#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define SIZE 100
typedef struct {
	char num[20];
	float grade[5];
    int ID;//Ԫ��λ��
}stu;
stu student[SIZE];//�������ݿռ�
int last=-1;//���Ԫ��λ�ó�ʼ��
char project[10][20]={("�����ԭ��"),("���ݽṹ"),("���ֵ�·"),("Ӣ��"),("jsp")};
int Insert_List(int insert)
{
    int j=last;
    if(last==SIZE-1)//���ռ�
        return -1;//����-1����
    if(insert<1||insert>(last+2))//������λ��
        return 0;//����0����
    for(j;j>=insert-1;j--)
    {
        student[j+1]=student[j];
        ++student[j+1].ID;
    }
    getchar();
    printf("���������ѧ��ѧ��:");
    for(int i=0;i<20;)
    {
        if((student[insert-1].num[i]=getchar())=='\n')//����������
        {
            student[insert-1].num[i]='\0';
            break;
        }
               ++i;
        if(i>20)
        {
            printf("ѧ�Ŵ�С�������ƣ���������ѧ��");//����Ƿ񳬳�����
            i=0;
        }
    }
    for(int i=0;i<5;i++)
    {
        printf("%s:",project[i]);
        scanf("%f",&student[insert-1].grade[i]);//¼��ɼ�
    }
    student[insert-1].ID=student[insert-2].ID+1;
    last++;
    return 1;
}
int Delete_List(int del)
{
    if(del<1||del>last+1)
        return 0;//���ش������
    for(int j=del;j<=last+1;j++)
    {
        student[j-1]=student[j];
        --student[j-1].ID;
    }
    --last;
    return 1;
}
int Search_List(int sea)
{
    int i;
    for(i=0;i<=last&&student[i].ID!=sea;i++);
    if(i>last)
        return -1;
    else
        return i;
}
main()
{
	int i=0,k=0,choose=0,code=0;//��ʼ��
	char check=0;
    student[0].ID=-1;//��ʼ���ṹ��
	printf("������ѧ��");
	while((check=getchar())!=EOF)//����Ƿ��������
	{
	    i=0;//��ʼ��¼���ַ�
	    ++last;//¼���һ��
		student[last].num[i]=check;//¼��ѧ��
		for(i=1;i<20;)
		{
			if((student[last].num[i]=getchar())=='\n')
               {
                   student[last].num[i]='\0';
                    break;
               }
			++i;
			if(i>20)
			{
				printf("ѧ�Ŵ�С�������ƣ���������ѧ��");//����Ƿ񳬳�����
				i=0;
			}

		}
		for(i=0;i<5;i++)
		{
			printf("%s:",project[i]);
			scanf("%f",&student[last].grade[i]);//¼��ɼ�
		}
		getchar();
		if(student[last].ID==-1)
            ++student[last].ID;
        else
            student[last].ID=student[last-1].ID+1;
		printf("�������%d��ѧ��ѧ��(EOF��������):",last+2);

	}
	printf("����������еĲ���:1.����2.ɾ��3.����4.����\n");
		scanf("%d",&choose);
	switch(choose)
	{
	case 1: printf("���������λ��:");
            scanf("%d",&k);
            code=Insert_List(k);
            if(code==-1)
                printf("�ռ������޷�����");
            else if(code==0)
                printf("����λ������");
            else if(code==1)
                printf("����ɹ�");
            else printf("δ֪����");
            break;
	case 2: printf("������Ҫɾ����Ϣ��ѧ��:");
            scanf("%d",&k);
            code=Delete_List(k);
            if(code=0)
                printf("�����ڸ�ѧ��");
            else if(code=1)
                printf("ɾ���ɹ�");
            else printf("δ֪����");
            break;
	case 3: printf("������Ҫ���ҵ�ѧ��ID:");
            scanf("%d",&k);
            code=Search_List(k);
            if(code==-1)
                printf("����ʧ��");
            else printf("ӵ��IDΪ%d��ѧ��",code);
            break;
	//case 4:break;
	//case 5:break;
	}
	_getch();
	//for(i=0;i<=last;i++)
	//{
	//    printf("%s\n",student[i].num);
    //     for(int j=0;j<5;j++)
    //        printf("%f\n",student[i].grade[j]);
    //    printf("%d\n",student[i].ID);
	//}
}
