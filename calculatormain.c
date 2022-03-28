#include"D:\VSProgram\Test\Inverse Polish calculator\calculator.h"
int main() {
	
	Stack num,sym;
	char str[100]={0};
	int i = 0, temp = 0, j=0;

	if (InitStack(&num)!=ERROR&&InitStack(&sym)!=ERROR)
	{
		printf("计算器初始化成功！\n");
	}

	printf("请输入你的算术表达式：");
	scanf_s("%s", str, 100);
	
	while (str[i]!='\0'||isEmpty(&sym)!=SUCCESS)
	{
		if (str[i]>='0'&& str[i]<='9')
		{
			temp = temp * 10 + str[i] - '0';
			i++;
			if (str[i]< '0'|| str[i]>'9')
			{
				Push(&num, temp);
				temp = 0;
			}
		}
		else
		{
			if ((isEmpty(&sym)==SUCCESS)||(getTop(&sym) == '(' && str[i] != ')' )||
				Priority(str[i]) > Priority(getTop(&sym)) )
			{
				Push(&sym, str[i]);
				i++;
				continue;
			}
			if (getTop(&sym) == '(' && str[i] == ')' )
			{
				Pop(&sym);
				i++;
				continue;
			}
			if ((str[i]=='\0' && isEmpty(&sym)!=SUCCESS)||(str[i] == ')' && getTop(&sym)!='(')||
				Priority(str[i])<=Priority(getTop(&sym)))
			{
				switch (Pop(&sym))
				{
				case '+':
					Push(&num, Pop(&num) + Pop(&num));
					break;
				case '-':
					j = Pop(&num);
					Push(&num, Pop(&num) - j);
					break;
				case '*':
					Push(&num, Pop(&num) * Pop(&num));
					break;
				case '/':
					j = Pop(&num);
					Push(&num, Pop(&num) / j);
				}
				continue;
			}
		}
	}
	printf("%d\n", Pop(&num));

	return 0;
}