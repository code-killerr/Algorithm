#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
void open()
{
	ShellExecute(0,"open","C:\\Program Files (x86)\\Tencent\\QQ\\Bin\\QQScLauncher.exe",0,0,1);
}

void mp3()
{
		ShellExecute(0,"open","7.mp3",0,0,0);
}


void move()
{
	int i;
	HWND win;
	win=FindWindowA("TXGuiFoundation","QQ");
	if(win==NULL)
	{
		printf("nothing");
	}
	else
	{
		printf("will do it");
		for(i=-100;i<=900;i=i+25)
		{
		    SetWindowPos(win,NULL,i,-100,300,400,1);
		    Sleep(10);
		}
		i=0;
		while(i<=450)
		{
			SetWindowPos(win,NULL,900,i,300,400,1);
			Sleep(10);
			i=i+25;
		}
		i=900;
		do
		{
			SetWindowPos(win,NULL,i,450,300,400,1);
			i=i-25;
			Sleep(10);
		}
		while(i>=-100);
		i=450;
		A1:if(i>=-100)
		{
			SetWindowPos(win,NULL,-100,i,300,400,1);
			i=i-25;
			Sleep(10);
			goto A1;
		}
		i=-100;
		int j=-100;
		for(i;i<=900;i=i+25)
		{
			j=j+11;
			SetWindowPos(win,NULL,i,j,300,400,1);
			Sleep(10);
		}
		i=900;
		j=440;
		for(i;i>=450;i=i-25)
		{
			j=j-11;
		    SetWindowPos(win,NULL,i,j,300,400,1);
		    Sleep(10);
		}
		
		
		for(i=0;i<=10;i++)
		{
			ShowWindow(win, SW_HIDE);
			Sleep(100);
			ShowWindow(win, SW_SHOW);
			Sleep(100);
		}
		
	}
}





void calc()
{
    MessageBox(NULL,"���ĵ������ж�","����",MB_OKCANCEL);
    MessageBox(0,"��ɶ��û��","����",0);
    MessageBox(0,"˵��û���㻹����","����",0);
    MessageBox(0,"������ô���ĸ��㽲������","����",0);
    MessageBox(0,"��ǰ����ɽ","����",0);
    MessageBox(0,"ɽ���и���","����",0);
    MessageBox(0,"����������","����",0);
    MessageBox(0,"���˲�������","����",0);
    A1:MessageBox(0,"���ľ���","����",0);
    int a=MessageBox(NULL,"��·���ҿ������������ԣ�ȷ���˲Ÿ�����","����",MB_OKCANCEL);
    if (a==IDOK)
    {
    	MessageBox(0,"���","����",0);
	}
    else
    {
    	MessageBox(0,"��ȷ�ϰɣ��ٺٺ�","����",0);
		goto A1; 
	}
	MessageBox(0,"������ôʵ�ϾͲ�������","����",0);
	MessageBox(0,"��ȥ��ȥ��","����",0);
	MessageBox(0,"��Щ���������˰�","����",0);
	int b;
	for(b=0;b<=20;b++)
	ShellExecute(0,"open","calc",0,0,0);
	
}



void close()
{
	system("taskkill /f /im QQ.exe");
}
void ccalc()
{
	system("taskkill /f /im calc.exe");
}


int main()
{
	open ();
	Sleep(7000);
	mp3();
	Sleep(1000);
    move();
    Sleep(1000);
    close();
    calc();
    Sleep(5000);
    ccalc();
 } 
