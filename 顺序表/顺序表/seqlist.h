#ifndef _SEQLIST_H_
#define _SEQLIST_H_
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define ElmeType int
#define  SeqLlis_Size  10  //Ĭ�ϴ�С�ռ�


//���嶯̬˳���ṹ
typedef struct SeqList
{
	ElmeType *base;//�� int *base  ָ��
	size_t capacity;//����
	size_t size;//��ЧԪ�صĸ���
}SeqList;




//���������ӿ�

void SeqListInit(SeqList *pst);//˳����ʼ����������
bool IsFull(SeqList *pst);//�ж�˳����Ƿ�������Ƿ���1
bool IsEmpty(SeqList *pst); //�ж�˳����Ƿ�Ϊ�գ��Ƿ���1
void SeqListPushBack(SeqList *pst, ElmeType x);//β������
void SeqListPushFront(SeqList *pst, ElmeType x);//ͷ������
void SeqListInserByPos(SeqList *pst, int ps, ElmeType x);//��λ�ò���
void SeqListInserByVal(SeqList *pst,ElmeType x);//��ֵ����
void SeqListPopBack(SeqList *pst);//β��ɾ��
void SeqListPopFront(SeqList *pst);//ͷ��ɾ��
void SeqListPopByPos(SeqList *pst, int ps);//��λ��ɾ��
void SeqListPopByByVal(SeqList *pst, ElmeType x);//��ֵɾ��
void SeqListFind(SeqList *pst, ElmeType x);//����
void  SeqListSort(SeqList *pst);//����
int SeqListlength(SeqList *pst);//���
void SeqListclear(SeqList *pst);//���

void SeqListShow(SeqList *pst);//��ʾ




//�����ӿ�ʵ��

//˳����ʼ����������
void SeqListInit(SeqList *pst)
{
	assert(pst != NULL);
	pst->base = (ElmeType *)malloc(sizeof(ElmeType)*SeqLlis_Size);
	assert(pst->base != NULL);
	memset(pst->base, 0, sizeof(ElmeType)*SeqLlis_Size);
	pst->capacity = SeqLlis_Size;
	pst->size = 0;
}

//�ж�˳����Ƿ�������Ƿ���1
bool IsFull(SeqList *pst)
{
	return pst->size >= pst->capacity;
}

//�ж�˳����Ƿ�Ϊ�գ��Ƿ���1
bool IsEmpty(SeqList *pst)
{
	return pst->size == 0;
}

//��ʾ
void SeqListShow(SeqList *pst)
{
	assert(pst!=NULL);
	printf("��������Ϊ��");
	for (size_t i = 0; i < pst->size; i++)
	{
		printf("%2d  ", pst->base[i]);
	}
	printf("\n");
}

//β������
void SeqListPushBack(SeqList *pst, ElmeType x)
{
	assert(pst != NULL);
	if (IsFull(pst))
	{
		printf("˳���ռ����������ܲ���%d\n", x);
		return;
	}
	pst->base[pst->size] = x;
	pst->size++;
}

//ͷ������
void SeqListPushFront(SeqList *pst, ElmeType x)
{
	assert(pst != NULL);
	if (IsFull(pst))
	{
		printf("˳���ռ����������ܲ���%d\n", x);
		return;
	}
	for (ElmeType i = pst->size; i > 0; i--)
	{
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[0] = x;
	pst->size++;
}
//��λ�ò���
void SeqListInserByPos(SeqList *pst, int ps, ElmeType x)
{
	assert(pst!=NULL);
	if (ps<0||ps>(int)pst->size)
	{
		printf("�������λ����Ч,���ܲ��룡\n");
		return;
	}
	
	for (int i = pst->size; i > ps; i--)
	{
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[ps] = x;
	pst->size++;
	printf("����ɹ���\n");
}
//��ֵ����
void SeqListInserByVal(SeqList *pst, ElmeType x)
{
	assert(pst!=NULL);
	if (IsFull(pst))
	{
		printf("���ݱ�����,���ܲ��룡\n");
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

//β��ɾ��
void SeqListPopBack(SeqList *pst)
{
	assert(pst != NULL);
	ElmeType num;
	do
	{
		printf("������Ҫɾ���ĸ���:>");
		scanf("%d", &num);
		if ((size_t)num > pst->size)
		{
			printf("��Ҫɾ������������˳�����Ч�ռ䣬���������룺>");
		}
	} while ((size_t)num > pst->size);

	for (ElmeType i = 1; i <= num; i++)
	{
		pst->base[pst->size - 1] = 0;
		pst->size--;
	}
	printf("ɾ���ɹ���\n");
}

//ͷ��ɾ��
void SeqListPopFront(SeqList *pst)
{
	assert(pst != NULL);
	ElmeType num;
	do
	{
		printf("������Ҫɾ���ĸ���:>");
		scanf("%d", &num);
		if ((size_t)num > pst->size)
		{
			printf("��Ҫɾ������������˳�����Ч�ռ䣬���������룺>");
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
	printf("ɾ���ɹ���\n");
}

//��λ��ɾ��
void SeqListPopByPos(SeqList *pst, int ps)
{
	assert(pst != NULL);
	
	if (ps>=(int)pst->size)
	{
		printf("�������λ����Ч,����ɾ����\n");
		return;
	}
	
	for (int i = ps; i < (int)pst->size - 1;i++)
	{
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
	printf("ɾ���ɹ���\n");
}

//��ֵɾ��
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
		printf("��Ҫɾ����ֵ�����ڣ�\n");
	else
		SeqListPopByPos(pst, ps);

}

//����
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
		printf("��Ҫ���ҵ�ֵ�����ڣ�\n");
	else
	printf("��Ҫ���ҵ�ֵ�±���%d��\n",i);
}

//����
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
	printf("����ɹ���\n");
}

//���
int SeqListlength(SeqList *pst)
{
	assert(pst!=NULL);
	return pst->size;
}
//���
void SeqListclear(SeqList *pst)
{
	assert(pst!=NULL);
	pst->size = 0;
}















#endif /*_SEQLIST_H_*/