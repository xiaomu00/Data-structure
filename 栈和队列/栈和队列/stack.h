#ifndef _STACK_H_
#define _STACK_H_
#include<stdio.h>

#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>

#define stack_size 3
#define Elemtype int

//////////////////////////////////////////////////////////////////////
//顺序栈

typedef  struct stack
{
	Elemtype *base;
	size_t capcity;
	int top;
}seqstack;


void seqstackInit(seqstack *pst);
bool seqstackFull(seqstack *pst);//判断是否溢出
bool seqstackEomty(seqstack *pst);//判断是否为空栈
Elemtype seqstackTop(seqstack *pst);//取栈顶元素
void seqstackPush(seqstack *pst, Elemtype x);//入栈
void seqstackPop(seqstack *pst);//出栈
void seqstackshow(seqstack *pst);//显示
void Expansion(seqstack *pst);//扩容

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
		printf("空间已满，%d不能入栈！\n",x);
		return;
	}
	pst->base[pst->top++] = x;
}

void seqstackPop(seqstack *pst)
{
	assert(pst!= NULL);
	if (seqstackEomty(pst))
	{
		printf("栈已空，不能出栈！\n");
	}
	Elemtype pt = seqstackTop(pst);
	printf("%2d  出栈！\n",pt);
	pst->top--;
	seqstackshow(pst);
}

//扩容
void Expansion(seqstack *pst)
{
	int x;
	printf("当前容量为：%2d  ,请输入要扩充的容量：\n",pst->capcity);
	scanf("%d",&x);
	pst->capcity = pst->capcity + x;
	printf("扩容成功，当前容量为：%2d \n", pst->capcity);
}
void seqstackshow(seqstack *pst)
{	
	assert(pst != NULL);
	if (seqstackEomty(pst))
	{
		printf("空栈！\n");
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
//链栈

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
bool linkstackEomty(linkstack *pst);//判断是否为空栈
Elemtype linkstackTop(linkstack *pst);//取栈顶元素
void linkstackPush(linkstack *pst, Elemtype x);//入栈
void linkstackPop(linkstack *pst);//出栈
void linkstackshow(linkstack *pst);//显示

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

//入栈
void linkstackPush(linkstack *pst, Elemtype x)
{
	assert(pst!=NULL);
	linkstacknode *s = open_node(x);
	s->next = pst->top->next;
	pst->top->next = s;
    
}
//取栈顶元素
Elemtype linkstackTop(linkstack *pst)
{
	assert(pst != NULL);
	if (pst->top->next == NULL)
	{
		return  -1;
	}
	return pst->top->next->date;
}
//出栈
void linkstackPop(linkstack *pst)
{
	assert(pst != NULL);
	if (pst->top->next == NULL)
	{
		printf("栈已空！\n");
		return;
	}
	printf("%2d  出栈！\n", linkstackTop(pst));
	linkstacknode *p = pst->top;
	pst->top = p->next;
	free(p);
	linkstackshow(pst);
}



//显示
void linkstackshow(linkstack *pst)
{
	assert(pst != NULL);
	if (pst->top->next == NULL)
	{
		printf("空栈！\n");
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