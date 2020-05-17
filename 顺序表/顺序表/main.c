#define _CRT_SECURE_NO_WARNINGS 1
#include "seqlist.h"

////˳���
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
		printf("****** [1]β������                       [2]ͷ������      ******\n");
		printf("****** [3]β��ɾ��                       [4]ͷ��ɾ��      ******\n");
		printf("****** [5]��λ�ò���                     [6]��λ��ɾ��    ******\n");
		printf("****** [7]��ֵ����                       [8]��ֵɾ��      ******\n");
		printf("****** [9]����                           [10]���         ******\n");
		printf("****** [11]���                        [12]����         ******\n");
		printf("****** [13]��ʾ����                      [0]�˳�ϵͳ      ******\n");
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
				SeqListPushBack(&mylist, data);
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
			SeqListPopBack(&mylist);
			break;

		case 4:
			SeqListPopFront(&mylist);
			break;

		case 5:
			if (IsFull(&mylist))
			{
				printf("���ݱ�����,���ܲ��룡\n");
				break;
			}
			printf("������Ҫ�����λ�ã�");
			scanf("%d",&ps);
			printf("������Ҫ�����ֵ:");
			scanf("%d", &data);
			SeqListInserByPos(&mylist,ps,data);
			break;

		case 6:
			if (IsEmpty(&mylist))
			{
				printf("���ݱ��ѿ�,����ɾ����\n");
				break;
			}
			printf("������Ҫɾ����λ�ã�");
			scanf("%d", &ps);
			SeqListPopByPos(&mylist,ps);
			break;

		case 7:
			printf("������Ҫ�����ֵ:");
			scanf("%d", &data);
			SeqListInserByVal(&mylist,data);
			break;
		case 8:
			if (IsEmpty(&mylist))
			{
				printf("���ݱ��ѿ�,����ɾ����\n");
				break;
			}
			printf("������Ҫɾ����ֵ��");
			scanf("%d", &data);
			SeqListPopByByVal(&mylist, data);
			break;

		case 9:
			printf("������Ҫ���ҵ�ֵ:");
			scanf("%d",&data);
			SeqListFind(&mylist, data);
			break;
			
		case 10:
			SeqListclear(&mylist);
			printf("����ɹ���\n");
			break;
		case 11:
		{
				  int length = SeqListlength(&mylist);
				  printf("��Ϊ:%d \n", length);
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
	printf("���˳����ټ���\n");
	return 0;
}
