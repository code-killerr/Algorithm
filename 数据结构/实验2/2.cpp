#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define SIZE 100
typedef struct {
	char num[20];
	float grade[5];
    int ID;//元素位置
}stu;
stu student[SIZE];//创建数据空间
int last=-1;//最后元素位置初始化
char project[10][20]={("计算机原理"),("数据结构"),("数字电路"),("英语"),("jsp")};
int Insert_List(int insert)
{
    int j=last;
    if(last==SIZE-1)//检查空间
        return -1;//返回-1错误
    if(insert<1||insert>(last+2))//检查插入位置
        return 0;//返回0错误
    for(j;j>=insert-1;j--)
    {
        student[j+1]=student[j];
        ++student[j+1].ID;
    }
    getchar();
    printf("请输入插入学生学号:");
    for(int i=0;i<20;)
    {
        if((student[insert-1].num[i]=getchar())=='\n')//检测输入结束
        {
            student[insert-1].num[i]='\0';
            break;
        }
               ++i;
        if(i>20)
        {
            printf("学号大小超出限制，重新输入学号");//检测是否超出限制
            i=0;
        }
    }
    for(int i=0;i<5;i++)
    {
        printf("%s:",project[i]);
        scanf("%f",&student[insert-1].grade[i]);//录入成绩
    }
    student[insert-1].ID=student[insert-2].ID+1;
    last++;
    return 1;
}
int Delete_List(int del)
{
    if(del<1||del>last+1)
        return 0;//返回错误代码
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
	int i=0,k=0,choose=0,code=0;//初始化
	char check=0;
    student[0].ID=-1;//初始化结构体
	printf("请输入学号");
	while((check=getchar())!=EOF)//检测是否输入完毕
	{
	    i=0;//初始化录入字符
	    ++last;//录入第一个
		student[last].num[i]=check;//录入学号
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
				printf("学号大小超出限制，重新输入学号");//检测是否超出限制
				i=0;
			}

		}
		for(i=0;i<5;i++)
		{
			printf("%s:",project[i]);
			scanf("%f",&student[last].grade[i]);//录入成绩
		}
		getchar();
		if(student[last].ID==-1)
            ++student[last].ID;
        else
            student[last].ID=student[last-1].ID+1;
		printf("请输入第%d个学生学号(EOF结束输入):",last+2);

	}
	printf("输入您想进行的操作:1.插入2.删除3.查找4.划分\n");
		scanf("%d",&choose);
	switch(choose)
	{
	case 1: printf("请输入插入位置:");
            scanf("%d",&k);
            code=Insert_List(k);
            if(code==-1)
                printf("空间已满无法插入");
            else if(code==0)
                printf("插入位置有误");
            else if(code==1)
                printf("插入成功");
            else printf("未知错误");
            break;
	case 2: printf("输入需要删除信息的学生:");
            scanf("%d",&k);
            code=Delete_List(k);
            if(code=0)
                printf("不存在该学生");
            else if(code=1)
                printf("删除成功");
            else printf("未知错误");
            break;
	case 3: printf("输入需要查找的学生ID:");
            scanf("%d",&k);
            code=Search_List(k);
            if(code==-1)
                printf("查找失败");
            else printf("拥有ID为%d的学生",code);
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
