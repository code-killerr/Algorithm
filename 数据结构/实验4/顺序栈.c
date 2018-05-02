#include<stdio.h>
#define MAX 8
typedef struct LinkStack//使用typedef结构体中，这个名称初始化使需要struct LinkStack
{
    int data;
	int x;
	int y;
}Stack;//这个名字为typedef名字
Stack line[MAX];
int top=-1;//初始化栈顶
Stack *x;

int Add(int rode)
{
	if(Check()==-1)
		return 0;
	else
	{
		++top;
		line[top].data=rode;
		return 1;
	}
}

int Check()
{
	if(top==-1)//栈空
		return 0;
    else if(top==MAX-1)//栈满
        return -1;
	else return 1;
}

int Pop()
{
	if(top>-1)
	{
	    *x= line[top];
		--top;
		return 1;
	}
	else return 0;
}

int TopStack()
{
    if(Check()==0)
        return 0;
    else return line[top].data;
}
void main()
{

}
