#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include"public.h"

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
void SeqListShow(SeqList *pst);//显示
void SeqListPushBack(SeqList *pst,ElmeType x);//尾部插入
void SeqListPushFront(SeqList *pst, ElmeType x);//头部插入







//函数接口实现

//顺序表初始化函数定义
void SeqListInit(SeqList *pst)
{
	assert(pst != NULL);
	pst->base = (ElmeType *)malloc(sizeof(ElmeType)*SeqLlis_Size);
	assert(pst->base!=NULL);
	memset(pst->base, 0, sizeof(ElmeType)*SeqLlis_Size);
	pst->capacity = SeqLlis_Size;
	pst->size = 0;
}

//判断顺序表是否溢出，是返回1
bool IsFull(SeqList *pst)
{  return pst->size >= pst->capacity;  }

//判断顺序表是否为空，是返回1
bool IsEmpty(SeqList *pst)
{  return pst->size ==0;  }

//显示
void SeqListShow(SeqList *pst)
{
	assert(pst != NULL);
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
		printf("顺序表空间已满，不能插入%d\n",x);
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
		pst->base[i] = pst->base[i-1];
	}
	pst->base[0] = x;
	pst->size++;
}





























#endif /*_SEQLIST_H_*/