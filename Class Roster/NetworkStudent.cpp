#include<iostream>
#include"NetworkStudent.h"
using std::cout;

NetworkStudent::NetworkStudent():Student()
{
	dtype = NETWORKING;
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], Degree dtype)
	:Student(studentID, firstName, lastName, emailAddress, age, days)
{
	dtype = NETWORKING;
}

Degree NetworkStudent::getdtype()
{
	return NETWORKING;
}

void NetworkStudent::print()
{
	this->Student::print();
	cout << "NETWORK" << "\n";
}

NetworkStudent::~NetworkStudent()
{
	Student::~Student();
}