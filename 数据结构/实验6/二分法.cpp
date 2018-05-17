#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
class Search{
private:
	int a[100];
	int len;
public:
	int Search1(int key);
	int Search2();
	void print();
	Search();
};
Search::Search(){
	len = 0;
	for(int i=0;i<100;i++)
	{
		//srand(time(NULL));
		//a[i] = 1+(rand()%10000);
		a[i]=i;
		len++;
	}
}
void Search::print(){
	for (int i=0;i<100;i++ )
	{
		cout<<a[i];
	}
}
int Search::Search1(int key){
	int high = len;
	int low = 0;
	int flag=-1,mid;
	while(low<=high){
		mid = (low+high)/2;
		cout<<mid;
		cout<<" ";
		if(key<a[mid])
			high = mid;
		else if(key>a[mid])
			low = mid;
		else if(key == a[mid]){
			flag = mid;
			return flag;
		}
	}

}
int main(){
	int answer;
	Search list;
	list.print();
	answer = list.Search1(55);
	if(answer!=-1)
		cout<<"查找不到";
	else cout<<"查找的数据是第:"+answer;
	getchar();
	return 0;
}