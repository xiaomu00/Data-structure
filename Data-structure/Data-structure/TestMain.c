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
		printf("****** [1]β������                       [2]ͷ������      ******\n");
		printf("****** [4]β��ɾ��   Push_back           Pop_front         [5]ͷ��ɾ��      ******\n");
		printf("****** [6]��λ�ò��� insert_pos        delete_pos            [7]��λ��ɾ��    ******\n");
		printf("****** [8]����   find_val                        [9]���          ******\n");
		printf("****** [9]��ʾ����                       [0]�˳�ϵͳ      ******\n");
		printf("****************************************************************\n");
		printf("������ѡ�");
		scanf("%d",&s);
		if (s == 0)
			break;
		switch (s)
		{
		case 1:
			printf("������Ҫ�����ֵ����-1������:>");
			
			while (scanf("%d", &data),data != -1)
			{
				SeqListPushBack(&mylist,data);
			}
			break;

		case 2:
			printf("������Ҫ�����ֵ����-1������:>");
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
	printf("���˳����ټ���\n");
	return 0;
}