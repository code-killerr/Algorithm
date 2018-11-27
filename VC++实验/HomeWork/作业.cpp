#include<iostream>
#include<math.h>
using namespace std;
class Trangle{
    private:
        float lSide;
        float rSide;
        float bottom;
    public:
        Trangle()
        {}
        Trangle(float left,float right,float bottom)
        {
            (*this).lSide = left;
            (*this).rSide = right;
            (*this).bottom = bottom;
        }
        void setLSide(float data)
        {
            (*this).lSide = data;
        }
        void setRSide(float data)
        {
            (*this).rSide = data;
        }
        void setBottom(float data)
        {
            (*this).bottom = data;
        }
        float area()
        {
            if(lSide + rSide < bottom||bottom + lSide < rSide||bottom + rSide <lSide)
                return 0;
            else
                return sqrt( 4*pow(lSide,2)*pow(bottom,2) - pow((pow(lSide,2) + pow(bottom,2) - pow(rSide,2)) , 2) )/4;
        }
};

float sum(float **data)//两边对角线相加
{
    float sum = 0;
    for(int i = 0;i < 4;i++)
        sum += data[i][i]+data[i][3-i];
    return sum;
}
int main(){
    float a = 0,b = 0,c = 0;
    cin >> a >> b >> c;
    Trangle t1(a,b,c);
    cout<<t1.area();
    return 0;
}
