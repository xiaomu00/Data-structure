 #define _CRT_SECURE_NO_WARNINGS 1
#include "list.h"



//void Tist_list()
//{
//	List mylist;
//	List_Init(&mylist);
//	//ListCreate_Tail(&mylist);
//	ListCreate_Head(&mylist);
//	Listshow(mylist);
//}
//
//int main()
//{
//	Tist_list();
//	return 0;
//}


int main()
{
	slist mylist;
	listInit(&mylist);
	ElmeType data;
	int s = 1;
	while (s = 1)
	{
		printf("*****************************************************************\n");
		printf("****** [1]尾部插入                       [2]头部插入      ******\n");
		printf("****** [3]尾部删除                       [4]头部删除      ******\n");
		printf("****** [5]求表长                         [6]摧毁          ******\n");
		printf("****** [7]显示数据                       [0]退出系统      ******\n");
		printf("****************************************************************\n");
		printf("请输入选项：");
		scanf("%d", &s);
		if (s == 0)
			break;
		switch (s)
		{
		case 1:
			printf("请输入要插入的值【以-1结束】:>");

			while (scanf("%d", &data), data != -1)
			{
				slistPushBackPushBack(&mylist, data);
			}
			break;

		case 2:
			printf("请输入要插入的值【以-1结束】:>");
			while (scanf("%d", &data), data != -1)
			{
				slistPushFront(&mylist,data);
			}
			break;
		case 3:
			slistPopBack(&mylist);
			break;

		case 4:
			slistPopFront(&mylist);
			break;

	
		case 5:
		{
				  int length = slistlength(&mylist);
				  printf("表长为:%d \n", length);
				  break;
		}
		case 6:
			slistDestroy(&mylist);
			break;
		case 7:
			slistShow(&mylist);
			break;

		}
	}
	printf("已退出，再见！\n");
	return 0;
}

