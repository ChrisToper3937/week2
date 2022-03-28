#include"D:\VSProgram\Test\Inverse Polish calculator\calculator.h"
//初始化栈
Status InitStack(Stack* s)
{
	s->top = NULL;
	s->count = 0;

	return SUCCESS;
}

//判断是否为空
Status isEmpty(Stack* stack) {
	if (stack->count == 0)return SUCCESS;
	return ERROR;
};

//头插入栈
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

//出栈
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

//获取栈顶元素
int getTop(Stack* stack) {
	if (stack->top==NULL)
	{
		printf("链栈中没有数值！\n");
		return ERROR;
	}
	return (stack->top->data);
};

//判断符号优先级
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

