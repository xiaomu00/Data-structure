#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include"public.h"


//��������ڵ�
typedef struct ListNode
{
	ElemType data;
	struct ListNode *next;
}ListNode;
typedef ListNode* List;


void ListCreate_Tail(List *plist);//β�巨����������
void ListCreate_Head(List *plist);//ͷ�巨����������
void Listshow(List plist);//��ʾ������

//
////����ͷ�ڵ�
////��ʼ��
//void List_Init(List *plist)//�൱��ListNode **plist
//{*plist = NULL;}
////β�巨����������
//void ListCreate_Tail(List *plist)
//{
//	*plist = (ListNode *)malloc(sizeof(ListNode));
//	assert(*plist!=NULL);
//	(*plist)->data = 1;
//	(*plist)->next = NULL;
//	ListNode *p = *plist;
//	for (int i = 2; i <= 10; i++)
//	{
//		ListNode *s = (ListNode *)malloc(sizeof(ListNode));
//		assert(s!= NULL);
//		s->data = i;
//		s->next = NULL;
//		p->next = s;
//		p = s;
//	}
//}
////ͷ�巨����������
//void ListCreate_Head(List *plist)
//{
//	*plist = (ListNode *)malloc(sizeof(ListNode));
//	assert(*plist != NULL);
//	(*plist)->data = 1;
//	(*plist)->next = NULL;
//	for (int i = 2; i <= 10; i++)
//	{
//		ListNode *s = (ListNode *)malloc(sizeof(ListNode));
//		assert(s != NULL);
//		s->data =i;
//		s->next = (*plist);
//		(*plist) = s;
//	}
//}
////��ʾ������
//void  Listshow(List plist)
//{
//	ListNode *p = plist;
//	while (p!= NULL)
//	{
//		printf("%d->",p->data);
//		p = p->next;
//	}
//	printf("Over\n");
//}


//��ͷ�ڵ�
//��ʼ��
void List_Init(List *plist)//�൱��ListNode **plist
{
	*plist = (ListNode *)malloc(sizeof(ListNode));
	assert(*plist != NULL);
	(*plist)->next = NULL;
}
void ListCreate_Tail(List *plist);//β�巨����������
void ListCreate_Head(List *plist);//ͷ�巨����������
void Listshow(List plist);//��ʾ������


//β�巨����������
void ListCreate_Tail(List *plist)
{
	ListNode *p = *plist;
	for (int i = 1; i <= 10; i++)
	{
		ListNode *s = (ListNode *)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;
		p->next = s;
		p = s;
	}
}
//ͷ�巨����������
void ListCreate_Head(List *plist)
{
	for (int i = 1; i <= 10; i++)
	{
		ListNode *s = (ListNode *)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;

		s->next = (*plist)->next;
		(*plist)->next = s;
	}
}

//��ʾ������
void  Listshow(List plist)
{
	ListNode *p = plist;
	p = p->next;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over\n");
}



typedef struct SListNode
{
	ElemType data;
	struct SListNode *next;
}SListNode;
typedef struct slist
{
	SListNode *head;
}slist;

////////////////////////////////////////////////////////////////////
//������ĺ����ӿ�����
static BuyNode(ElemType x);//����һ���ڵ�ռ䲢��ֵ
void listInit(slist *pst);//����������ʼ����������
void slistPushBackPushBack(slist *plist, ElemType x);//β������
void slistPushFront(slist *plist, ElemType x);//ͷ������
void slistPopBack(slist *plist);//β��ɾ��
void slistPopFront(slist *plist);//ͷ��ɾ��
int slistlength(slist *plist);//���
void slistDestroy(slist *plist);//�ݻ�
void slistShow(slist *plist);//��ʾ




////////////////////////////////////////////////////////////////////
//������ĺ����ӿ�ʵ��

//����һ���ڵ�ռ䲢��ֵ
static SListNode* _BuyNode(ElemType x)
{
	SListNode *s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	return s;
}
//�������ʼ����������
void listInit(slist *plist)
{
	plist->head = NULL;
}
//β������ ʱ�临�Ӷ�ΪO��n��
void slistPushBackPushBack(slist *plist, ElemType x)
{
	assert(plist != NULL);
	SListNode *s = _BuyNode(x);
	if (plist->head == NULL)
	{
		plist->head = s;
		return;
	}
	SListNode *p = plist->head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = s;
}

//ͷ������  ʱ�临�Ӷ�ΪO��1��
void slistPushFront(slist *plist, ElemType x)
{
	assert(plist != NULL);
	SListNode *s = _BuyNode(x);
	s->next = plist->head;
	plist->head = s;
}


//β��ɾ��  
void slistPopBack(slist *plist)
{
	assert(plist != NULL);
	if (plist->head == NULL)
	{
		printf("�����ѿգ�\n");
		return;
	}
	SListNode *p = plist->head;
	if (p->next == NULL)//˵��ֻ��һ���ڵ�
	{
		free(p);
		plist->head = NULL;
		printf("ɾ���ɹ�!\n");
		return;
	}
	else
	while (p->next->next != NULL)
	{
		p = p->next;
	}
	free(p->next);
	p->next = NULL;
	printf("ɾ���ɹ�!\n");
}

//ͷ��ɾ��   
void slistPopFront(slist *plist)
{
	assert(plist != NULL);
	if (plist->head == NULL)
	{
		printf("�����ѿգ�\n");
		return;
	}
	SListNode *p = plist->head;
	plist->head = p->next;
	free(p);
	printf("ɾ���ɹ�!\n");
}

//���
int slistlength(slist *plist)
{

	SListNode *p;
	assert(plist != NULL);
	if (plist->head == NULL)
		return 0;
	p = plist->head;
	int len = 0;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}


//�ݻ�
void slistDestroy(slist *plist)
{
	if (plist->head == NULL)
	{
		printf("�����ѿգ�\n");
		return;
	}
	while (plist->head != NULL)
	{
		SListNode *p = plist->head;
		plist->head = p->next;
		free(p);
	}
	printf("�ݻٳɹ���\n");
}

//��ʾ
void slistShow(slist *plist)
{
	if (plist->head == NULL)
	{
		printf("�����ѿգ�\n");
		return;
	}
	SListNode *p = plist->head;
	while (p != NULL)
	{
		printf("%d -> ", p->data);
		p = p->next;
	}
	printf("Over\n");
}



#endif /*_SEQLIST_H_*/