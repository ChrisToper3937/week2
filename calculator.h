#include<stdio.h>
#include<stdlib.h>

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;

//��������ջ�ṹ
typedef struct node {
	int data;
	struct node* next;
}Node;

typedef struct stack {
	Node* top;
	int count;
}Stack;

//��ʼ��ջ
Status initStack(Stack*stack);

//�ж��Ƿ�Ϊ��
Status isEmpty(Stack* stack);

//��ջ
Status Push(Stack* stack, int num);

//��ջ
int Pop(Stack* stack);

//��ȡջ��Ԫ��
int getTop(Stack* stack);

//�жϷ������ȼ�
int Priority(char symbol);

