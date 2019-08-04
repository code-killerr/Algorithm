#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;

const int fenjie[7] = {0,3000,12000,25000,35000,55000,80000};
const float money[7] = {0.03,0.1,0.2,0.25,0.3,0.35,0.45};
double moneyList[7] = {0,
                    3000*0.03,
                    round((12000-3000)*0.1+moneyList[1]),
                    round((25000-12000)*0.2+moneyList[2]),
                    round((35000 - 25000)*0.25+moneyList[3]),
                    round((55000 - 35000)*0.3 + moneyList[4]),
                    round((80000 - 55000)*0.35 + moneyList[5])};
int search(int sale){
    int left = 0 , right = 6 , mid = 0;
		while(left < right-1)
		{
			mid = (left+right)/2;
			if(sale < fenjie[mid])
                right = mid;
			else
                left = mid;
		}
		return left;
}

double judge(int sale){
    int weizhi=0;
    sale -= 5000;
    if(sale < 0){
        return 0;
    }
    if(sale > 80000){
        return round(moneyList[6]+(sale - 80000)*0.45);
    }
    weizhi = search(sale);
    return round(moneyList[weizhi]+(sale-fenjie[weizhi])*money[weizhi]);

}



int main(){
    for(int i = 0;i<7;i++)
        cout << moneyList[i]<<endl;
    int sale = 0,num = 0;
    int result[100] = {0};
    float submit = 0;
    cin >> num;
    for(int i=0;i<num;i++){
        cin >> sale;
        result[i] = (int)judge(sale);
    }
    for(int i = 0;i<num;i++)
        cout << result[i] <<endl;
    return 0;
}
