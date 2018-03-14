#include<stdio.h>
#include<math.h>
main()
{
	int a,b,c,d[10],i=2,j,k,l,m=1,n;
	scanf("%d",&n);
    for(i;i<=n;i++)
	{
	    k=(int)sqrt(i);
		for(j=2;j<=k;j++)
		{
			if(i%j==0)
			break;
		}
		if(j>=k+1)
		{
			a=-1;
			b=i;
			while(b)
			{
				b=b/10;
				a++; 
			}
			b=a;
			m=1;
			//printf("*%d ",b);
			if(i>=10)
			{
				while(b)
				{
				//检测是否有0 算法待定 
					c=i%(int)pow(10,b);
					b=b-1;
					if(c<10)
					{
			            if(c==2||c==5||c==7||c==3)
							{d[m]=1;m++;}
						else
						  { d[m]=0;m++;}
					}
					else
					{
					  if(c%5!=0&&c%2!=0&&c%3!=0&&c%7!=0)
					  	{d[m]=1;m++;}
					  else
					    { d[m]=0;m++;}
					} 
			    }
			    b=1;
				for(c=1;c<m;c++)
			    {
					if(d[c]==0)
					b=0;
				}
				if(b)
				   printf("%d ",i);
		    }
		    else
		      if(i%5!=0||i%2!=0||c%3!=0||c%7!=0)
		          printf("%d ",i);
		}
	}
}
