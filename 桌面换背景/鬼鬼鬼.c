#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
main()
{
	int a,i,b;
	int beijing[100];
	int mp3[100];
	srand(time(NULL));
	ShellExecute(0,"open","1.mp3",0,0,0);
	Sleep(500);
	for(i=0;i<=2;i++)
	{
	    a=1+(rand()%6);
	    b=2+(rand()%4);
		sprintf(mp3,"%d.mp3",b);
		sprintf(beijing,"%d.jpg",a);
	    SystemParametersInfoA(20,0,beijing,3);
	    ShellExecute(0,"open",mp3,0,0,0);
	    Sleep(4000);
	    
    }
    SystemParametersInfoA(20,0,"C:\\Windows\\Web\\Wallpaper\\Windows\\img0.jpg",3);
}
