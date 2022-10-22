#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
using namespace std;
template <typename T>
T add(T a,T b){return a+b;}//函数模板

int main(){
    std::vector<int> c;//c++中的向量数组
    c.push_back(10);//添加元素
    for(int i =0;i<10;i++)
        c.push_back(i);
    for(int i=0 ; i < c.size();i++)
        std::cout<<c[i]<<std::endl;//输出方法和c一致
    std::string s;//string类型声明
    s = "1231123";//赋值
    s +="aaaaaa";//字符串链接
    s == "aaaaaa";//字符串比较
	
	//输入输出流
	
	std::cout<<setfill('a')<<setw(10)<<"222"<<endl;
	//setfill可以设置setw中的填充，setw默认填充为空格，其可以设置下一个字符所占控件，endl为换行并清空流缓冲区
	std::cout<<hex<<23<<endl;//使用hex表示16进制输出，Oct为8进制输出，注意设置以后cout输出值均为该进制
	//cin进行输入操作，其忽略空格，回车和制表符
	
	//string类型
	
	//string可以使用+，=，==，<,>等进行连接，赋值，比较操作
	string str1 = "hello";
	string str2=str1;//str1赋值给str2
	std::cout<<(str1==str2)<<endl;//进行比较
	//string类型有多种初始化方式
	string str3("world");//等价string str3 = string("world")
	string str4(5,'g');//5个g初始化str4
	string str5 = str1+str3;
	std::cout << str5<<endl<<str4<<endl;//使用+进行字符串链接
	//使用size判断字符串长度
	std::cout<<dec<<str5.size()<<endl<<str5.empty()<<endl;//empty可以判空
    string str6 = "";
    getline(cin,str6);//可以进行读取一行数据
    //const char* p =str.c_str();方法可以获取string的头指针，其是const char类型
	//当空间不够时讲销毁以前空间新建更大的内存空间，指针将会失效
	
	//vector
	
	//vector为一个模板类，能够像容器一样存放对象，也是一个能够存放任意类型的动态数组
    return 0;
}
