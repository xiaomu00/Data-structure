#ifndef _STACK_H_
#define _STACK_H_
#include<stdio.h>

#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>

#define stack_size 3
#define Elemtype int

//////////////////////////////////////////////////////////////////////
//˳��ջ

typedef  struct stack
{
	Elemtype *base;
	size_t capcity;
	int top;
}seqstack;



void seqstackInit(seqstack *pst);
bool seqstackFull(seqstack *pst);//�ж��Ƿ����
bool seqstackEomty(seqstack *pst);//�ж��Ƿ�Ϊ��ջ
Elemtype seqstackTop(seqstack *pst);//ȡջ��Ԫ��
void seqstackPush(seqstack *pst, Elemtype x);//��ջ
void seqstackPop(seqstack *pst);//��ջ
void seqstackshow(seqstack *pst);//��ʾ
void Expansion(seqstack *pst);//����
















bool seqstackFull(seqstack *pst)
{
	assert(pst != NULL); return   pst->top == pst->capcity;
}

bool seqstackEomty(seqstack *pst)
{
	assert(pst != NULL);  return  pst->top == 0;
}

void seqstackInit(seqstack *pst)
{
	pst->base = (Elemtype*)malloc(sizeof(Elemtype)*stack_size);
	assert(pst->base != NULL);
	pst->capcity = stack_size;
	pst->top = 0;
}

Elemtype seqstackTop(seqstack *pst)
{
	assert(pst != NULL);
	return pst->base[pst->top-1];
}

void seqstackPush(seqstack *pst, Elemtype x)
{
	assert(pst!=NULL);
	if (seqstackFull(pst))
	{
		printf("�ռ�������%d������ջ��\n",x);
		return;
	}
	pst->base[pst->top++] = x;
}

void seqstackPop(seqstack *pst)
{
	assert(pst!= NULL);
	if (seqstackEomty(pst))
	{
		printf("ջ�ѿգ����ܳ�ջ��\n");
	}
	Elemtype pt = seqstackTop(pst);
	printf("%2d  ��ջ��\n",pt);
	pst->top--;
	seqstackshow(pst);
}



//����
void Expansion(seqstack *pst)
{
	int x;
	printf("��ǰ����Ϊ��%2d  ,������Ҫ�����������\n",pst->capcity);
	scanf("%d",&x);
	pst->capcity = pst->capcity + x;
	printf("���ݳɹ�����ǰ����Ϊ��%2d \n", pst->capcity);
}

void seqstackshow(seqstack *pst)
{	
	assert(pst != NULL);
	if (seqstackEomty(pst))
	{
		printf("��ջ��\n");
	}
	int i=pst->top-1;
	while (i>=0)
	{
		printf("%2d  ",pst->base[i]);
		printf("\n");
		i--;
	}

}

#endif /*_STACK_H_*/