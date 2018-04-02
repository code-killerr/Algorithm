#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
    char num[20];
	float grade[5];
    int ID;//元素位置
    link *next;
};

int flag=0;
link head;//定义链表头
char project[10][20]={("计算机原理"),("数据结构"),("数字电路"),("英语"),("jsp")};


link crate()
{
    link *data=NULL;//初始化链表头
    data=(link *)malloc(sizeof(link));//强制转换为link类型并开辟空间
    return *data;
}


link add(link p)
{
    link *data=NULL;//初始化节点
    data=(link *)malloc(sizeof(link));
    //data.ID=p.ID;
    //p.next=data;
    return *data;
}


main()
{
    int i=0,k=0,choose=0,code=0;//初始化
	char check=0;
	link data;
	printf("请输入学号");
	while((check=getchar())!=EOF)//检测是否输入完毕
	{
	    i=0;//初始化录入字符
        if(flag==0)
        {
            head=crate();
            head.ID=-1;//初始化学生位置
            data=head;
            flag++;
       }
       else
           data=add(data);
		data.num[i]=check;//录入学号
		for(i=1;i<20;)
		{
			if((data.num[i]=getchar())=='\n')
               {
                   data.num[i]='\0';
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
			scanf("%f",&data.grade[i]);//录入成绩
		}
		getchar();
		if(data.ID==-1)
            ++data.ID;
		printf("请输入第%d个学生学号(EOF结束输入):",data.ID);

	}
	printf("输入您想进行的操作:1.插入2.删除3.查找4.划分\n");
		scanf("%d",&choose);
	switch(choose)
	{
	case 1: printf("请输入插入位置:");
            scanf("%d",&k);
            //code=Insert_List(k);
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
            //code=Delete_List(k);
            if(code=0)
                printf("不存在该学生");
            else if(code=1)
                printf("删除成功");
            else printf("未知错误");
            break;
	case 3: printf("输入需要查找的学生ID:");
            scanf("%d",&k);
            //code=Search_List(k);
            if(code==-1)
                printf("查找失败");
            else printf("拥有ID为%d的学生",code);
            break;
	//case 4:break;
	//case 5:break;
	}
}
