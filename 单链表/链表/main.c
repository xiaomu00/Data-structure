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
				slistPushBackPushBack(&mylist, data);
			}
			break;

		case 2:
			printf("������Ҫ�����ֵ����-1������:>");
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
				  printf("��Ϊ:%d \n", length);
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
	printf("���˳����ټ���\n");
	return 0;
}

