#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
main()
{
        printf("һСʱ��������ʱ��ʼ");
        Sleep(3600000);
        printf("��ʼ����team\nloading...\n");
        system("taskkill /f /im steam.exe");
        ShellExecute(0,"open","D:\\steam\\steam\\Steam.exe",0,0,1);
        printf("\n�������....");
}
