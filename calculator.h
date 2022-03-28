#include<stdio.h>
#include<stdlib.h>

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;

//构建结点和栈结构
typedef struct node {
	int data;
	struct node* next;
}Node;

typedef struct stack {
	Node* top;
	int count;
}Stack;

//初始化栈
Status initStack(Stack*stack);

//判断是否为空
Status isEmpty(Stack* stack);

//入栈
Status Push(Stack* stack, int num);

//出栈
int Pop(Stack* stack);

//获取栈顶元素
int getTop(Stack* stack);

//判断符号优先级
int Priority(char symbol);

