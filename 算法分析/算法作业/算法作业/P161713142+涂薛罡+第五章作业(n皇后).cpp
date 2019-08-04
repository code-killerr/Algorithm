#include<stdio.h>
#define n 8
int qu[10],z[20],f[20],l[10],sum;
void calc(int x)
{
	if(x==n){
		sum++;
		return ;
	}
	for(int i=0;i<n;i++){
		if(!l[i]&&!f[i+x]&&!z[n+x-i]){
			l[i]=f[i+x]=z[n+x-i]=1;
			calc(x+1);
			l[i]=f[i+x]=z[n+x-i]=0;
		}
	}
}
int main()
{
	calc(0);
	printf("%d皇后解的个数为：%d\n",n,sum);
	return 0;
}
