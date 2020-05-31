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




//////////////////////////////////////////////////////////////////////
//��ջ

typedef  struct linkstacknode
{
	Elemtype date;
	struct linkstacknode *next;
}linkstacknode;


typedef struct linkstack
{
	linkstacknode *top;
}linkstack;


void linkstackInit(linkstack *pst);
struct linkstacknode* open_node(Elemtype x);
bool linkstackEomty(linkstack *pst);//�ж��Ƿ�Ϊ��ջ
Elemtype linkstackTop(linkstack *pst);//ȡջ��Ԫ��
void linkstackPush(linkstack *pst, Elemtype x);//��ջ
void linkstackPop(linkstack *pst);//��ջ
void linkstackshow(linkstack *pst);//��ʾ

void linkstackInit(linkstack *ps)
{
	ps->top = (linkstacknode*)malloc(sizeof(linkstacknode));
	ps->top->date = 0;
	ps->top->next=NULL;
}

struct linkstacknode* open_node(Elemtype x)
{
	linkstacknode *s = (linkstacknode*)malloc(sizeof(linkstacknode));
	assert(s!=NULL);
	s->date = x;
	s->next = NULL;
	return s;
}

//��ջ
void linkstackPush(linkstack *pst, Elemtype x)
{
	assert(pst!=NULL);
	linkstacknode *s = open_node(x);
	s->next = pst->top->next;
	pst->top->next = s;
    
}
//ȡջ��Ԫ��
Elemtype linkstackTop(linkstack *pst)
{
	assert(pst != NULL);
	if (pst->top->next == NULL)
	{
		return  -1;
	}
	return pst->top->next->date;
}
//��ջ
void linkstackPop(linkstack *pst)
{
	assert(pst != NULL);
	if (pst->top->next == NULL)
	{
		printf("ջ�ѿգ�\n");
		return;
	}
	printf("%2d  ��ջ��\n", linkstackTop(pst));
	linkstacknode *p = pst->top;
	pst->top = p->next;
	free(p);
	linkstackshow(pst);
}



//��ʾ
void linkstackshow(linkstack *pst)
{
	assert(pst != NULL);
	if (pst->top->next == NULL)
	{
		printf("��ջ��\n");
		return;
	}
	linkstacknode *p=(linkstacknode*)malloc(sizeof(linkstacknode));
	p= pst->top->next;
	while (p != NULL)
	{
		
		printf("%2d\n",p->date);
		p = p->next;
	}
}


#endif /*_STACK_H_*/