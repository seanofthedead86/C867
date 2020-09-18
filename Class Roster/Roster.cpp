#include "Roster.h"
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <iomanip>


using namespace std;
Roster::Roster()
{
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [capacity];
}

Student* Roster::getStudentAt(int index)
{
	return classRosterArray [index];
}

void Roster::parseThenAdd(string row) {
	if (lastIndex < capacity) {
		lastIndex++;
		Degree degreeType;
		vector<string> results;
		
		for (auto words : row) {
			stringstream  ss(row);
			string classRoster;
			while (getline(ss, classRoster, ',')) {
				results.push_back(classRoster);
			}
		}

		string studentID = results[0];
		string firstName = results[1];
		string lastName = results[2];
		string emailAddress = results[3];
		int age = stoi(results[4]);
		int days1 = stoi(results[5]);
		int days2 = stoi(results[6]);
		int days3 = stoi(results[7]);
		
		if (results[8][0] == 'N') degreeType = NETWORKING;
		else if ((results[8][0] == 'S') && (results[8][1] == 'E'))degreeType = SECURITY;
		else if ((results[8][0] == 'S') && (results[8][1] == 'O'))degreeType = SOFTWARE;
		else
		{
			cerr << "Invalid student type. Exiting the program...\n";
			exit(-1);
		}
		
		add(studentID, firstName, lastName, emailAddress, age, days1, days2, days3, degreeType);
	}
	else
	{
		cerr << "List has exceeded capacity. Exiting the program...";
		exit(-1);
	}
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int days1, int days2, int days3, Degree dtype)
{
	int studentCourses[Student::numberOfDays];
	studentCourses[0] = days1;
	studentCourses[1] = days2;
	studentCourses[2] = days3;
	if (dtype == SOFTWARE) classRosterArray[lastIndex] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, studentCourses, dtype);
	else if (dtype == SECURITY) classRosterArray[lastIndex] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, studentCourses, dtype);
	else classRosterArray[lastIndex] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, studentCourses, dtype);
}
void Roster::print_All()
{
	for (int i = 0; i <= this->lastIndex; i++)
	{
		(this->classRosterArray)[i]->print();
	}
}

bool Roster::remove(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getstudentID() == studentID)
		{
			found = true;
			delete this->classRosterArray[i];

			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
		}
	}
	if (found) {
		cout << "\Student ID " << studentID << " removed\n\n";
	}
	else {
		cout << "\nStudent ID " <<studentID <<" not found\n\n";
	}

	return found;
}

void Roster::printDaysInCourse(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; ++i)
	{
		if (this->classRosterArray[i]->getstudentID() == studentID)
		{
			found = true;
			int* p = classRosterArray[i]->getdays();
			cout << "Student ID " << studentID << ": " << (p[0] + p[1] + p[2]) / 3 << ".\n";
		}
	}
	if (!found) cout << "\nStudent not found!\n";
}


void Roster::printInvalidEmails()
{
for (int i = 0; i <= lastIndex; i++) 
	{
	string emailAddress = classRosterArray[i]->getemailAddress();
	if ((emailAddress.find("@") == string::npos) || (emailAddress.find(" ") != string::npos) || (emailAddress.find(".") == string::npos)) 
	{
		cout << classRosterArray[i]->getemailAddress() << " is not valid." << endl;
	}
}
}

void Roster::printByDegreeProgram(int degreeType)
{
	cout << "Printing students in the " << degreeStrings[degreeType] << " degree program\n";
	cout << left << setw(5) << "ID";
	cout << left << setw(15) << "First Name";
	cout << left << setw(15) << "Last Name";
	cout << left << setw(30) << "Email";
	cout << left << setw(5) << "Age";
	cout << left << setw(10) << "Days 1";
	cout << left << setw(10) << "Days 2";
	cout << left << setw(10) << "Days 3";
	cout << left << setw(10) << "Program";
	cout << "\n";
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getdtype() == degreeType) this->classRosterArray[i]->print();
	}
}
Roster::~Roster()
{
	for (int i = 0; i <= lastIndex; i++)
	{
		delete this->classRosterArray[i];
	}
	delete classRosterArray;
}
void main()
{
	cout << "Class Roster Project for C867 Scripting and Programing - Applications \nSean Cooper \nStudent ID: #001076687\nCreated using C++\n";
	cout << "\n";

	int numStudents = 5;

	
	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	 "A5,Sean,Cooper,scoo182@wgu.edu,33,1000,2365,9999,SOFTWARE" };

	Roster* classRoster = new Roster(numStudents); 

	for (int i = 0; i < numStudents; i++)
	{
		classRoster->parseThenAdd(studentData[i]);
	}

	cout << "Class Roster:\n";
	cout << left << setw(5) << "ID";
	cout << left << setw(15) << "First Name";
	cout << left << setw(15) << "Last Name";
	cout << left << setw(30) << "Email";
	cout << left << setw(5) << "Age";
	cout << left << setw(10) << "Days 1";
	cout << left << setw(10) << "Days 2";
	cout << left << setw(10) << "Days 3";
	cout << left << setw(10) << "Program";
	cout << "\n";

	classRoster->print_All();

	cout << "\nList invalid emails:\n";
	classRoster->printInvalidEmails();

	cout << "\nList average days in course:\n";
	for (int i = 0; i < numStudents; i++) {
		classRoster->printDaysInCourse(classRoster->getStudentAt(i)->getstudentID());
	}

	cout << "\n";

	classRoster->printByDegreeProgram(SOFTWARE);

	cout << "\nRemoving Student ID A3.\n";

	classRoster->remove("A3");
	
	cout << "Class Roster without Student ID A3:\n";
	cout << left << setw(5) << "ID";
	cout << left << setw(15) << "First Name";
	cout << left << setw(15) << "Last Name";
	cout << left << setw(30) << "Email";
	cout << left << setw(5) << "Age";
	cout << left << setw(10) << "Days 1";
	cout << left << setw(10) << "Days 2";
	cout << left << setw(10) << "Days 3";
	cout << left << setw(10) << "Program";
	cout << "\n";
	classRoster->print_All();
	
	cout << "\nVerify Student ID A3 has been removed\n";
	classRoster->remove("A3");
	
	cout << "Class Roster:\n";
	cout << left << setw(5) << "ID";
	cout << left << setw(15) << "First Name";
	cout << left << setw(15) << "Last Name";
	cout << left << setw(30) << "Email";
	cout << left << setw(5) << "Age";
	cout << left << setw(10) << "Days 1";
	cout << left << setw(10) << "Days 2";
	cout << left << setw(10) << "Days 3";
	cout << left << setw(10) << "Program";
	cout << "\n";
	classRoster->print_All();

	classRoster->~Roster();

	return;
}