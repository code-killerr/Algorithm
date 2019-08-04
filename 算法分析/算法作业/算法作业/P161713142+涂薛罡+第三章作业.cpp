#include<stdio.h>
#define maxN 1000
#define INF 0x3f3f3f3f
char p[maxN];
int n,v[maxN],m[maxN][maxN][2],max,min;
void calc(int j,int i,int k){
	int data[2][2];
	data[0][0]=m[i][k][0];
	data[0][1]=m[i][k][1];
	int t=(i+j-1)%n+1;
	data[1][0]=m[t][j-k][0];
	data[1][1]=m[t][j-k][1];
	if(p[t]=='*'){
		min=INF;max=-INF;
		for(int i1=0;i1<2;i1++)
			for(int j1=0;j1<2;j1++){
				if(data[0][i1]*data[1][j1]>max) max=data[0][i1]*data[1][j1];
				if(data[0][i1]*data[1][j1]<min) min=data[0][i1]*data[1][j1];
			}
	}
	else{
		max=data[0][1]+data[1][1];
		min=data[0][0]+data[1][0];
	}
}
int getMax()
{
	for(int j=2;j<=n;j++){
		for(int i=1;i<=n;i++){
			for(int k=1;k<j;k++){
				calc(j,i,k);
				m[i][j][0]=min;
				m[i][j][1]=max;
			}
		}
	}
	max = m[1][n][1];
	for(int i=2;i<=n;i++)
		if(m[i][n][1]>max) max=m[i][n][1];
	return max;
}
int main()
{
	printf("输入点的个数\n");
	scanf("%d",&n);
	printf("输入边的符号以及点的值\n");
	for(int i=1;i<=n;i++){
		getchar();
		scanf("%c %d",&p[i],&v[i]);
		m[i][1][0]=m[i][1][1]=v[i];
	}
	int ans=getMax();
	printf("最大值为:%d\n",ans);
	return 0;
}
