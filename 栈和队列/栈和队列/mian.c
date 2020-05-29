#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"


int main()
{
	seqstack ls;
	seqstackInit(&ls);
	Elemtype data;
	int s = 1;
	while (s = 1)
	{
		printf("*****************************************************************\n");
		printf("****** [1]入栈                           [2]出栈          *******\n");
		printf("****** [3]取栈顶元素                     [4]显示栈数据    *******\n");
		printf("****** [5]扩容                          [0]退出系统     *******\n");
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
				seqstackPush(&ls, data);
			}
			break;

		case 2:
			seqstackPop(&ls);
			break;
		case 3:
			if (seqstackEomty(&ls))
			{
				printf("空栈！\n");
				break;
			}
			printf("栈顶元素为：%d\n", seqstackTop(&ls));
			break;
		case 4:
			seqstackshow(&ls);
			break;

		case 5:
			Expansion(&ls);
			break;

		}
	}
	
	return 0;
}



