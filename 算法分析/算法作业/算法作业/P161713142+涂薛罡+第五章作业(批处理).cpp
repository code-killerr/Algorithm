#include<stdio.h>
#define maxN 100 
int n,m[maxN][2],bestv=0x3f3f3f3f,f1,f;
int best[maxN],temp[maxN],f2[maxN];
void swap(int x1,int x2)
{
	int t=temp[x1];
	temp[x1]=temp[x2];
	temp[x2]=t;
} 
void dg(int x)
{
	if(x==n+1){
		bestv=f;
		for(int i=1;i<=n;i++)
			best[i]=temp[i];
		return ;
	}
	for(int i=x;i<=n;i++){
		f1+=m[i][0];
		f2[i]=(f1>f2[i-1]?f1:f2[i-1])+m[i][1];
		f+=f2[i];
		if(f<bestv){
			swap(x,i);
			dg(x+1);
			swap(x,i);
		}
		f1-=m[i][0];
		f-=f2[i];
	}
}
int main()
{
	printf("输入要处理的作业数\n");
	scanf("%d",&n);
	printf("输入每项作业在一号和二号机处理时间\n");
	for(int i=1;i<=n;i++)
		scanf("%d %d",&m[i][0],&m[i][1]);
	for(int i=1;i<=n;i++)
		temp[i]=i;
	dg(1);
	printf("最少花费总时间为：%d\n",bestv);
	printf("调度策略为：\n");
	for(int i=1;i<=n;i++)
		printf("%d ",best[i]);
	return 0;
} 
