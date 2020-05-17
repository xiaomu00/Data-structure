#define _CRT_SECURE_NO_WARNINGS 1
#include "seqlist.h"

////顺序表
int main()
{
	SeqList mylist;
	SeqListInit(&mylist);

	ElmeType data;
	int s = 1;
	int ps;
	while (s = 1)
	{
		printf("*****************************************************************\n");
		printf("****** [1]尾部插入                       [2]头部插入      ******\n");
		printf("****** [3]尾部删除                       [4]头部删除      ******\n");
		printf("****** [5]按位置插入                     [6]按位置删除    ******\n");
		printf("****** [7]按值插入                       [8]按值删除      ******\n");
		printf("****** [9]查找                           [10]清除         ******\n");
		printf("****** [11]求表长                        [12]排序         ******\n");
		printf("****** [13]显示数据                      [0]退出系统      ******\n");
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
				SeqListPushBack(&mylist, data);
			}
			break;

		case 2:
			printf("请输入要插入的值【以-1结束】:>");
			while (scanf("%d", &data), data != -1)
			{
				SeqListPushFront(&mylist, data);
			}
			break;
		case 3:
			SeqListPopBack(&mylist);
			break;

		case 4:
			SeqListPopFront(&mylist);
			break;

		case 5:
			if (IsFull(&mylist))
			{
				printf("数据表已满,不能插入！\n");
				break;
			}
			printf("请输入要插入的位置：");
			scanf("%d",&ps);
			printf("请输入要插入的值:");
			scanf("%d", &data);
			SeqListInserByPos(&mylist,ps,data);
			break;

		case 6:
			if (IsEmpty(&mylist))
			{
				printf("数据表已空,不能删除！\n");
				break;
			}
			printf("请输入要删除的位置：");
			scanf("%d", &ps);
			SeqListPopByPos(&mylist,ps);
			break;

		case 7:
			printf("请输入要插入的值:");
			scanf("%d", &data);
			SeqListInserByVal(&mylist,data);
			break;
		case 8:
			if (IsEmpty(&mylist))
			{
				printf("数据表已空,不能删除！\n");
				break;
			}
			printf("请输入要删除的值：");
			scanf("%d", &data);
			SeqListPopByByVal(&mylist, data);
			break;

		case 9:
			printf("请输入要查找的值:");
			scanf("%d",&data);
			SeqListFind(&mylist, data);
			break;
			
		case 10:
			SeqListclear(&mylist);
			printf("清除成功！\n");
			break;
		case 11:
		{
				  int length = SeqListlength(&mylist);
				  printf("表长为:%d \n", length);
				  break;
		}
		case 12:
			SeqListSort(&mylist);
			break;

		case 13:
			SeqListShow(&mylist);
			break;

		}
	}
	printf("已退出，再见！\n");
	return 0;
}
