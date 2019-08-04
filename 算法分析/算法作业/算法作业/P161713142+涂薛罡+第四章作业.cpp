#include<stdio.h>
#include<algorithm>
using namespace std;
#define maxN 1000
int p[2],v[maxN],n,sum;
int main()
{
	printf("输入两艘船的载重\n");
	scanf("%d %d",&p[0],&p[1]);
	printf("输入物品数量\n");
	scanf("%d",&n);
	printf("输入每件物品的重量\n");
	for(int i=0;i<n;i++)
		scanf("%d",&v[i]);
	sort(v,v+n);
	for(int i=0;i<n;i++){
		if(p[0]>v[i]){
			p[0]-=v[i];
			sum++;
		}
		else if(p[1]>v[i]){
			p[0]-=v[i];
			sum++;
		}
	}
	printf("最大容纳个数为：%d\n",sum);
	printf("不一定产生最优解\n");
	return 0;
}
