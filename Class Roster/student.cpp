#include <iostream>
#include <iomanip>
#include "student.h"
using std::cout;
using std::left;
using std::setw;

Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < numberOfDays; i++) this->days[i] = 0;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[])
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < numberOfDays; i++) this->days[i] = days[i];
}

string Student::getstudentID()
{
	return studentID;
}
string Student::getfirstName()
{
	return firstName;
}
string Student::getlastName()
{
	return lastName;
}
string Student::getemailAddress()
{
	return emailAddress;
}
int Student::getage()
{
	return age;
}
int* Student::getdays()
{
	return days;
}
void Student::setstudentID(string studentID)
{
	this->studentID = studentID;
}
void Student::setfirstName(string firstName)
{
	this->firstName = firstName;
}
void Student::setlastName(string lastName)
{
	this->lastName = lastName;
}
void Student::setemailAddress(string emailAddress)
{
	this->emailAddress = emailAddress;
}
void Student::setage(int age)
{
	this->age = age;
}
void Student::setdays(int days[])
{
	for (int i = 0; i < numberOfDays; i++)
		this->days[i] = days[1];
}

void Student::print()
{
	cout << left << setw(5) << studentID;
	cout << left << setw(15) << firstName;
	cout << left << setw(15) << lastName;
	cout << left << setw(30) << emailAddress;
	cout << left << setw(5) << age;
	cout << left << setw(10) << days[0];
	cout << left << setw(10) << days[1];
	cout << left << setw(10) << days[2];
}

Student::~Student()
{

}


