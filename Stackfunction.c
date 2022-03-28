#include"D:\VSProgram\Test\LinkStackTest\LinkStack.h"

//��ʼ��ջ
Status initLStack(LinkStack* s) {
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (s->top == NULL)return ERROR;
	s->count = 0;
	s->top = NULL;
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack* s) {
	if (s->count == 0)
	{
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack* s, ElemType* e) {
	if (s->top == NULL)
	{
		return ERROR;
	}
	else
	{
		*e = s->top->data;
		return SUCCESS;
	}
}

//���ջ
Status clearLStack(LinkStack* s) {
	LinkStackPtr temp = s;
	if (s == NULL)return SUCCESS;
	while (temp)
	{
		temp = temp->next;
	}
	s->top =NULL;
	return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack* s) {
	LinkStackPtr p, q;
	p =q= s->top;
	while (p)
	{
		p = q;
		p = p->next;
		free(q);
	}
	s->count = 0;
	return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack* s, int* length) {
	*length = s->count;
	printf("��ջ�ĳ���Ϊ��%d", *length);
	return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack* s, ElemType data) {
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	if (p == NULL)return ERROR;
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	return SUCCESS;
}

//��ջ
Status popLStack(LinkStack* s, ElemType* data) {
	LinkStackPtr temp;
	if (isEmptyLStack(s) == SUCCESS)
	{
		return ERROR;
	}
	else
	{
		temp = s->top;
		s->top = s->top->next;
		free(temp);
		s->count--;
		return SUCCESS;
	}
}

Status printLStack(LinkStack* s) {
	LinkStackPtr temp = s->top;
	while (temp==NULL)
	{
		printf("��ջΪ��\n");
		return ERROR;
	}
	while (temp)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	return SUCCESS;
}

void menu() {
	printf("1.�ж���ջ�Ƿ�Ϊ��\n");
	printf("2.ѹջ\n");
	printf("3.��ջ\n");
	printf("4.��ȡջ��Ԫ��\n");	
	printf("5.��ȡ��ջ����\n");
	printf("6.���ջ\n");
	printf("7.����ջ\n");
	printf("8.��ӡ��ջ\n");
	printf("9.�˳�\n");
}