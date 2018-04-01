#include<stdio.h>
#include<stdlib.h>
int flag=0;
typedef struct link
{
    char num[20];
	float grade[5];
    int ID;//元素位置
    link *next;
};
link crate()
{
    link *data=NULL;
    data=(link *)malloc(sizeof(link));//强制转换为link类型并开辟空间


}
main()
{


}
