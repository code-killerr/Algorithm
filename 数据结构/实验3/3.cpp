#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
    char num[20];
	float grade[5];
    int ID;//Ԫ��λ��
    link *next;
};

int flag=0;
link head;//��������ͷ
char project[10][20]={("�����ԭ��"),("���ݽṹ"),("���ֵ�·"),("Ӣ��"),("jsp")};


link crate()
{
    link *data=NULL;//��ʼ������ͷ
    data=(link *)malloc(sizeof(link));//ǿ��ת��Ϊlink���Ͳ����ٿռ�
    return *data;
}


link add(link p)
{
    link *data=NULL;//��ʼ���ڵ�
    data=(link *)malloc(sizeof(link));
    //data.ID=p.ID;
    //p.next=data;
    return *data;
}


main()
{
    int i=0,k=0,choose=0,code=0;//��ʼ��
	char check=0;
	link data;
	printf("������ѧ��");
	while((check=getchar())!=EOF)//����Ƿ��������
	{
	    i=0;//��ʼ��¼���ַ�
        if(flag==0)
        {
            head=crate();
            head.ID=-1;//��ʼ��ѧ��λ��
            data=head;
            flag++;
       }
       else
           data=add(data);
		data.num[i]=check;//¼��ѧ��
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
				printf("ѧ�Ŵ�С�������ƣ���������ѧ��");//����Ƿ񳬳�����
				i=0;
			}

		}
		for(i=0;i<5;i++)
		{
			printf("%s:",project[i]);
			scanf("%f",&data.grade[i]);//¼��ɼ�
		}
		getchar();
		if(data.ID==-1)
            ++data.ID;
		printf("�������%d��ѧ��ѧ��(EOF��������):",data.ID);

	}
	printf("����������еĲ���:1.����2.ɾ��3.����4.����\n");
		scanf("%d",&choose);
	switch(choose)
	{
	case 1: printf("���������λ��:");
            scanf("%d",&k);
            //code=Insert_List(k);
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
            //code=Delete_List(k);
            if(code=0)
                printf("�����ڸ�ѧ��");
            else if(code=1)
                printf("ɾ���ɹ�");
            else printf("δ֪����");
            break;
	case 3: printf("������Ҫ���ҵ�ѧ��ID:");
            scanf("%d",&k);
            //code=Search_List(k);
            if(code==-1)
                printf("����ʧ��");
            else printf("ӵ��IDΪ%d��ѧ��",code);
            break;
	//case 4:break;
	//case 5:break;
	}
}
