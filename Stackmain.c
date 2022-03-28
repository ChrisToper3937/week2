#include"D:\VSProgram\Test\LinkStackTest\LinkStack.h"
int main() {

	LinkStack *s=(LinkStack*)malloc(sizeof(LinkStack));

	//��ջ��ʼ��
	if (initLStack(s))
	{
		printf("��ջ��ʼ���ɹ�!\n");
	}
	else
	{
		printf("��ջ��ʼ��ʧ��!\n");
	}
	int choice=0;

	while (1)
	{
		menu();			
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1: {
			printf("�ж�ջ�Ƿ�Ϊ��?\n");
			int n1 = isEmptyLStack(s);
			if (n1)
			{
				printf("�ж�ջΪ��\n");
			}
			else
			{
				printf("�ж�ջ��Ϊ��\n");
			}
			break;
		}
		case 2: {
			printf("��������ջԪ�ص�ֵ��");
			int data = 0;
			scanf_s("%d", &data);
			int n2 = pushLStack(s, data);
			if (n2)
			{
				printf("��ջ�ɹ�\n");

			}
			else
			{
				printf("��ջʧ��\n");

			}
			break;
		}
		case 3: {
			int deldata = 0;
			int n3 = popLStack(s, &deldata);
			if (n3)
			{
				printf("��ջ�ɹ�\n");

			}
			else
			{
				printf("��ջʧ��\n");

			}
			printf("��ջԪ��Ϊ��%d\n", deldata);
			break;
		}
		case 4: {
			printf("�õ�ջ��Ԫ��\n");
			int top = 0;
			int n4 = getTopLStack(s, &top);
			if (n4)
			{
				printf("��ȡ�ɹ�\n");
			}
			else
			{
				printf("��ȡʧ��\n");
			}
			printf("ջ��Ԫ��Ϊ:%d\n", top);
			break;
		}
		case 5: {
			printf("���ջ����\n");
			int length = 0;
			int n5 = LStackLength(s, &length);
			if (n5)
			{
				printf("��ȡ�ɹ�\n");
			}
			else
			{
				printf("��ȡʧ��\n");
			}
			printf("��ջ����Ϊ��%d\n", length);
			break;
		}
		case 6: {
			printf("���ջ\n");
			int n6 = clearLStack(s);
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
			printf("����ջ\n");
			int n7 = destroyLStack(s);
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
			printf("��ӡ��ջ��\n");
			printLStack(s);
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