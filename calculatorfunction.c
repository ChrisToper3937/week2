#include"D:\VSProgram\Test\Inverse Polish calculator\calculator.h"
//��ʼ��ջ
Status InitStack(Stack* s)
{
	s->top = NULL;
	s->count = 0;

	return SUCCESS;
}

//�ж��Ƿ�Ϊ��
Status isEmpty(Stack* stack) {
	if (stack->count == 0)return SUCCESS;
	return ERROR;
};

//ͷ����ջ
Status Push(Stack* stack,int num) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		return ERROR;
	}
	
	newNode->data = num;
	newNode->next = stack->top;
	stack->top = newNode;
	stack->count++;

	return SUCCESS;
};

//��ջ
int Pop(Stack* stack) {
	int num;

	if (stack->top == NULL)return ERROR;

	Node* temp = stack->top;
	num = temp->data;
	stack->top = temp->next;
	stack->count--;
	free(temp);

	return num;
};

//��ȡջ��Ԫ��
int getTop(Stack* stack) {
	if (stack->top==NULL)
	{
		printf("��ջ��û����ֵ��\n");
		return ERROR;
	}
	return (stack->top->data);
};

//�жϷ������ȼ�
int Priority(char symbol) {
	switch (symbol)
	{
	case '(':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	default:
		return 0;
	}
};

