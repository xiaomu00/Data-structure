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
		printf("****** [1]��ջ                           [2]��ջ          *******\n");
		printf("****** [3]ȡջ��Ԫ��                     [4]��ʾջ����    *******\n");
		printf("****** [5]����                          [0]�˳�ϵͳ     *******\n");
		printf("*****************************************************************\n");
		printf("������ѡ�");
		scanf("%d", &s);
		if (s == 0)
		{
			printf("���˳����ټ���\n");
			break;
		}
			
		switch (s)
		{
		case 1:
			printf("������Ҫ�����ֵ����-1������:>");

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
				printf("��ջ��\n");
				break;
			}
			printf("ջ��Ԫ��Ϊ��%d\n", seqstackTop(&ls));
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



