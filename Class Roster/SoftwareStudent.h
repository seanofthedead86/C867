#pragma once
#include <string>
#include "student.h"

class SoftwareStudent : public Student
{

public:
	SoftwareStudent();
	SoftwareStudent(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int days[],
		Degree dtype
	);

	Degree getdtype();
	void print();

	~SoftwareStudent();
};