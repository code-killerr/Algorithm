#include<iostream>
#include<string.h>
using namespace std;
class CStudent{
private:
	char sName[5];
	int sNumber;
	float sGrade;
public:
	CStudent() {}
	CStudent(const char name[],int number,float grade){
		strcpy((*this).sName, name);
		(*this).sNumber = number;
		(*this).sGrade = grade;
	}
	void print() {
		cout << "姓名:" << sName << "学号:" << sNumber << "成绩:" << sGrade << endl;
	}
	friend ostream& operator<<(ostream& os, CStudent& stu) {
		os.write(stu.sName, 5);
		os.write((char*)&stu.sNumber, 4);
		os.write((char*)&stu.sGrade, 4);
		return os;
	}
	friend istream& operator>>(istream& is, CStudent& stu) {
		char name[5];
		is.read(name, 5);
		is.read((char*)&stu.sNumber, 4);
		is.read((char*)&stu.sGrade, 4);
		strcpy(stu.sName, name);
		return is;
	}
};
