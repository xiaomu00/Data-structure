#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"
#include "queue.h"

//顺序栈
//int main()
//{
//	seqstack ls;
//	seqstackInit(&ls);
//	Elemtype data;
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

//链栈
//int main()
//{
//	linkstack ls;
//	linkstackInit(&ls);
//	Elemtype data;
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
//			  Elemtype x = linkstackTop(&ls);
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

//顺序队列
//int main()
//{
//	seqqueue q;
//	seqqueueInit(&q);
//	Elemtype data;
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
//				break;
//
//		case 2:
//			seqqueueDeque(&q);
//			break;
//		case 3:
//			if (seqqueueTop(&q)==-1)
//			{
//			printf("空队！\n");
//			break;
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
//			}
//		}
//	return 0;
//	}



//链队列
int main()
{
	linkqueue q;
	linkqueueInit(&q);
	Elemtype data;
	int s = 1;
	while (s = 1)
	{
		printf("*****************************************************************\n");
		printf("****** [1]入队                           [2]出队          *******\n");
		printf("****** [3]取队头元素                     [4]显示队数据    *******\n");
		printf("****** [5]扩容                           [0]退出系统     *******\n");
		printf("*****************************************************************\n");
		printf("请输入选项：");
		scanf("%d", &s);
		if (s == 0)
		{
			printf("已退出，再见！\n");
			break;
		}

		switch (s)
		{
		case 1:
			printf("请输入要插入的值【以-1结束】:>");

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
				printf("空队！\n");
				break;
			}
		   printf("队头元素为：%d\n", linkqueueTop(&q));
			break;
		case 4:
			linkqueueshow(&q);
			break;

		
		}
	}
	return 0;
}

