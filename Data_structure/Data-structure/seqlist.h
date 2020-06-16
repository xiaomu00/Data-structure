#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include"public.h"


//定义链表节点
typedef struct ListNode
{
	ElemType data;
	struct ListNode *next;
}ListNode;
typedef ListNode* List;


void ListCreate_Tail(List *plist);//尾插法创建单链表
void ListCreate_Head(List *plist);//头插法创建单链表
void Listshow(List plist);//显示单链表

//
////不带头节点
////初始化
//void List_Init(List *plist)//相当于ListNode **plist
//{*plist = NULL;}
////尾插法创建单链表
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
////头插法创建单链表
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
////显示单链表
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


//带头节点
//初始化
void List_Init(List *plist)//相当于ListNode **plist
{
	*plist = (ListNode *)malloc(sizeof(ListNode));
	assert(*plist != NULL);
	(*plist)->next = NULL;
}
void ListCreate_Tail(List *plist);//尾插法创建单链表
void ListCreate_Head(List *plist);//头插法创建单链表
void Listshow(List plist);//显示单链表


//尾插法创建单链表
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
//头插法创建单链表
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

//显示单链表
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
//单链表的函数接口声明
static BuyNode(ElemType x);//开辟一个节点空间并赋值
void listInit(slist *pst);//单链表序表初始化函数声明
void slistPushBackPushBack(slist *plist, ElemType x);//尾部插入
void slistPushFront(slist *plist, ElemType x);//头部插入
void slistPopBack(slist *plist);//尾部删除
void slistPopFront(slist *plist);//头部删除
int slistlength(slist *plist);//求表长
void slistDestroy(slist *plist);//摧毁
void slistShow(slist *plist);//显示




////////////////////////////////////////////////////////////////////
//单链表的函数接口实现

//开辟一个节点空间并赋值
static SListNode* _BuyNode(ElemType x)
{
	SListNode *s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	return s;
}
//单链表初始化函数声明
void listInit(slist *plist)
{
	plist->head = NULL;
}
//尾部插入 时间复杂度为O（n）
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

//头部插入  时间复杂度为O（1）
void slistPushFront(slist *plist, ElemType x)
{
	assert(plist != NULL);
	SListNode *s = _BuyNode(x);
	s->next = plist->head;
	plist->head = s;
}


//尾部删除  
void slistPopBack(slist *plist)
{
	assert(plist != NULL);
	if (plist->head == NULL)
	{
		printf("链表已空！\n");
		return;
	}
	SListNode *p = plist->head;
	if (p->next == NULL)//说明只有一个节点
	{
		free(p);
		plist->head = NULL;
		printf("删除成功!\n");
		return;
	}
	else
	while (p->next->next != NULL)
	{
		p = p->next;
	}
	free(p->next);
	p->next = NULL;
	printf("删除成功!\n");
}

//头部删除   
void slistPopFront(slist *plist)
{
	assert(plist != NULL);
	if (plist->head == NULL)
	{
		printf("链表已空！\n");
		return;
	}
	SListNode *p = plist->head;
	plist->head = p->next;
	free(p);
	printf("删除成功!\n");
}

//求表长
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


//摧毁
void slistDestroy(slist *plist)
{
	if (plist->head == NULL)
	{
		printf("链表已空！\n");
		return;
	}
	while (plist->head != NULL)
	{
		SListNode *p = plist->head;
		plist->head = p->next;
		free(p);
	}
	printf("摧毁成功！\n");
}

//显示
void slistShow(slist *plist)
{
	if (plist->head == NULL)
	{
		printf("链表已空！\n");
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