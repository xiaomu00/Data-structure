#ifndef _QUEUE_H_
#define _QUEUE_H_

#define queue_size 5
#define Elemtype int


//////////////////////////////////////////////////////////////////////
//顺序队列

typedef  struct seqqueue
{
	Elemtype *base;
	size_t capcity;
	int front;
	int rear;
}seqqueue;

void seqqueueInit(seqqueue *psq);
bool seqqueueFull(seqqueue *psq);//判断是否溢出
bool seqqueueEomty(seqqueue *psq);//判断是否为空队
void seqqueueEnque(seqqueue *psq, Elemtype x);//入队
void seqqueueDeque(seqqueue *psq);//出队
Elemtype seqqueueTop(seqqueue *psq);//取队头元素
void seqqueueshow(seqqueue *psq);//显示
void queueExpansion(seqqueue *psq);//扩容

void seqqueueInit(seqqueue *psq)
{
	psq->base = (Elemtype*)malloc(sizeof(Elemtype)*queue_size);
	assert(psq->base!=NULL);
	psq->capcity = queue_size;
	psq->front = psq->rear = 0;
}
//判断是否溢出
bool seqqueueFull(seqqueue *psq)
{  
	assert(psq!=NULL);
	return (size_t)psq->rear >= psq->capcity;
}

//判断是否为空队
bool seqqueueEomty(seqqueue *psq)
{ 
	assert(psq != NULL);
	return psq->front == psq->rear; 
}

//入队
void seqqueueEnque(seqqueue *psq,Elemtype x)
{
	assert(psq != NULL);
	if (seqqueueFull(psq))
	{
		printf("队列已满，%d不能入队！\n",x);
		return;
	}
	psq->base[psq->rear] = x;
	psq->rear++;
	
}

//出队
void seqqueueDeque(seqqueue *psq)
{
	int i = 0;
	assert(psq != NULL);
	if (seqqueueEomty(psq))
	{
		printf("队列已空，不能出队！\n");
		return;
	}
	printf("%2d出队！ ",psq->base[0]);
	for (i = 0; i < psq->rear; i++)
	{
		psq->base[i] = psq->base[i+1];
	}
	psq->rear--;
	seqqueueshow(psq);
}

//取队头元素
Elemtype seqqueueTop(seqqueue *psq)
{
	assert(psq != NULL);
	if (seqqueueEomty(psq))
	{
		return -1;
	}
	return psq->base[0];
}


//显示
void seqqueueshow(seqqueue *psq)
{
	assert(psq != NULL);
	if (seqqueueEomty(psq))
	{
		printf("队列已空！\n");
	}
	else
	{
		printf("队列为： ");
		for (int i = 0; i <psq->rear; i++)
		{
			printf("%2d  ",psq->base[i]);
		}
		printf("\n");
	}
	
}

//扩容
void queueExpansion(seqqueue *psq)
{
	int x;
	printf("当前容量为：%2d  ,请输入要扩充的容量：\n", psq->capcity);
	scanf("%d", &x);
	psq->capcity = psq->capcity + x;
	printf("扩容成功，当前容量为：%2d \n", psq->capcity);
}


//////////////////////////////////////////////////////////////////////
//链式队列
//////////////////////////////////////////////////////////////////////
//顺序队列

typedef  struct linkqueuenode
{
	Elemtype base;
	struct linkqueuenode *next;
}linkqueuenode;

typedef  struct linkqueue
{
	linkqueuenode *qfront;
	linkqueuenode *qrear;
}linkqueue;



void linkqueueInit(linkqueue *psq);
void linkqueueEnque(linkqueue *psq, Elemtype x);//入队
void linkqueueDeque(linkqueue *psq);//出队
Elemtype linkqueueTop(linkqueue *psq);//取队头元素
void linkqueueshow(linkqueue *psq);//显示
struct linkqueuenode* open_qnode(Elemtype x);
void linkqueueInit(linkqueue *psq)
{
	assert(psq!=NULL);
	psq->qfront = psq->qrear = (linkqueuenode*)malloc(sizeof(linkqueuenode));
	psq->qfront->next = psq->qrear;
	psq->qrear->next = NULL;
}
struct linkqueuenode* open_qnode(Elemtype x)
{
	linkqueuenode *s = (linkqueuenode*)malloc(sizeof(linkqueuenode));
	assert(s != NULL);
	s->base = x;
	s->next = NULL;
	return s;
}

//入队
void linkqueueEnque(linkqueue *psq, Elemtype x)
{
	assert(psq != NULL);
	linkqueuenode *s = open_qnode(x);
	psq->qrear->next = s;
	psq->qrear = s;
}
//
//出队
void linkqueueDeque(linkqueue *psq)
{
	int i = 0;
	assert(psq != NULL);
	if (psq->qfront->next==NULL)
	{
		printf("队列已空，不能出队！\n");
		return;
	}
	linkqueuenode *p = (linkqueuenode*)malloc(sizeof(linkqueuenode));
	p = psq->qfront->next;
	printf("%2d出队！ ", p->base);
	psq->qfront->next = p->next;
	free(p);
	linkqueueshow(psq);
}
//
//取队头元素
Elemtype linkqueueTop(linkqueue *psq)
{
	assert(psq != NULL);
	if (psq->qfront == psq->qrear)
	{
		return -1;
	}
	return psq->qfront->next->base;
}


//显示
void linkqueueshow(linkqueue *psq)
{
	assert(psq != NULL);
	if (psq->qfront==psq->qrear)
	{
		printf("队列已空！\n");
	}
	else
	{
		linkqueuenode *p = (linkqueuenode*)malloc(sizeof(linkqueuenode));
		p = psq->qfront->next;
		printf("队列元素为： ");
		while (p!= NULL)
		{
			printf("%2d  ", p->base);
			p = p->next;
		}
		printf("\n");
	}

}








#endif /*_QUEUE_H_*/