#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
void swap(int num[],int index1,int index2){
	int key = num[index1];
	num[index1] = num[index2];
	num[index2] = key;
}
void Sort(int num[])
{
	int length=0;
	for(length;num[length]!=0;length++);
    for(int i = 1;i < length;i++)
    {
		for(int j = i; num[j-1]!=0 ; j-- )
		{
			if(num[j] < num[j-1]){
				swap(num,j,j-1);
			}
		}
    }

}
void Show(int num[]){
	for(int i = 0 ; num[i] != 0 ; i++ )
	 cout<<num[i]<<" ";
	cout<<"\n";
}
int main()
{
    int Data[]={23,41,23,545,1,213,512,33,5,8,98,885,0};
	Show(Data);
    Sort(Data);
	Show(Data);
	getchar();
    return 0;
}
