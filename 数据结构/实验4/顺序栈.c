#include<stdio.h>
typedef struct LinkStack
{
	int data[8];
	LinkStack next;
}
LinkStack top=NULL;

void crate()
{
	LinkSysck *p;
	p->next=NULL;
	top=p;
}

void Add()
{
	LinkStack *p;
	top->next=p;
	p->next=NULL;
	top=p;
}

void Del()
{

}