#include"D:\VSProgram\Test\LinkStackTest\LinkStack.h"

//初始化栈
Status initLStack(LinkStack* s) {
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (s->top == NULL)return ERROR;
	s->count = 0;
	s->top = NULL;
	return SUCCESS;
}

//判断栈是否为空
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

//得到栈顶元素
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

//清空栈
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

//销毁栈
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

//检测栈长度
Status LStackLength(LinkStack* s, int* length) {
	*length = s->count;
	printf("链栈的长度为：%d", *length);
	return SUCCESS;
}

//入栈
Status pushLStack(LinkStack* s, ElemType data) {
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	if (p == NULL)return ERROR;
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	return SUCCESS;
}

//出栈
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
		printf("链栈为空\n");
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
	printf("1.判断链栈是否为空\n");
	printf("2.压栈\n");
	printf("3.出栈\n");
	printf("4.获取栈顶元素\n");	
	printf("5.获取链栈长度\n");
	printf("6.清空栈\n");
	printf("7.销毁栈\n");
	printf("8.打印链栈\n");
	printf("9.退出\n");
}