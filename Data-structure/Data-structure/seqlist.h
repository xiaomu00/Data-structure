#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include"public.h"

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
void SeqListShow(SeqList *pst);//��ʾ
void SeqListPushBack(SeqList *pst,ElmeType x);//β������
void SeqListPushFront(SeqList *pst, ElmeType x);//ͷ������







//�����ӿ�ʵ��

//˳����ʼ����������
void SeqListInit(SeqList *pst)
{
	assert(pst != NULL);
	pst->base = (ElmeType *)malloc(sizeof(ElmeType)*SeqLlis_Size);
	assert(pst->base!=NULL);
	memset(pst->base, 0, sizeof(ElmeType)*SeqLlis_Size);
	pst->capacity = SeqLlis_Size;
	pst->size = 0;
}

//�ж�˳����Ƿ�������Ƿ���1
bool IsFull(SeqList *pst)
{  return pst->size >= pst->capacity;  }

//�ж�˳����Ƿ�Ϊ�գ��Ƿ���1
bool IsEmpty(SeqList *pst)
{  return pst->size ==0;  }

//��ʾ
void SeqListShow(SeqList *pst)
{
	assert(pst != NULL);
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
		printf("˳���ռ����������ܲ���%d\n",x);
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
		pst->base[i] = pst->base[i-1];
	}
	pst->base[0] = x;
	pst->size++;
}





























#endif /*_SEQLIST_H_*/