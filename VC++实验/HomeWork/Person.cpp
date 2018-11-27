#include<iostream>
#include<string.h>
class CPerson{
    private:
        char name[5];
        int number;
        char sex;
    public:
        CPerson(char *name,int number,char sex){
            strcpy((*this).name,name);
            (*this).number = number;
            (*this).sex = sex;
        }
        void print(){
            std::cout << "姓名:" << name << "编号:" << number << "性别:" <<sex;
        }

};
class CStudent : protected CPerson{
    CStudent(char *name,int number,char sex):CPerson(name,number,sex){

    }
};
class CTeacher : protected CPerson{
    CTeacher(char *name,int number,char sex):CPerson(name,number,sex){

    }
};
template<typename T1,typename T2>
T1 sum(T1 a,T2 b){
    return a+b;
}
int main(){
    std::cout << sum(1.2,2);//可以自动识别类型
    return 0;
}
