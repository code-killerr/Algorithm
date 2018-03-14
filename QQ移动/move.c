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
    MessageBox(NULL,"您的电脑已中毒","警告",MB_OKCANCEL);
    MessageBox(0,"按啥都没用","警告",0);
    MessageBox(0,"说了没用你还不信","警告",0);
    MessageBox(0,"看你这么无聊给你讲个故事","警告",0);
    MessageBox(0,"从前有座山","警告",0);
    MessageBox(0,"山上有个庙","警告",0);
    MessageBox(0,"庙里俩和尚","警告",0);
    MessageBox(0,"算了不逗你了","警告",0);
    A1:MessageBox(0,"最后的抉择","警告",0);
    int a=MessageBox(NULL,"此路是我开，此树是我栽，确认了才给放行","警告",MB_OKCANCEL);
    if (a==IDOK)
    {
    	MessageBox(0,"你好","警告",0);
	}
    else
    {
    	MessageBox(0,"快确认吧，嘿嘿嘿","警告",0);
		goto A1; 
	}
	MessageBox(0,"看你这么实诚就不逗你了","警告",0);
	MessageBox(0,"该去哪去哪","警告",0);
	MessageBox(0,"这些玩意送你了啊","警告",0);
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
