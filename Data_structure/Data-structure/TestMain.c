#define _CRT_SECURE_NO_WARNINGS 1
#include "seqlist.h"
#include "list.h"
#include "stack.h"
#include "queue.h"
#include "tree.h"


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////˳���
//int main()
//{
//	slist mylist;
//	listInit(&mylist);
//	ElemType data;
//	int s = 1;
//	while (s = 1)
//	{
//		printf("*****************************************************************\n");
//		printf("****** [1]β������                       [2]ͷ������      ******\n");
//		printf("****** [3]β��ɾ��                       [4]ͷ��ɾ��      ******\n");
//		printf("****** [5]���                         [6]�ݻ�          ******\n");
//		printf("****** [7]��ʾ����                       [0]�˳�ϵͳ      ******\n");
//		printf("****************************************************************\n");
//		printf("������ѡ�");
//		scanf("%d", &s);
//		if (s == 0)
//			break;
//		switch (s)
//		{
//		case 1:
//			printf("������Ҫ�����ֵ����-1������:>");
//
//			while (scanf("%d", &data), data != -1)
//			{
//				slistPushBackPushBack(&mylist, data);
//			}
//			break;
//
//		case 2:
//			printf("������Ҫ�����ֵ����-1������:>");
//			while (scanf("%d", &data), data != -1)
//			{
//				slistPushFront(&mylist, data);
//			}
//			break;
//		case 3:
//			slistPopBack(&mylist);
//			break;
//		case 4:
//			slistPopFront(&mylist);
//			break;
//		case 5:
//		{
//				  int length = slistlength(&mylist);
//				  printf("��Ϊ:%d \n", length);
//				  break;
//		}
//		case 6:
//			slistDestroy(&mylist);
//			break;
//		case 7:
//			slistShow(&mylist);
//			break;
//		}
//	}
//	printf("���˳����ټ���\n");
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////˫��ѭ������
//int main()
//{
//	DCList mylist;
//	DCListInit(&mylist);
//	ElemType data;
//	int s = 1;
//	while (s = 1)
//	{
//		printf("*****************************************************************\n");
//		printf("****** [1]β������                       [2]ͷ������      ******\n");
//		printf("****** [3]β��ɾ��                       [4]ͷ��ɾ��      ******\n");
//		printf("****** [5]���                         [6]�ݻ�          ******\n");
//		printf("****** [7]��ʾ����                       [0]�˳�ϵͳ      ******\n");
//		printf("****************************************************************\n");
//		printf("������ѡ�");
//		scanf("%d", &s);
//		if (s == 0)
//			break;
//		switch (s)
//		{
//		case 1:
//			printf("������Ҫ�����ֵ����-1������:>");
//
//			while (scanf("%d", &data), data != -1)
//			{
//				DCListPushBack(&mylist, data);
//			}
//			break;
//		case 2:
//			printf("������Ҫ�����ֵ����-1������:>");
//			while (scanf("%d", &data), data != -1)
//			{
//				DCListPushFront(&mylist, data);
//			}
//			break;
//		case 3:
//			DCListPopBack(&mylist);
//			break;
//		case 4:
//			DCListPopFront(&mylist);
//			break;
//		case 5:
//		{
//				  int length = DCListlength(&mylist);
//				  printf("��Ϊ:%d \n", length);
//				  break;
//		}
//		case 6:
//			DCListDestroy(&mylist);
//			break;
//		case 7:
//			DCListShow(&mylist);
//			break;
//		}
//	}
//	printf("���˳����ټ���\n");
//	return 0;
//}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ջ

////˳��ջ
//int main()
//{
//	seqstack ls;
//	seqstackInit(&ls);
//	ElemType data;
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////��ջ
//int main()
//{
//	linkstack ls;
//	linkstackInit(&ls);
//	ElemType data;
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
//			  ElemType x = linkstackTop(&ls);
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
////����
////˳�����
//int main()
//{
//	seqqueue q;
//	seqqueueInit(&q);
//	ElemType data;
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
//			break;
//
//		case 2:
//			seqqueueDeque(&q);
//			break;
//		case 3:
//			if (seqqueueTop(&q) == -1)
//			{
//				printf("�նӣ�\n");
//				break;
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
//		}
//	}
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////������
//int main()
//{
//	linkqueue q;
//	linkqueueInit(&q);
//	ElemType data;
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
//				linkqueueEnque(&q, data);
//			}
//			break;
//
//		case 2:
//			linkqueueDeque(&q);
//			break;
//		case 3:
//		   if (linkqueueTop(&q) == -1)
//			{
//				printf("�նӣ�\n");
//				break;
//			}
//		   printf("��ͷԪ��Ϊ��%d\n", linkqueueTop(&q));
//			break;
//		case 4:
//			linkqueueshow(&q);
//			break;	
//		}
//	}
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//������

int main()
{
	const char s[] = {"abc##de##f##g#h##"};
	BinTree mbt;
	BinTreeInIt(&mbt);
	//BinTreeCreate(&mbt);
	BinTreeCreatestr(&mbt,s);
	////����
	/*printf("VLR   :");
	PreOrder(&mbt);
	printf("\n");
	printf("LVR   :");
	InOrder(&mbt);
	printf("\n");
	printf("RVL   :");
	PosOrder(&mbt);
	printf("\n");
	printf("Level :");
	LevelOrder(&mbt);
	printf("\n");
	printf("size=%d\n", BinTreeCount(&mbt));
	printf("height=%d\n", BinTreeHeight(&mbt));*/

	////���Ҹ��ڵ�
	//BinTreeNode* p = BinTreeParent(&mbt, 'a');
	//if (NULL == p)
	//	printf("��Ҫ���ҵĸ��ڵ㲻���ڣ�\n");
	//else
	//{
	//	printf("data=%c\n", p->data);
	//}

	////���ҽڵ�
	/*BinTreeNode* p =BinTreeFind(&mbt, 'a');
	if (NULL == p)
		printf("��Ҫ���ҵĽڵ㲻���ڣ�\n");
	else
	{
		printf("data=%c\n", p->data);
	}*/

	////����
	BinTree bt;
	BinTreeInIt(&bt);
	BinTreeCopy(&mbt, &bt);//ͨ��mbt����bt

	////�ж����������Ƿ����
	const char sr[] = { "abc##de##f##G#h##" };
	BinTree bt1;
	BinTreeInIt(&bt1);
	BinTreeCreatestr(&bt1, sr);

	if (BinTreeEqual(&mbt, &bt))
		printf("mbt��bt��ȣ�\n");
	else
		printf("mbt��bt����ȣ�\n");	

	if (BinTreeEqual(&bt, &bt1))
		printf("bt��bt1��ȣ�\n");
	else
		printf("bt��bt1����ȣ�\n");
	return 0;
}