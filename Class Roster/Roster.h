#pragma once
#include <string>
#include <iostream>
#include "student.h"
#include "NetworkStudent.h"
#include "SecurityStudent.h"
#include "SoftwareStudent.h"

class Roster {
private:
	int lastIndex;
	int capacity;
	Student** classRosterArray;
public:
	Roster();
	Roster(int capacity);
	
	Student* getStudentAt(int index);
	void print_All();
	void printInvalidEmails();
	void printDaysInCourse(string studentID);
	void printByDegreeProgram(int degreeType);
	void parseThenAdd(string row);
	void add(string sID, string sFirstName, string sLastName, string sEmail, int sAge, int days1, int days2, int days3, Degree sd);
	bool remove(string studnetID);

	~Roster();

};
