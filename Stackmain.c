#include"D:\VSProgram\Test\LinkStackTest\LinkStack.h"
int main() {

	LinkStack *s=(LinkStack*)malloc(sizeof(LinkStack));

	//链栈初始化
	if (initLStack(s))
	{
		printf("链栈初始化成功!\n");
	}
	else
	{
		printf("链栈初始化失败!\n");
	}
	int choice=0;

	while (1)
	{
		menu();			
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1: {
			printf("判断栈是否为空?\n");
			int n1 = isEmptyLStack(s);
			if (n1)
			{
				printf("判断栈为空\n");
			}
			else
			{
				printf("判断栈不为空\n");
			}
			break;
		}
		case 2: {
			printf("请输入链栈元素的值：");
			int data = 0;
			scanf_s("%d", &data);
			int n2 = pushLStack(s, data);
			if (n2)
			{
				printf("入栈成功\n");

			}
			else
			{
				printf("入栈失败\n");

			}
			break;
		}
		case 3: {
			int deldata = 0;
			int n3 = popLStack(s, &deldata);
			if (n3)
			{
				printf("出栈成功\n");

			}
			else
			{
				printf("出栈失败\n");

			}
			printf("出栈元素为：%d\n", deldata);
			break;
		}
		case 4: {
			printf("得到栈顶元素\n");
			int top = 0;
			int n4 = getTopLStack(s, &top);
			if (n4)
			{
				printf("获取成功\n");
			}
			else
			{
				printf("获取失败\n");
			}
			printf("栈顶元素为:%d\n", top);
			break;
		}
		case 5: {
			printf("检测栈长度\n");
			int length = 0;
			int n5 = LStackLength(s, &length);
			if (n5)
			{
				printf("获取成功\n");
			}
			else
			{
				printf("获取失败\n");
			}
			printf("链栈长度为：%d\n", length);
			break;
		}
		case 6: {
			printf("清空栈\n");
			int n6 = clearLStack(s);
			if (n6)
			{
				printf("清空成功\n");
			}
			else
			{
				printf("清空失败\n");
			}
			break;
		}
		case 7: {
			printf("销毁栈\n");
			int n7 = destroyLStack(s);
			if (n7)
			{
				printf("销毁成功\n");
			}
			else
			{
				printf("销毁失败\n");
			}
			break;
		}
		case 8: {
			printf("打印链栈：\n");
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