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
	DCList mylist;
	DCListInit(&mylist);
	ElmeType data;
	int s = 1;
	while (s = 1)
	{
		printf("*****************************************************************\n");
		printf("****** [1]β������                       [2]ͷ������      ******\n");
		printf("****** [3]β��ɾ��                       [4]ͷ��ɾ��      ******\n");
		printf("****** [5]���                         [6]�ݻ�          ******\n");
		printf("****** [7]��ʾ����                       [0]�˳�ϵͳ      ******\n");
		printf("****************************************************************\n");
		printf("������ѡ�");
		scanf("%d", &s);
		if (s == 0)
			break;
		switch (s)
		{
		case 1:
			printf("������Ҫ�����ֵ����-1������:>");

			while (scanf("%d", &data), data != -1)
			{
				DCListPushBack(&mylist, data);
			}
			break;

		case 2:
			printf("������Ҫ�����ֵ����-1������:>");
			while (scanf("%d", &data), data != -1)
			{
				DCListPushFront(&mylist, data);
			}
			break;
		case 3:
			DCListPopBack(&mylist);
			break;

		case 4:
			DCListPopFront(&mylist);
			break;


		case 5:
		{
				 int length = DCListlength(&mylist);
				  printf("��Ϊ:%d \n", length);
				  break;
		}
		case 6:
			DCListDestroy(&mylist);
			break;
		case 7:
			DCListShow(&mylist);
			break;

		}
	}
	printf("���˳����ټ���\n");
	return 0;
}



