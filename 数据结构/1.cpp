#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stu{
	char num[20];
	float grade[5];

}student[100];
char *project[10]={"�����ԭ��","���ݽṹ","���ֵ�·","Ӣ��","jsp"};
float array()
{
	int j,i;
	float sum=0;
	printf("ѡ����Ҫ�鿴��ѧ��:");
	scanf("%d",&i);
	for(j=0;j<5;j++)
		sum+=student[i-1].grade[j];
	return sum/5.0;

}
void Project_Array(int num)
{
	int i,j;
	float sum=0;
	printf("ѡ����Ҫ�鿴��Ŀ��ƽ����1.�����ԭ��,2.���ݽṹ,3.���ֵ�·,4.Ӣ��,5.jsp");
	scanf("%d",&j);
	for(i=0;i<num;i++)
		sum+=student[i].grade[j-1];
	printf("%s��ƽ����Ϊ%f",project[j],sum/num);
}
main()
{
	int i=0,j=0,k=0,choose;
	char check;

	printf("������ѧ��");
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
				printf("ѧ�Ŵ�С�������ƣ���������ѧ��");
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
		printf("�������%d��ѧ��ѧ��(EOF��������):",j+1);

	}
	printf("����������еĲ���:1.��ѧ������ƽ��ֵ2.��ȫ�����Ƴɼ�ƽ��ֵ\n");
		scanf("%d",&choose);
	switch(choose)
	{
	case 1:printf("��ѧ��ƽ���ɼ�Ϊ:%f",array());break;
	case 2:Project_Array(j);break;
	}
}
