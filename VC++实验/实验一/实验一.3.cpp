#include<iostream>
using namespace std;
class CBook{
private: 
		int quantity;
		int price;
public:
	Student(char number[],char name[],float grade);
	void Show();
};
Student::Student(char number[],char name[],float grade)
{
	int i = 0;
	for(i = 0;number[i]!='\0';i++)studentNumber[i] = number[i];
	studentNumber[i] = '\0';
	for(i = 0;number[i]!='\0';i++)studentName[i] = name[i];
	studentGrade = grade;
	allStudentNumber++;
	allGrade += grade;
}

void Student::Show()
{
	cout << studentNumber << " " << studentName << " " << studentGrade<<endl;
} 

int main()
{
	Student a[5]={Student("P31223331","���",78),Student("P31223331","���",78),Student("P31223331","���",78),Student("P31223331","���",78),Student("P31223331","���",78)};
	for(int i = 0 ;i<5;i++)
		a[i].Show();
	cout << "�ܹ���:" << allStudentNumber << "��ѧ��" << endl;
	cout << "�ܳɼ�Ϊ" << allGrade << endl;
	getchar();
	return 0;
}