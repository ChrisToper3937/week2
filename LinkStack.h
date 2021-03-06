#include<stdio.h>
#include<stdlib.h>

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;


//暂定元素类型为int
typedef int ElemType;

//构造节点
typedef struct StackNode {
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

//构造链栈
typedef struct LinkStack {
	LinkStackPtr top;
	int count;
}LinkStack;

Status initLStack(LinkStack* s);//初始化栈
Status isEmptyLStack(LinkStack* s);//判断栈是否为空
Status getTopLStack(LinkStack* s, ElemType* e);//得到栈顶元素
Status clearLStack(LinkStack* s);//清空栈
Status destroyLStack(LinkStack* s);//销毁栈
Status LStackLength(LinkStack* s, int* length);//检测栈长度
Status pushLStack(LinkStack* s, ElemType data);//入栈
Status popLStack(LinkStack* s, ElemType* data);//出栈
Status printLStack(LinkStack* s);
void menu();
