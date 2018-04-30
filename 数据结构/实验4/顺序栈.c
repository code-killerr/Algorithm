#include<stdio.h>
#define MAX 100
struct LinkStack
{
	int data;
}line[MAX];
int top=-1;//≥ı ºªØ’ª∂• 


int Add(int rode)
{
	if(top<MAX)
	{
		++top;
		line[top].data=rode;
		return 0;
	}
	else return -1;
}


int Del()
{
	if(top>-1)
	{
		--top;
		return 0;
	}
	else return -1;
}


void main()
{
	
}
