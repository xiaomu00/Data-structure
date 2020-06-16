#define _CRT_SECURE_NO_WARNINGS 1
#include "seqlist.h"
#include "list.h"
#include "stack.h"
#include "queue.h"
#include "tree.h"


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////顺序表
//int main()
//{
//	slist mylist;
//	listInit(&mylist);
//	ElemType data;
//	int s = 1;
//	while (s = 1)
//	{
//		printf("*****************************************************************\n");
//		printf("****** [1]尾部插入                       [2]头部插入      ******\n");
//		printf("****** [3]尾部删除                       [4]头部删除      ******\n");
//		printf("****** [5]求表长                         [6]摧毁          ******\n");
//		printf("****** [7]显示数据                       [0]退出系统      ******\n");
//		printf("****************************************************************\n");
//		printf("请输入选项：");
//		scanf("%d", &s);
//		if (s == 0)
//			break;
//		switch (s)
//		{
//		case 1:
//			printf("请输入要插入的值【以-1结束】:>");
//
//			while (scanf("%d", &data), data != -1)
//			{
//				slistPushBackPushBack(&mylist, data);
//			}
//			break;
//
//		case 2:
//			printf("请输入要插入的值【以-1结束】:>");
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
//				  printf("表长为:%d \n", length);
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
//	printf("已退出，再见！\n");
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////双向循环链表
//int main()
//{
//	DCList mylist;
//	DCListInit(&mylist);
//	ElemType data;
//	int s = 1;
//	while (s = 1)
//	{
//		printf("*****************************************************************\n");
//		printf("****** [1]尾部插入                       [2]头部插入      ******\n");
//		printf("****** [3]尾部删除                       [4]头部删除      ******\n");
//		printf("****** [5]求表长                         [6]摧毁          ******\n");
//		printf("****** [7]显示数据                       [0]退出系统      ******\n");
//		printf("****************************************************************\n");
//		printf("请输入选项：");
//		scanf("%d", &s);
//		if (s == 0)
//			break;
//		switch (s)
//		{
//		case 1:
//			printf("请输入要插入的值【以-1结束】:>");
//
//			while (scanf("%d", &data), data != -1)
//			{
//				DCListPushBack(&mylist, data);
//			}
//			break;
//		case 2:
//			printf("请输入要插入的值【以-1结束】:>");
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
//				  printf("表长为:%d \n", length);
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
//	printf("已退出，再见！\n");
//	return 0;
//}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//栈

////顺序栈
//int main()
//{
//	seqstack ls;
//	seqstackInit(&ls);
//	ElemType data;
//	int s = 1;
//	while (s = 1)
//	{
//		printf("*****************************************************************\n");
//		printf("****** [1]入栈                           [2]出栈          *******\n");
//		printf("****** [3]取栈顶元素                     [4]显示栈数据    *******\n");
//		printf("****** [5]扩容                           [0]退出系统     *******\n");
//		printf("*****************************************************************\n");
//		printf("请输入选项：");
//		scanf("%d", &s);
//		if (s == 0)
//		{
//			printf("已退出，再见！\n");
//			break;
//		}
//			
//		switch (s)
//		{
//		case 1:
//			printf("请输入要插入的值【以-1结束】:>");
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
//				printf("空栈！\n");
//				break;
//			}
//			printf("栈顶元素为：%d\n", seqstackTop(&ls));
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
////链栈
//int main()
//{
//	linkstack ls;
//	linkstackInit(&ls);
//	ElemType data;
//	int s = 1;
//	while (s = 1)
//{
//	printf("*****************************************************************\n");
//	printf("****** [1]入栈                           [2]出栈          *******\n");
//	printf("****** [3]取栈顶元素                     [4]显示栈数据    *******\n");
//	printf("****** [5]扩容                           [0]退出系统     *******\n");
//	printf("*****************************************************************\n");
//	printf("请输入选项：");
//	scanf("%d", &s);
//	if (s == 0)
//	{
//		printf("已退出，再见！\n");
//		break;
//	}
//	switch (s)
//	{
//	case 1:
//		printf("请输入要插入的值【以-1结束】:>");
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
//				  printf("空栈，无栈顶元素\n");
//				  break;
//			  }
//			  else
//			  {
//				  printf("栈顶元素为：%d\n", x);
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
////队列
////顺序队列
//int main()
//{
//	seqqueue q;
//	seqqueueInit(&q);
//	ElemType data;
//	int s = 1;
//	while (s = 1)
//	{
//		printf("*****************************************************************\n");
//		printf("****** [1]入队                           [2]出队          *******\n");
//		printf("****** [3]取队头元素                     [4]显示队数据    *******\n");
//		printf("****** [5]扩容                           [0]退出系统     *******\n");
//		printf("*****************************************************************\n");
//		printf("请输入选项：");
//		scanf("%d", &s);
//		if (s == 0)
//		{
//			printf("已退出，再见！\n");
//			break;
//		}
//
//		switch (s)
//		{
//		case 1:
//			printf("请输入要插入的值【以-1结束】:>");
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
//				printf("空队！\n");
//				break;
//			}
//			printf("队头元素为：%d\n", seqqueueTop(&q));
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

////链队列
//int main()
//{
//	linkqueue q;
//	linkqueueInit(&q);
//	ElemType data;
//	int s = 1;
//	while (s = 1)
//	{
//		printf("*****************************************************************\n");
//		printf("****** [1]入队                           [2]出队          *******\n");
//		printf("****** [3]取队头元素                     [4]显示队数据    *******\n");
//		printf("****** [5]扩容                           [0]退出系统     *******\n");
//		printf("*****************************************************************\n");
//		printf("请输入选项：");
//		scanf("%d", &s);
//		if (s == 0)
//		{
//			printf("已退出，再见！\n");
//			break;
//		}
//
//		switch (s)
//		{
//		case 1:
//			printf("请输入要插入的值【以-1结束】:>");
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
//				printf("空队！\n");
//				break;
//			}
//		   printf("队头元素为：%d\n", linkqueueTop(&q));
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
//二叉树

int main()
{
	const char s[] = {"abc##de##f##g#h##"};
	BinTree mbt;
	BinTreeInIt(&mbt);
	//BinTreeCreate(&mbt);
	BinTreeCreatestr(&mbt,s);
	////遍历
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

	////查找父节点
	//BinTreeNode* p = BinTreeParent(&mbt, 'a');
	//if (NULL == p)
	//	printf("您要查找的父节点不存在！\n");
	//else
	//{
	//	printf("data=%c\n", p->data);
	//}

	////查找节点
	/*BinTreeNode* p =BinTreeFind(&mbt, 'a');
	if (NULL == p)
		printf("您要查找的节点不存在！\n");
	else
	{
		printf("data=%c\n", p->data);
	}*/

	////拷贝
	BinTree bt;
	BinTreeInIt(&bt);
	BinTreeCopy(&mbt, &bt);//通过mbt拷贝bt

	////判断两二叉树是否相等
	const char sr[] = { "abc##de##f##G#h##" };
	BinTree bt1;
	BinTreeInIt(&bt1);
	BinTreeCreatestr(&bt1, sr);

	if (BinTreeEqual(&mbt, &bt))
		printf("mbt和bt相等！\n");
	else
		printf("mbt和bt不相等！\n");	

	if (BinTreeEqual(&bt, &bt1))
		printf("bt和bt1相等！\n");
	else
		printf("bt和bt1不相等！\n");
	return 0;
}