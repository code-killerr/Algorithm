#include<iostream>
#define pi 3.1415926
using namespace std;
class CBase
{
    public:
        virtual float GetArea()
        {
            return 0;
        }
};
class CCricle :private CBase
{
    protected:
        float radius;
    public:
        CCricle(float rad)
        {
            radius = rad;
        }
        float GetArea()
        {
            return pi*radius*radius;
        }
        float Perimeter()
        {
            return pi*2*radius;
        }
};
class CCylinder:protected CCricle
{
    private:
        float hight;
    public:
        CCylinder(float h,float r):CCricle(r)
        {
            hight = h;
        }
        float GetArea()
        {
            return CCricle::GetArea()*2+CCricle::Perimeter()*hight;
        }
        float GetVol()
        {
            return CCricle::GetArea()*hight;
        }

};
int main()
{
    CCylinder Data(5,4.5);
    cout <<"面积是:"<<Data.GetArea() <<" 体积是" << Data.GetVol()<<endl;
    return 0;
}
