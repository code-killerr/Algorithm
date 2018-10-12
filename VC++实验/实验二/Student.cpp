#include"student.h"
#include<fstream>
int main() {
	CStudent stu1("小a",23444123,79);
	CStudent stu2("小B",432423532423,99);
    CStudent stu3("小C",324234234,87.8);
    CStudent stu4("小D",324234234,87.8);
    CStudent stu5("小E",324234234,87.8);
	fstream file1;
	file1.open("student.dat",ios::in|ios::out|ios::binary);
	file1 << stu1<<stu2<<stu3<<stu4<<stu5;
	CStudent* one = new CStudent("",0,0);
	const int size = 13;
	file1.seekp(0);
	file1>>*one;
	one->print();//seekp：设置输出文件流的文件流指针位置seekg：设置输入文件流的文件流指针位置
	return 0;
}
