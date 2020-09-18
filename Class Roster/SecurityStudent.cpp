#include<iostream>
#include"SecurityStudent.h"
using std::cout;

SecurityStudent::SecurityStudent() :Student()
{
	dtype = SECURITY;
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], Degree dtype)
	: Student(studentID, firstName, lastName, emailAddress, age, days)
{
	dtype = SECURITY;
}

Degree SecurityStudent::getdtype()
{
	return SECURITY;
}

void SecurityStudent::print()
{
	this->Student::print();
	cout << "SECURITY" << "\n";
}

SecurityStudent::~SecurityStudent()
{
	Student::~Student();
}