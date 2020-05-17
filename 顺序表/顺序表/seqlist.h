#ifndef _SEQLIST_H_
#define _SEQLIST_H_
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define ElmeType int
#define  SeqLlis_Size  10  //默认大小空间


//定义动态顺序表结构
typedef struct SeqList
{
	ElmeType *base;//即 int *base  指向
	size_t capacity;//容量
	size_t size;//有效元素的个数
}SeqList;




//声明函数接口

void SeqListInit(SeqList *pst);//顺序表初始化函数声明
bool IsFull(SeqList *pst);//判断顺序表是否溢出，是返回1
bool IsEmpty(SeqList *pst); //判断顺序表是否为空，是返回1
void SeqListPushBack(SeqList *pst, ElmeType x);//尾部插入
void SeqListPushFront(SeqList *pst, ElmeType x);//头部插入
void SeqListInserByPos(SeqList *pst, int ps, ElmeType x);//按位置插入
void SeqListInserByVal(SeqList *pst,ElmeType x);//按值插入
void SeqListPopBack(SeqList *pst);//尾部删除
void SeqListPopFront(SeqList *pst);//头部删除
void SeqListPopByPos(SeqList *pst, int ps);//按位置删除
void SeqListPopByByVal(SeqList *pst, ElmeType x);//按值删除
void SeqListFind(SeqList *pst, ElmeType x);//查找
void  SeqListSort(SeqList *pst);//排序
int SeqListlength(SeqList *pst);//求表长
void SeqListclear(SeqList *pst);//清除

void SeqListShow(SeqList *pst);//显示




//函数接口实现

//顺序表初始化函数定义
void SeqListInit(SeqList *pst)
{
	assert(pst != NULL);
	pst->base = (ElmeType *)malloc(sizeof(ElmeType)*SeqLlis_Size);
	assert(pst->base != NULL);
	memset(pst->base, 0, sizeof(ElmeType)*SeqLlis_Size);
	pst->capacity = SeqLlis_Size;
	pst->size = 0;
}

//判断顺序表是否溢出，是返回1
bool IsFull(SeqList *pst)
{
	return pst->size >= pst->capacity;
}

//判断顺序表是否为空，是返回1
bool IsEmpty(SeqList *pst)
{
	return pst->size == 0;
}

//显示
void SeqListShow(SeqList *pst)
{
	assert(pst!=NULL);
	printf("表中数据为：");
	for (size_t i = 0; i < pst->size; i++)
	{
		printf("%2d  ", pst->base[i]);
	}
	printf("\n");
}

//尾部插入
void SeqListPushBack(SeqList *pst, ElmeType x)
{
	assert(pst != NULL);
	if (IsFull(pst))
	{
		printf("顺序表空间已满，不能插入%d\n", x);
		return;
	}
	pst->base[pst->size] = x;
	pst->size++;
}

//头部插入
void SeqListPushFront(SeqList *pst, ElmeType x)
{
	assert(pst != NULL);
	if (IsFull(pst))
	{
		printf("顺序表空间已满，不能插入%d\n", x);
		return;
	}
	for (ElmeType i = pst->size; i > 0; i--)
	{
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[0] = x;
	pst->size++;
}
//按位置插入
void SeqListInserByPos(SeqList *pst, int ps, ElmeType x)
{
	assert(pst!=NULL);
	if (ps<0||ps>(int)pst->size)
	{
		printf("您输入的位置无效,不能插入！\n");
		return;
	}
	
	for (int i = pst->size; i > ps; i--)
	{
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[ps] = x;
	pst->size++;
	printf("插入成功！\n");
}
//按值插入
void SeqListInserByVal(SeqList *pst, ElmeType x)
{
	assert(pst!=NULL);
	if (IsFull(pst))
	{
		printf("数据表已满,不能插入！\n");
		return;
	}
	int ps,i;
	SeqListSort(pst);
	for (i = 0; i <(int)pst->size; i++)
	{
		if (x <= pst->base[i])
		{
			ps = i;
			break;
		}
	}
	if (i >= (int)pst->size)
		ps = pst->size;
	SeqListInserByPos(pst, ps, x);
}

//尾部删除
void SeqListPopBack(SeqList *pst)
{
	assert(pst != NULL);
	ElmeType num;
	do
	{
		printf("请输入要删除的个数:>");
		scanf("%d", &num);
		if ((size_t)num > pst->size)
		{
			printf("您要删除的数量大于顺序表有效空间，请重新输入：>");
		}
	} while ((size_t)num > pst->size);

	for (ElmeType i = 1; i <= num; i++)
	{
		pst->base[pst->size - 1] = 0;
		pst->size--;
	}
	printf("删除成功！\n");
}

//头部删除
void SeqListPopFront(SeqList *pst)
{
	assert(pst != NULL);
	ElmeType num;
	do
	{
		printf("请输入要删除的个数:>");
		scanf("%d", &num);
		if ((size_t)num > pst->size)
		{
			printf("您要删除的数量大于顺序表有效空间，请重新输入：>");
		}
	} while ((size_t)num > pst->size);

	for (ElmeType i = 1; i <= num; i++)
	{
		for (size_t j = 0; j < pst->size - 1; j++)
		{
			pst->base[j] = pst->base[j + 1];
		}
		pst->base[pst->size - 1] = 0;
		pst->size--;
	}
	printf("删除成功！\n");
}

//按位置删除
void SeqListPopByPos(SeqList *pst, int ps)
{
	assert(pst != NULL);
	
	if (ps>=(int)pst->size)
	{
		printf("您输入的位置无效,不能删除！\n");
		return;
	}
	
	for (int i = ps; i < (int)pst->size - 1;i++)
	{
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
	printf("删除成功！\n");
}

//按值删除
void SeqListPopByByVal(SeqList *pst, ElmeType x)
{
	assert(pst != NULL);
	int i, ps;
	for (i = 0; i <(int)pst->size; i++)
	{
		if (pst->base[i] == x)
		{
			ps = i;
			break;
		}
	}
	if (i >= (int)pst->size)
		printf("您要删除的值不存在！\n");
	else
		SeqListPopByPos(pst, ps);

}

//查找
void SeqListFind(SeqList *pst, ElmeType x)
{
	assert(pst != NULL);
	int i,ps;
	for (i = 0; i <(int)pst->size; i++)
	{
		if (pst->base[i] == x)
		{
			ps = i;
			break;
		}	
	}
	if (i >= (int)pst->size)
		printf("您要查找的值不存在！\n");
	else
	printf("您要查找的值下标是%d！\n",i);
}

//排序
void  SeqListSort(SeqList *pst)
{
	assert(pst!=NULL);
	if (pst->size < 2)
		return;
	for (int i = 0; i < (int)pst->size - 1; i++)
	{
		for (int j = 0; j < (int)pst->size - 1 - i; j++)
		{
			if (pst->base[j]>pst->base[j + 1])
			{
				ElmeType a = pst->base[j];
				pst->base[j] = pst->base[j + 1];
				pst->base[j + 1] = a;
			}

		}
	}
	printf("排序成功！\n");
}

//求表长
int SeqListlength(SeqList *pst)
{
	assert(pst!=NULL);
	return pst->size;
}
//清除
void SeqListclear(SeqList *pst)
{
	assert(pst!=NULL);
	pst->size = 0;
}















#endif /*_SEQLIST_H_*/