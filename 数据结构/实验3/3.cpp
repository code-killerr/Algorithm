#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
typedef struct link
{
    char num[20];
	float grade[5];
    int ID;//Ԫ��λ��
    link *next;
};

int flag=0;
link *head;//��������ͷ
char project[10][20]={("�����ԭ��"),("���ݽṹ"),("���ֵ�·"),("Ӣ��"),("jsp")};


link *crate(int mark)
{
    link *data=NULL;//��ʼ������ͷ
    data=(link *)malloc(sizeof(link));//ǿ��ת��Ϊlink���Ͳ����ٿռ�
    if(mark)
        data->next=NULL;
    else data->next=head;
    data->ID=-1;//��ʼ��ѧ��λ��
    return data;
}


link *add(link *p,int mark)
{
    link *data=NULL;//��ʼ���ڵ�
    data=(link *)malloc(sizeof(link));
    if(mark)
        data->next=NULL;
    else data->next=p->next;//��ʼ���ڵ�ӿ�
    data->ID=p->ID;//�ṹ�����ó�Ա������->���ṹ��ָ�벻�У�����->
    p->next=data;//->��ʾֱ�Ӵ�ָ��ָ��ĵ�ַ��ȡ����Ա������Ҫ*ת��
    return data;
}


void Add_Message(link *data,int mark)
{
    int i=0,k=0,choose=0,code=0;//��ʼ��
	char check=0;
	printf("������ѧ��");
    while((check=getchar())!=EOF)//����Ƿ��������
	{
	    i=0;//��ʼ��¼���ַ�
        if(flag==0)
        {
            data=crate(mark);//head��¼����ͷ��ַ���ж��Ƿ����
            head=data;//��¼ͷ���
            flag++;
       }
       else
           data=add(data,mark);//���ӽڵ㲢�ж��Ƿ����
		data->num[i]=check;//¼��ѧ��
		for(i=1;i<20;)
		{
			if((data->num[i]=getchar())=='\n')
               {
                   data->num[i]='\0';
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
			scanf("%f",&data->grade[i]);//¼��ɼ�
		}
		if(mark)
		{
		    getchar();//��ֹ¼��س�Ӱ���������¼��
            ++data->ID;
            printf("�������%d��ѧ��ѧ��(EOF��������):",data->ID+2);
		}
        else
            break;
    }
}


int Insert_List(int insert)
{
    link *data;
    data=head;
	while(data!=NULL)
	{
	    if(insert==1)//����Ƿ��������ͷ
	    {
	        flag=0;
	        Add_Message(data,0);
	        data=head;
	        while(data!=NULL)
                {
                    data->ID++;//��ִ�в�����������һ���ڵ�
                    data=data->next;
                }
            return 1;
	    }
	    else if((data->ID+2)==insert)
        {
            Add_Message(data,0);//�ڶ�������Ϊ0����������
            while(data->next!=NULL)
                {
                    data=data->next;//�����ӽڵ��ٽ��в���
                    data->ID++;//ע����������ڲ���ǰ�Ͳ����������
                }
            return 1;
        }
        data=data->next;
	}
        return 0;
}


int Delete_List(int del)
{
    link *data;
    data=head;
    while(data!=NULL)
    {
        if(del==1)
            {
                head=data->next;
                while(data!=NULL)
                {
                    data->ID--;
                    data=data->next;
                }
                return 1;;
            }
        if((data->ID-2)==del)
        {
            data->next=(data->next)->next;
             while(data->next!=NULL)
                {
                    data=data->next;
                    data->ID--;
                }
                return 1;

        }
        data=data->next;
    }
    return 0;
}


void Check()
{
    link *data;
    data=head;
	while(data!=NULL)
	{
	    printf("%s\n",data->num);
         for(int j=0;j<5;j++)
            printf("%f\n",data->grade[j]);
        printf("%d\n",data->ID);
        data=data->next;
	}
}


main()
{
    int i=0,k=0,choose=-1,code=0;
    link *data;//��ʼ��
    Add_Message(data,1);//�ڶ�������Ϊ1���������������ݲ���
	while(choose!=0)
    {
        printf("����������еĲ���:0.�˳��˵�1.����2.ɾ��3.����\n");
        scanf("%d",&choose);
        switch(choose)
        {
        case 1: printf("���������λ��:");
                scanf("%d",&k);
                code=Insert_List(k);
                if(code==0)
                    printf("����λ������\n");
                else if(code==1)
                    printf("����ɹ�\n");
                else printf("δ֪����\n");
                system("cls");
                break;
        case 2: printf("������Ҫɾ����Ϣ��ѧ��:");
                scanf("%d",&k);
                code=Delete_List(k);
                if(code=0)
                    printf("�����ڸ�ѧ��\n");
                else if(code=1)
                    printf("ɾ���ɹ�\n");
                else printf("δ֪����\n");
                system("cls");
                break;
        case 3: //code=Back_List(k);
                if(code==-1)
                    printf("����ʧ��\n");
                else printf("����ɹ�\n",code);
                system("cls");
                break;
        //case 4:break;
        //case 5:break;
        }
    }
	//Check();
}
