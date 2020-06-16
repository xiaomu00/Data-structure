#ifndef _QUEUE_H_
#define _QUEUE_H_


#include"public.h"
#define queue_size 5



//////////////////////////////////////////////////////////////////////
//˳�����

typedef  struct seqqueue
{
	ElemType *base;
	size_t capcity;
	int front;
	int rear;
}seqqueue;

void seqqueueInit(seqqueue *psq);
bool seqqueueFull(seqqueue *psq);//�ж��Ƿ����
bool seqqueueEomty(seqqueue *psq);//�ж��Ƿ�Ϊ�ն�
void seqqueueEnque(seqqueue *psq, ElemType x);//���
void seqqueueDeque(seqqueue *psq);//����
ElemType seqqueueTop(seqqueue *psq);//ȡ��ͷԪ��
void seqqueueshow(seqqueue *psq);//��ʾ
void queueExpansion(seqqueue *psq);//����

void seqqueueInit(seqqueue *psq)
{
	psq->base = (ElemType*)malloc(sizeof(ElemType)*queue_size);
	assert(psq->base != NULL);
	psq->capcity = queue_size;
	psq->front = psq->rear = 0;
}
//�ж��Ƿ����
bool seqqueueFull(seqqueue *psq)
{
	assert(psq != NULL);
	return (size_t)psq->rear >= psq->capcity;
}

//�ж��Ƿ�Ϊ�ն�
bool seqqueueEomty(seqqueue *psq)
{
	assert(psq != NULL);
	return psq->front == psq->rear;
}

//���
void seqqueueEnque(seqqueue *psq, ElemType x)
{
	assert(psq != NULL);
	if (seqqueueFull(psq))
	{
		printf("����������%d������ӣ�\n", x);
		return;
	}
	psq->base[psq->rear] = x;
	psq->rear++;

}

//����
void seqqueueDeque(seqqueue *psq)
{
	int i = 0;
	assert(psq != NULL);
	if (seqqueueEomty(psq))
	{
		printf("�����ѿգ����ܳ��ӣ�\n");
		return;
	}
	printf("%2d���ӣ� ", psq->base[0]);
	for (i = 0; i < psq->rear; i++)
	{
		psq->base[i] = psq->base[i + 1];
	}
	psq->rear--;
	seqqueueshow(psq);
}

//ȡ��ͷԪ��
ElemType seqqueueTop(seqqueue *psq)
{
	assert(psq != NULL);
	if (seqqueueEomty(psq))
	{
		return -1;
	}
	return psq->base[0];
}


//��ʾ
void seqqueueshow(seqqueue *psq)
{
	assert(psq != NULL);
	if (seqqueueEomty(psq))
	{
		printf("�����ѿգ�\n");
	}
	else
	{
		printf("����Ϊ�� ");
		for (int i = 0; i <psq->rear; i++)
		{
			printf("%2d  ", psq->base[i]);
		}
		printf("\n");
	}

}

//����
void queueExpansion(seqqueue *psq)
{
	int x;
	printf("��ǰ����Ϊ��%2d  ,������Ҫ�����������\n", psq->capcity);
	scanf("%d", &x);
	psq->capcity = psq->capcity + x;
	printf("���ݳɹ�����ǰ����Ϊ��%2d \n", psq->capcity);
}


//////////////////////////////////////////////////////////////////////
//��ʽ����

typedef  struct linkqueuenode
{
	ElemType base;
	struct linkqueuenode *next;
}linkqueuenode;

typedef  struct linkqueue
{
	linkqueuenode *qfront;
	linkqueuenode *qrear;
}linkqueue;



void linkqueueInit(linkqueue *psq);
void linkqueueEnque(linkqueue *psq, ElemType x);//���
void linkqueueDeque(linkqueue *psq);//����

void linkqueueshow(linkqueue *psq);//��ʾ
struct linkqueuenode* open_qnode(ElemType x);
void linkqueueInit(linkqueue *psq)
{
	
	psq->qfront = psq->qrear = NULL;
	
}
struct linkqueuenode* open_qnode(ElemType x)
{
	linkqueuenode *s = (linkqueuenode*)malloc(sizeof(linkqueuenode));
	assert(s != NULL);
	s->base = x;
	s->next = NULL;
	return s;
}

//���
void linkqueueEnque(linkqueue *psq, ElemType x)
{
	assert(psq != NULL);
	linkqueuenode *s = open_qnode(x);
	if (psq->qfront == NULL)
	{
		psq->qfront = psq->qrear = s;
	}
	else
	{
		psq->qrear->next = s;
		psq->qrear = s;
	}

}
//
//����
void linkqueueDeque(linkqueue *psq)
{
	int i = 0;

	if (psq->qfront == NULL)
	{
		printf("�����ѿգ����ܳ��ӣ�\n");
		return;
	}
	linkqueuenode *p = (linkqueuenode*)malloc(sizeof(linkqueuenode));
	p = psq->qfront;
	printf("%2d���ӣ� ", p->base);
	psq->qfront = p->next;
	free(p);
	linkqueueshow(psq);
}
//
//ȡ��ͷԪ��
ElemType linkqueueTop(linkqueue *psq)
{
	return psq->qfront->base;
}


//��ʾ
void linkqueueshow(linkqueue *psq)
{

	if (psq->qfront == NULL)
	{
		printf("�����ѿգ�\n");
	}
	else
	{
		linkqueuenode *p = (linkqueuenode*)malloc(sizeof(linkqueuenode));
		p = psq->qfront;
		printf("����Ԫ��Ϊ�� ");
		while (p != NULL)
		{
			printf("%2d  ", p->base);
			p = p->next;
		}
		printf("\n");
	}

}

#endif /*_QUEUE_H_*/