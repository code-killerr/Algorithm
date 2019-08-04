#include<stdio.h>
#include<math.h>
#include<algorithm>
#define INF 1e10
#define maxN 100
using namespace std;
int n,qu1[maxN];
struct position{
	double x;
	double y;
}qu[maxN];
int cmpx(position x1,position x2){
	return x1.x<x2.x;
}
int cmpy(int x1,int x2){
	return qu[qu1[x1]].y<qu[qu1[x2]].y;
}
double calc(int x1,int x2){
	return sqrt(qu[x1].x*qu[x1].x+qu[x2].y+qu[x2].y);
}
double calculate(int l,int r){
	if(l>=r) return INF;
	int m=(l+r)>>1,cnt=0;
	double fmin=min(calculate(l,m),calculate(m+1,r));
	for(int i=m;i>=l;--i){
		if(qu[m].x-qu[i].x<fmin){
			qu1[cnt++]=i;
		}
		else break;
	}
	for(int i=m+1;i<=r;i++){
		if(qu[i].x-qu[m].x<fmin){
			qu1[cnt++]=i;
		}
		else break;
	}
	sort(qu1,qu1+cnt,cmpy);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(qu[qu1[j]].y-qu[qu1[i]].y<fmin)
				fmin=min(fmin,calc(qu1[i],qu1[j]));
			else break;
		}
	}
	return fmin;
}
int main()
{
	printf("输入点的个数\n");
	scanf("%d",&n);
	printf("输入点对的坐标值:\n");
	for(int i=0;i<n;i++)
		scanf("%lf %lf",&qu[i].x,&qu[i].y);
	sort(qu,qu+n,cmpx);
	printf("最小点对距离为：%.2lf\n",calculate(0,n-1));
	return 0;
}
