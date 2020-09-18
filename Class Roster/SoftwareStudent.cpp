#include<iostream>
#include"SoftwareStudent.h"
using std::cout;

SoftwareStudent::SoftwareStudent() :Student()
{
	dtype = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], Degree dtype)
	: Student(studentID, firstName, lastName, emailAddress, age, days)
{
	dtype = SOFTWARE;
}

Degree SoftwareStudent::getdtype()
{
	return SOFTWARE;
}

void SoftwareStudent::print()
{
	this->Student::print();
	cout << "SOFTWARE" << "\n";
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
}