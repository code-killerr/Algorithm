#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
main()
{
        printf("一小时重启倒计时开始");
        Sleep(3600000);
        printf("开始重启team\nloading...\n");
        system("taskkill /f /im steam.exe");
        ShellExecute(0,"open","D:\\steam\\steam\\Steam.exe",0,0,1);
        printf("\n重启完成....");
}
