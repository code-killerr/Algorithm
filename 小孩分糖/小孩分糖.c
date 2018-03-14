#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
	int l,h[10000],i,j=0,k[100],a,b[100],n;
	char c;
	srand(time(NULL));
	printf("几个小盆友:");
	scanf("%d",&n);
	printf("\n选择自己手动输入给每个小盆友的糖果还是随机\n手动s随机r回车结束程序");
	A3:scanf("%c",&c);
	scanf("%c",&c);
	if(c=='r'||c=='\n'||c=='s')
	{
		if(c=='r')
		{
			for(i=0;i<n;i++)
			{
				b[i]=((rand()%1000)+1);
				printf("%d ",b[i]);
			}
	    }
	    if(c=='s')
	    {
	    	for(i=0;i<n;i++)
			{
			    scanf("%d",&b[i]);
			}
		}
    }
	else 
	{
		printf("请输入正确的指令"); 
		goto A3;
	}
	printf("\n");
		for(i=0;i<n;i++)
	{
		for(l=1;l<n;l++)
		if(b[i]!=b[l])
		h[i]=1;
		else
		h[i]=0;
	}
	for(i=0;i<n;i++)
	{
		for(l=1;l<n;l++)
		{
		if(h[i]!=h[l])
		goto A1;
		}
		if(h[i]==0)
		goto A2;
	}
    A1:for(i=0;i<n;i++)
	{
		if(b[i]%2!=0)
		{
			b[i]=b[i]+1;
			j=j+1;
		}
	}
	for(i=0;i<n;i++)
	{
		k[i]=b[i]/2; 
	}
	for(i=1;i<n;i++)
	{
		b[i]=k[i]+k[i-1];
	}
	b[0]=k[n-1]+k[0];
	for(i=0;i<n-1;i++)
	{
		if(b[i]!=b[i+1])
		  goto A1;
	}
	printf("每个小盆友有%d个糖",b[0]);
	A2:printf("要再加%d个糖",j);
	
}
