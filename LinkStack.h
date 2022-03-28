#include<stdio.h>
#include<stdlib.h>

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;


//�ݶ�Ԫ������Ϊint
typedef int ElemType;

//����ڵ�
typedef struct StackNode {
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

//������ջ
typedef struct LinkStack {
	LinkStackPtr top;
	int count;
}LinkStack;

Status initLStack(LinkStack* s);//��ʼ��ջ
Status isEmptyLStack(LinkStack* s);//�ж�ջ�Ƿ�Ϊ��
Status getTopLStack(LinkStack* s, ElemType* e);//�õ�ջ��Ԫ��
Status clearLStack(LinkStack* s);//���ջ
Status destroyLStack(LinkStack* s);//����ջ
Status LStackLength(LinkStack* s, int* length);//���ջ����
Status pushLStack(LinkStack* s, ElemType data);//��ջ
Status popLStack(LinkStack* s, ElemType* data);//��ջ
Status printLStack(LinkStack* s);
void menu();
