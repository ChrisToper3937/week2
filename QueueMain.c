#include"D:\VSProgram\Test\ListQueue\LQueue.h"

int main() {

	LQueue* Q = (LQueue*)malloc(sizeof(LQueue));
	InitLQueue(Q);

	int choice=0;
	while (1)
	{
		menu();
		
		printf("\n");
		printf("���������ѡ��");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1: {
			printf("�ж϶����Ƿ�Ϊ��?\n");
			int n1 = IsEmptyLQueue(Q);
			if (n1)
			{
				printf("�ж϶���Ϊ��\n");
			}
			else
			{
				printf("�ж϶��в�Ϊ��\n");
			}
			break;
		}
		case 2: {
			printf("���������Ԫ�ص�ֵ��");
			char data[100] ;
			scanf_s("%s", data,100);
			int n2 = EnLQueue(Q, (void*)(data));
			if (n2)
			{
				printf("��ӳɹ�\n");

			}
			else
			{
				printf("���ʧ��\n");

			}
			break;
		}
		case 3: {
			int n3 = DeLQueue(Q);
			if (n3)
			{
				printf("���ӳɹ�\n");

			}
			else
			{
				printf("����ʧ��\n");

			}
			break;
		}
		case 4: {
			printf("�õ���ͷԪ��:\t");
			void* data = NULL;
			int n4= GetHeadLQueue(Q, data);
			if (n4)
			{
				printf("��ȡ�ɹ�\n");
			}
			else
			{
				printf("��ȡʧ��\n");
			}
			break;
		}
		case 5: {
			printf("�����г���\n");
			int length = LengthLQueue(Q);
			if (length)
			{
				printf("��ȡ�ɹ�\n");
			}
			else
			{
				printf("��ȡʧ��\n");
			}
			printf("���г���Ϊ��%d\n", length);
			break;
		}
		case 6: {
			printf("���ջ\n");
			int n6 = ClearLQueue(Q);
			if (n6)
			{
				printf("��ճɹ�\n");
			}
			else
			{
				printf("���ʧ��\n");
			}
			break;
		}
		case 7: {
			printf("���ٶ���\n");
			int n7 = DestoryLQueue(Q);
			if (n7)
			{
				printf("���ٳɹ�\n");
			}
			else
			{
				printf("����ʧ��\n");
			}
			break;
		}
		case 8: {
			printf("��ӡ���У�\n");
			void(*fun)(void*p)=NULL;
			fun = LPrint;
			TraverseLQueue(Q,fun);
			break;
		}
		case 9:
			exit(0);
			break;
		default:
			break;
		}
	}

	return 0;
}