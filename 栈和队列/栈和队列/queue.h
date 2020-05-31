#ifndef _QUEUE_H_
#define _QUEUE_H_

#define queue_size 5
#define Elemtype int


//////////////////////////////////////////////////////////////////////
//˳�����

typedef  struct seqqueue
{
	Elemtype *base;
	size_t capcity;
	int front;
	int rear;
}seqqueue;

void seqqueueInit(seqqueue *psq);
bool seqqueueFull(seqqueue *psq);//�ж��Ƿ����
bool seqqueueEomty(seqqueue *psq);//�ж��Ƿ�Ϊ�ն�
void seqqueueEnque(seqqueue *psq, Elemtype x);//���
void seqqueueDeque(seqqueue *psq);//����
Elemtype seqqueueTop(seqqueue *psq);//ȡ��ͷԪ��
void seqqueueshow(seqqueue *psq);//��ʾ
void queueExpansion(seqqueue *psq);//����

void seqqueueInit(seqqueue *psq)
{
	psq->base = (Elemtype*)malloc(sizeof(Elemtype)*queue_size);
	assert(psq->base!=NULL);
	psq->capcity = queue_size;
	psq->front = psq->rear = 0;
}
//�ж��Ƿ����
bool seqqueueFull(seqqueue *psq)
{  
	assert(psq!=NULL);
	return (size_t)psq->rear >= psq->capcity;
}

//�ж��Ƿ�Ϊ�ն�
bool seqqueueEomty(seqqueue *psq)
{ 
	assert(psq != NULL);
	return psq->front == psq->rear; 
}

//���
void seqqueueEnque(seqqueue *psq,Elemtype x)
{
	assert(psq != NULL);
	if (seqqueueFull(psq))
	{
		printf("����������%d������ӣ�\n",x);
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
	printf("%2d���ӣ� ",psq->base[0]);
	for (i = 0; i < psq->rear; i++)
	{
		psq->base[i] = psq->base[i+1];
	}
	psq->rear--;
	seqqueueshow(psq);
}

//ȡ��ͷԪ��
Elemtype seqqueueTop(seqqueue *psq)
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
			printf("%2d  ",psq->base[i]);
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
//////////////////////////////////////////////////////////////////////
//˳�����

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
void linkqueueEnque(linkqueue *psq, Elemtype x);//���
void linkqueueDeque(linkqueue *psq);//����
Elemtype linkqueueTop(linkqueue *psq);//ȡ��ͷԪ��
void linkqueueshow(linkqueue *psq);//��ʾ
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

//���
void linkqueueEnque(linkqueue *psq, Elemtype x)
{
	assert(psq != NULL);
	linkqueuenode *s = open_qnode(x);
	psq->qrear->next = s;
	psq->qrear = s;
}
//
//����
void linkqueueDeque(linkqueue *psq)
{
	int i = 0;
	assert(psq != NULL);
	if (psq->qfront->next==NULL)
	{
		printf("�����ѿգ����ܳ��ӣ�\n");
		return;
	}
	linkqueuenode *p = (linkqueuenode*)malloc(sizeof(linkqueuenode));
	p = psq->qfront->next;
	printf("%2d���ӣ� ", p->base);
	psq->qfront->next = p->next;
	free(p);
	linkqueueshow(psq);
}
//
//ȡ��ͷԪ��
Elemtype linkqueueTop(linkqueue *psq)
{
	assert(psq != NULL);
	if (psq->qfront == psq->qrear)
	{
		return -1;
	}
	return psq->qfront->next->base;
}


//��ʾ
void linkqueueshow(linkqueue *psq)
{
	assert(psq != NULL);
	if (psq->qfront==psq->qrear)
	{
		printf("�����ѿգ�\n");
	}
	else
	{
		linkqueuenode *p = (linkqueuenode*)malloc(sizeof(linkqueuenode));
		p = psq->qfront->next;
		printf("����Ԫ��Ϊ�� ");
		while (p!= NULL)
		{
			printf("%2d  ", p->base);
			p = p->next;
		}
		printf("\n");
	}

}








#endif /*_QUEUE_H_*/