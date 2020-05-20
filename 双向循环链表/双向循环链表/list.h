#ifndef _LISE_H_
#define _LIST_H_

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define ElmeType int



//定义链表节点
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
////单链表的函数接口声明
static DCListNode* BuyDCNode(ElmeType x);//开辟一个节点空间并赋值
void DCListInit(DCList *pst);//单链表序表初始化函数声明
void DCListPushBack(DCList *plist, ElmeType x);//尾部插入
void DCListPushFront(DCList *plist, ElmeType x);//头部插入
void DCListPopBack(DCList *plist);//尾部删除
void DCListPopFrontt(DCList *plist);//头部删除
int DCListlength(DCList *plist);//求表长
void DCListDestroy(DCList *plist);//摧毁
void DCListShow(DCList *plist);//显示
//

//
////////////////////////////////////////////////////////////////////////
//单链表的函数接口实现

//开辟一个节点空间并赋值
static DCListNode* BuyDCNode(ElmeType x)
{
	DCListNode *s = (DCListNode*)malloc(sizeof(DCListNode));
	assert(s != NULL);
	s->data = x;
	s->next = s->prev = s;
	return s;
}

//单链表初始化函数声明
void DCListInit(DCList *plist)
{
	plist->head = BuyDCNode(0); 
}

//尾部插入 
void DCListPushBack(DCList *plist, ElmeType x)
{
	DCListNode *s = BuyDCNode(x);
	s->prev = plist->head->prev;
	s->prev->next = s;
	s->next = plist->head;
	s->next->prev = s;
}

//头部插入  
void DCListPushFront(DCList *plist, ElmeType x)
{

	DCListNode *s = BuyDCNode(x);
	s->next = plist->head->next;
	s->next->prev = s;
	s->prev = plist->head;
	plist->head->next = s;
}


//尾部删除  
void DCListPopBack(DCList *plist)
{
	if (plist->head->next == plist->head)
	{
		printf("只有头结点，不能删除\n");
		return;
	}
	DCListNode *p = plist->head->prev;
	p->prev->next = plist->head;
	plist->head->prev = p->prev;
	free(p);
	printf("删除成功!\n");
}

//头部删除   
void DCListPopFront(DCList *plist)
{
	if (plist->head->next == plist->head)
	{
		printf("只有头结点，不能删除\n");
		return;
	}
	DCListNode *p = plist->head->next;
	plist->head->next = p->next;
	p->next->prev = plist->head;
	free(p);
	printf("删除成功!\n");
}

//求表长
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


//摧毁
void DCListDestroy(DCList *plist)
{
	while (plist->head->next != plist->head)
	{
		DCListNode *p = plist->head->next;
		plist->head->next = p->next;
		p->next->prev = plist->head;
		free(p);
	}
	printf("摧毁成功！\n");
}

//显示
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