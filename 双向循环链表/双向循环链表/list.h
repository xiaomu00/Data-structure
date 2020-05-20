#ifndef _LISE_H_
#define _LIST_H_

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define ElmeType int



//��������ڵ�
typedef struct DCListNode
{
	ElmeType data;
	struct DCListNode *next;
	struct DCListNode *prev;
}DCListNode;


typedef struct DCList
{
	DCListNode *head;
}DCList;



////////////////////////////////////////////////////////////////////////
////������ĺ����ӿ�����
static DCListNode* BuyDCNode(ElmeType x);//����һ���ڵ�ռ䲢��ֵ
void DCListInit(DCList *pst);//����������ʼ����������
void DCListPushBack(DCList *plist, ElmeType x);//β������
void DCListPushFront(DCList *plist, ElmeType x);//ͷ������
void DCListPopBack(DCList *plist);//β��ɾ��
void DCListPopFrontt(DCList *plist);//ͷ��ɾ��
int DCListlength(DCList *plist);//���
void DCListDestroy(DCList *plist);//�ݻ�
void DCListShow(DCList *plist);//��ʾ
//

//
////////////////////////////////////////////////////////////////////////
//������ĺ����ӿ�ʵ��

//����һ���ڵ�ռ䲢��ֵ
static DCListNode* BuyDCNode(ElmeType x)
{
	DCListNode *s = (DCListNode*)malloc(sizeof(DCListNode));
	assert(s != NULL);
	s->data = x;
	s->next = s->prev = s;
	return s;
}

//�������ʼ����������
void DCListInit(DCList *plist)
{
	plist->head = BuyDCNode(0); 
}

//β������ 
void DCListPushBack(DCList *plist, ElmeType x)
{
	DCListNode *s = BuyDCNode(x);
	s->prev = plist->head->prev;
	s->prev->next = s;
	s->next = plist->head;
	s->next->prev = s;
}

//ͷ������  
void DCListPushFront(DCList *plist, ElmeType x)
{

	DCListNode *s = BuyDCNode(x);
	s->next = plist->head->next;
	s->next->prev = s;
	s->prev = plist->head;
	plist->head->next = s;
}


//β��ɾ��  
void DCListPopBack(DCList *plist)
{
	if (plist->head->next == plist->head)
	{
		printf("ֻ��ͷ��㣬����ɾ��\n");
		return;
	}
	DCListNode *p = plist->head->prev;
	p->prev->next = plist->head;
	plist->head->prev = p->prev;
	free(p);
	printf("ɾ���ɹ�!\n");
}

//ͷ��ɾ��   
void DCListPopFront(DCList *plist)
{
	if (plist->head->next == plist->head)
	{
		printf("ֻ��ͷ��㣬����ɾ��\n");
		return;
	}
	DCListNode *p = plist->head->next;
	plist->head->next = p->next;
	p->next->prev = plist->head;
	free(p);
	printf("ɾ���ɹ�!\n");
}

//���
int DCListlength(DCList *plist)
{

	if (plist->head->next == plist->head)
	{
		return 0;
	}
	DCListNode *p = plist->head->next;
	int len = 0;
	while (p != plist->head)
	{
		len++;
		p = p->next;
	}

	return len;
}


//�ݻ�
void DCListDestroy(DCList *plist)
{
	while (plist->head->next != plist->head)
	{
		DCListNode *p = plist->head->next;
		plist->head->next = p->next;
		p->next->prev = plist->head;
		free(p);
	}
	printf("�ݻٳɹ���\n");
}

//��ʾ
void DCListShow(DCList *plist)
{
	if (plist->head->next == plist->head)
	{
		printf("head<=>head\n");
		return;
	}
	DCListNode *p = plist->head->next;
	printf("head<=> ", p->data);
	while (p != plist->head)
	{
		printf("%d <=> ", p->data);
		p = p->next;
	}
	printf("head\n");
}

#endif /*_LISE_H_*/