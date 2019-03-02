#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

class Student{
public:
	int semesterHours;
	double gpa;
};

void someFn(Student* student);

int main(int nARGS, char* ARGS[]){
	Student s;
	cout<<"Calling someFn()"<<endl;
	someFn(&s);
	cout<<"semester hours: "<<s.semesterHours<<endl;
	cout<<"GPA: "<<s.gpa;

	return 0;
}

void someFn(Student* student){
	student->semesterHours = 10;
	student->gpa = 4.0;
	return;
}