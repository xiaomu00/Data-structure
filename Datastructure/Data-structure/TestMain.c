#define _CRT_SECURE_NO_WARNINGS 1
#include "seqlist.h"


int main()
{
	SeqList mylist;
	SeqListInit(&mylist);

	ElmeType data;
	int s = 1;
	while (s = 1)
	{
		printf("*****************************************************************\n");
		printf("****** [1]尾部插入                       [2]头部插入      ******\n");
		printf("****** [4]尾部删除   Push_back           Pop_front         [5]头部删除      ******\n");
		printf("****** [6]按位置插入 insert_pos        delete_pos            [7]按位置删除    ******\n");
		printf("****** [8]查找   find_val                        [9]清除          ******\n");
		printf("****** [9]显示数据                       [0]退出系统      ******\n");
		printf("****************************************************************\n");
		printf("请输入选项：");
		scanf("%d",&s);
		if (s == 0)
			break;
		switch (s)
		{
		case 1:
			printf("请输入要插入的值【以-1结束】:>");
			
			while (scanf("%d", &data),data != -1)
			{
				SeqListPushBack(&mylist,data);
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
			
			break;

		case 4:

			break;

		case 5
			:

			break;

		case 6:

			break;

		case 7:

			break;

		case 8:

			break;
		case 9:
			SeqListShow(&mylist);
			break;

		} 
	}
	printf("已退出，再见！\n");
	return 0;
}