#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
class CBook{
private:
		int quantity;
		int price;
public:
	CBook(int data);
	void Show();
};
CBook::CBook(int data)
{
	quantity = data;
	price = quantity*10;
}

void CBook::Show()
{
	cout << "quantity*priceµÄÖµÊÇ:" << quantity*price<<endl;
}

int main()
{
	CBook a[5]={CBook(25),CBook(34),CBook(12),CBook(37),CBook(88)};
	for(int i = 0 ;i<5;i++)
		a[i].Show();
    CBook *p;
    p = a;
    for(int i = 4;i >= 0;i--)
        (*(p+i)+).Show();

	getchar();
	return 0;
}
