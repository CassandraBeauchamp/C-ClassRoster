#pragma once
#ifndef Student_h
#define Student_h

#include <iostream>
#include <iomanip>
#include "degree.h"
using namespace std;

class Student
{
	private: // private variables for students
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3];
	DegreeProgram degreeProgram;

	public: // Public methods for students

	Student();

	Student(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse[3], DegreeProgram degreeProgram); //Constructor

	

	string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int getDaysInCourse1();
	int getDaysInCourse2();
	int getDaysInCourse3();
	DegreeProgram getDegreeProgram();

	//Setters for the variables
	void setStudentId(std::string studentID);
	void setFirstName(std::string firstName);
	void setLastname(std::string lastName);
	void setEmailAddress(std::string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	//print statement for students
	void print();






};




#endif 