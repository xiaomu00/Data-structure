#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"
#include "queue.h"

//˳��ջ
//int main()
//{
//	seqstack ls;
//	seqstackInit(&ls);
//	Elemtype data;
//	int s = 1;
//	while (s = 1)
//	{
//		printf("*****************************************************************\n");
//		printf("****** [1]��ջ                           [2]��ջ          *******\n");
//		printf("****** [3]ȡջ��Ԫ��                     [4]��ʾջ����    *******\n");
//		printf("****** [5]����                           [0]�˳�ϵͳ     *******\n");
//		printf("*****************************************************************\n");
//		printf("������ѡ�");
//		scanf("%d", &s);
//		if (s == 0)
//		{
//			printf("���˳����ټ���\n");
//			break;
//		}
//			
//		switch (s)
//		{
//		case 1:
//			printf("������Ҫ�����ֵ����-1������:>");
//
//			while (scanf("%d", &data), data != -1)
//			{
//				seqstackPush(&ls, data);
//			}
//			break;
//
//		case 2:
//			seqstackPop(&ls);
//			break;
//		case 3:
//			if (seqstackEomty(&ls))
//			{
//				printf("��ջ��\n");
//				break;
//			}
//			printf("ջ��Ԫ��Ϊ��%d\n", seqstackTop(&ls));
//			break;
//		case 4:
//			seqstackshow(&ls);
//			break;
//
//		case 5:
//			Expansion(&ls);
//			break;
//		}
//	}	
//	return 0;
//}

//��ջ
//int main()
//{
//	linkstack ls;
//	linkstackInit(&ls);
//	Elemtype data;
//	int s = 1;
//	while (s = 1)
//{
//	printf("*****************************************************************\n");
//	printf("****** [1]��ջ                           [2]��ջ          *******\n");
//	printf("****** [3]ȡջ��Ԫ��                     [4]��ʾջ����    *******\n");
//	printf("****** [5]����                           [0]�˳�ϵͳ     *******\n");
//	printf("*****************************************************************\n");
//	printf("������ѡ�");
//	scanf("%d", &s);
//	if (s == 0)
//	{
//		printf("���˳����ټ���\n");
//		break;
//	}
//	switch (s)
//	{
//	case 1:
//		printf("������Ҫ�����ֵ����-1������:>");
//
//		while (scanf("%d", &data), data != -1)
//		{
//			linkstackPush(&ls, data);
//		}
//		break;	
//	case 2:
//		linkstackPop(&ls);
//		break;
//	case 3:
//	 {
//			  Elemtype x = linkstackTop(&ls);
//			  if (x == -1)
//			  {
//				  printf("��ջ����ջ��Ԫ��\n");
//				  break;
//			  }
//			  else
//			  {
//				  printf("ջ��Ԫ��Ϊ��%d\n", x);
//				  break;
//			  }		 
//	}
//	case 4:
//		linkstackshow(&ls);
//		break;
//	}
//}
//   return 0;
//}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//˳�����
//int main()
//{
//	seqqueue q;
//	seqqueueInit(&q);
//	Elemtype data;
//	int s = 1;
//	while (s = 1)
//	{
//		printf("*****************************************************************\n");
//		printf("****** [1]���                           [2]����          *******\n");
//		printf("****** [3]ȡ��ͷԪ��                     [4]��ʾ������    *******\n");
//		printf("****** [5]����                           [0]�˳�ϵͳ     *******\n");
//		printf("*****************************************************************\n");
//		printf("������ѡ�");
//		scanf("%d", &s);
//		if (s == 0)
//		{
//			printf("���˳����ټ���\n");
//			break;
//		}
//
//		switch (s)
//		{
//		case 1:
//			printf("������Ҫ�����ֵ����-1������:>");
//
//			while (scanf("%d", &data), data != -1)
//			{
//				seqqueueEnque(&q, data);
//			}
//				break;
//
//		case 2:
//			seqqueueDeque(&q);
//			break;
//		case 3:
//			if (seqqueueTop(&q)==-1)
//			{
//			printf("�նӣ�\n");
//			break;
//			}
//			printf("��ͷԪ��Ϊ��%d\n", seqqueueTop(&q));
//			break;
//		case 4:
//			seqqueueshow(&q);
//			break;
//
//		case 5:
//			queueExpansion(&q);
//			break;
//			}
//		}
//	return 0;
//	}



//������
int main()
{
	linkqueue q;
	linkqueueInit(&q);
	Elemtype data;
	int s = 1;
	while (s = 1)
	{
		printf("*****************************************************************\n");
		printf("****** [1]���                           [2]����          *******\n");
		printf("****** [3]ȡ��ͷԪ��                     [4]��ʾ������    *******\n");
		printf("****** [5]����                           [0]�˳�ϵͳ     *******\n");
		printf("*****************************************************************\n");
		printf("������ѡ�");
		scanf("%d", &s);
		if (s == 0)
		{
			printf("���˳����ټ���\n");
			break;
		}

		switch (s)
		{
		case 1:
			printf("������Ҫ�����ֵ����-1������:>");

			while (scanf("%d", &data), data != -1)
			{
				linkqueueEnque(&q, data);
			}
			break;

		case 2:
			linkqueueDeque(&q);
			break;
		case 3:
		   if (linkqueueTop(&q) == -1)
			{
				printf("�նӣ�\n");
				break;
			}
		   printf("��ͷԪ��Ϊ��%d\n", linkqueueTop(&q));
			break;
		case 4:
			linkqueueshow(&q);
			break;

		
		}
	}
	return 0;
}

