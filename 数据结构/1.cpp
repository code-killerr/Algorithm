#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stu{
	char num[20];
	float grade[5];

}student[100];
char *project[10]={"计算机原理","数据结构","数字电路","英语","jsp"};
float array()
{
	int j,i;
	float sum=0;
	printf("选择需要查看的学生:");
	scanf("%d",&i);
	for(j=0;j<5;j++)
		sum+=student[i-1].grade[j];
	return sum/5.0;

}
void Project_Array(int num)
{
	int i,j;
	float sum=0;
	printf("选择需要查看科目的平均分1.计算机原理,2.数据结构,3.数字电路,4.英语,5.jsp");
	scanf("%d",&j);
	for(i=0;i<num;i++)
		sum+=student[i].grade[j-1];
	printf("%s的平均分为%f",project[j],sum/num);
}
main()
{
	int i=0,j=0,k=0,choose;
	char check;

	printf("请输入学号");
	while((check=getchar())!=EOF)
	{
		student[j].num[i]=check;
		++i;
		for(i;i<20;)
		{
			if((student[j].num[i]=getchar())=='\n')
				break;
			++i;
			if(i>19)
			{
				printf("学号大小超出限制，重新输入学号");
				i=0;
			}

		}
		for(k=0;k<5;k++)
		{
			printf("%s:",project[k]);
			scanf("%f",&student[j].grade[k]);
		}
		getchar();
		++j;
		printf("请输入第%d个学生学号(EOF结束输入):",j+1);

	}
	printf("输入您想进行的操作:1.求学生各科平均值2.求全部各科成绩平均值\n");
		scanf("%d",&choose);
	switch(choose)
	{
	case 1:printf("该学生平均成绩为:%f",array());break;
	case 2:Project_Array(j);break;
	}
}
