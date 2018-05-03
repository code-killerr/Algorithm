#include<string.h>
#include<stdio.h>
#include<Windows.h>
int main()
{
	int i=0,flag=0;
	char a[100];
	while((a[i]=getchar())!='\n')
		i++;
	a[i]='\0';
	for(i=0;i<(strlen(a)/2);i++)
		if(a[i]!=a[strlen(a)-i-1])
			{
				flag=1;
				break;
			}
	if( flag==0)
		printf("that's right");
	else printf("false");
	system("pause");
	return 0;
}