#include<stdio.h>
struct Node{
	char dt;
	Node *rNode;
	Node *lNode;
};
int Max=0;
char getOnechar(char ch[20])//��ȡһ���ַ� 
{
	static int i;
	return ch[i++];
}
void Create(Node **t,char ch[20])//���� 
{
	char c=getOnechar(ch);
	if(c!='*')
	{
		Node *n1=new Node;
		n1->dt=c;
		(*t)=n1;
		Create(&(n1->lNode),ch); 
		Create(&(n1->rNode),ch);
	}
	else
		(*t)=NULL;
}
void printPre(Node *t)//ǰ���ӡ 
{
	if(t!=NULL)
	{
		printf("%c ",t->dt);
		printPre(t->lNode);
		printPre(t->rNode);
	}
}
void printZhong(Node *t)//�����ӡ 
{
	if(t!=NULL)
	{
		printZhong(t->lNode);
		printf("%c ",t->dt);
		printZhong(t->rNode);
	}
}
void printHou(Node *t)//�����ӡ 
{
	if(t!=NULL)
	{
		printHou(t->lNode);
		printHou(t->rNode);
		printf("%c ",t->dt);
	}
}
void getH(Node *t,int h)//������� 
{
	if(t!=NULL)
	{
		if(h>Max)
			Max=h;
		getH(t->lNode,h+1);
		getH(t->rNode,h+1);
	}
}
int count(Node *t)//����Ҷ���� 
{
	if(t!=NULL)
	{
		int x1=count(t->lNode);
		int x2=count(t->rNode);
		if(x1+x2==0)
			return 1;
		return x1+x2;
	}
	else
		return 0;
} 
int countSum(Node *t)//����ڵ����� 
{
	if(t!=NULL)
	{
		int x1=countSum(t->lNode);
		int x2=countSum(t->rNode);
		if(t->lNode==NULL&&t->rNode==NULL)
			return 1;
		return x1+x2+1;
	}
	else
		return 0;
}
Node* copy1(Node *s)//���� 
{
	Node *t=NULL;
	if(s!=NULL)
	{
		t=new Node;
		t->dt=s->dt;
		t->lNode=copy1(s->lNode);
		t->rNode=copy1(s->rNode);
	}
	return t;
}
void copy2(Node *s,Node **t)//���� 
{
	if(s!=NULL)
	{
		(*t)=new Node;
		(*t)->dt=s->dt;
		copy2(s->lNode,&(*t)->lNode);
		copy2(s->rNode,&(*t)->rNode);
	}
	else
		(*t)=NULL;
}
int main()
{
	Node *tree,*tree1;
	char ch[20]="ABD*F***CE***";
	Create(&tree,ch);
	printf("ǰ�����Ϊ��");
	printPre(tree);
	printf("\n�������Ϊ��");
	printZhong(tree);
	printf("\n�������Ϊ��");
	printHou(tree);
	copy2(tree,&tree1);
	printf("\n���ƴ���ǰ�����Ϊ��");
	printPre(tree1);
	getH(tree,1);
	printf("\nH: %d\n",Max);
	int num=count(tree);
	printf("\nҶ����: %d\n",num);
	int sum=countSum(tree);
	printf("\n�ڵ���: %d\n",sum);
	return 0;
}
