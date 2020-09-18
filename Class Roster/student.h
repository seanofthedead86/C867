#pragma once
#include <string>
#include "degree.h"
using std::string;

class Student
{
public:
	const static int numberOfDays = 3;

protected:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int days[numberOfDays];
	Degree dtype;

public:
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[]);

	string getstudentID();
	string getfirstName();
	string getlastName();
	string getemailAddress();
	int getage();
	int* getdays();
	virtual Degree getdtype() = 0;

	void setstudentID(string studentID);
	void setfirstName(string firstName);
	void setlastName(string lastName);
	void setemailAddress(string emailAddress);
	void setage(int age);
	void setdays(int days[]);

	virtual void print() = 0;

	~Student();

};
