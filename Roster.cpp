#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "roster.h"
#include "student.h"
using namespace std;


void Roster::parseAndAdd(string studentData)
{
	
	string studentId; // Make my variable to pass to add
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse1;
	int daysInCourse2;
	int daysInCourse3;
	DegreeProgram degreeProgram;

	int nextComma = 0;
	int currentIndex = 0;

	nextComma = studentData.find(",", currentIndex); // nextComma is equal to the index of the next comma
	studentId = studentData.substr(currentIndex, nextComma); // assign next variable to between current index and nextComma
	currentIndex = nextComma + 1; // currentIndex is set to next field

	nextComma = studentData.find(",", currentIndex); 
	firstName = studentData.substr(currentIndex, nextComma-currentIndex);
	currentIndex = nextComma + 1;

	nextComma = studentData.find(",", currentIndex); // nextComma is equal to the index of the next comma
	lastName = studentData.substr(currentIndex, nextComma - currentIndex); // assign next variable to between current index and nextComma
	currentIndex = nextComma + 1;

	nextComma = studentData.find(",", currentIndex); // nextComma is equal to the index of the next comma
	emailAddress = studentData.substr(currentIndex, nextComma - currentIndex); // assign next variable to between current index and nextComma
	currentIndex = nextComma + 1;

	nextComma = studentData.find(",", currentIndex); // nextComma is equal to the index of the next comma
	age = stod(studentData.substr(currentIndex, nextComma - currentIndex)); // Stod casts the substring as an int
	currentIndex = nextComma + 1;
	
	nextComma = studentData.find(",", currentIndex); // nextComma is equal to the index of the next comma
	daysInCourse1 = stod(studentData.substr(currentIndex, nextComma - currentIndex)); // Stod casts the substring as an int
	currentIndex = nextComma + 1;

	nextComma = studentData.find(",", currentIndex); // nextComma is equal to the index of the next comma
	daysInCourse2 = stod(studentData.substr(currentIndex, nextComma - currentIndex)); // Stod casts the substring as an int
	currentIndex = nextComma + 1;

	nextComma = studentData.find(",", currentIndex); // nextComma is equal to the index of the next comma
	daysInCourse3 = stod(studentData.substr(currentIndex, nextComma - currentIndex)); // Stod casts the substring as an int
	currentIndex = nextComma + 1;

	nextComma = studentData.find(",", currentIndex); // nextComma is equal to the index of the next comma
	string findDegreeProgram = (studentData.substr(currentIndex, nextComma - currentIndex)); 

	// Can't use the same method since we can't cast it as a DegreeProgram like we did with int
	degreeProgram = SOFTWARE;
	if (findDegreeProgram.back() == 'K') degreeProgram = NETWORK; // Look at the Last letter since they are all different unlike first letters
	else if (findDegreeProgram.back() == 'Y') degreeProgram = SECURITY;

	add(studentId, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);

	
	
}

Roster::~Roster()
{
	cout << "Deconstructor called" << endl;
	for (int i = 0; i <= index; i++)
	{
		delete classRosterArray[i];
		index--;
	}
}

void Roster::add(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) 
{

	int daysInCourseArray[3];
	daysInCourseArray[0] = daysInCourse1;
	daysInCourseArray[1] = daysInCourse2;
	daysInCourseArray[2] = daysInCourse3; // Make an array with all the daysInCourse parameters

	this->classRosterArray[++index] = new Student(studentId, firstName, lastName, emailAddress, age, daysInCourseArray, degreeProgram); // Add student to the array
}


Student* Roster::get(int index) //return student based off index
{
	return classRosterArray[index];
}
void Roster::remove(std::string studentId)
{
	cout << "Attempting to remove student with ID "  << studentId << ": " << endl; 
	int found = 0;


	for (int i = 0; i <= this->index; i++)
	{
		if (classRosterArray[i]->getStudentId() == studentId)
		{
			found = 1;
			delete classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[index]; // Move last index to deleted index to not leave gaps 
			index--; // Shorten the indexs since we got rid of a element of the array
			cout << "Success!";
		}
	}

	if(found == 0)
	cout << "Error: Student not found." << endl;
	
}

void Roster::printAll() // Print students
{
	cout << "Printing all the students: " << endl;
	for (int i = 0; i <= this->index; ++i) { // go through the roster
		
			classRosterArray[i]->print();
		
	}

}

void Roster::printAverageDaysInCourse(string studentId)
{

	for (int i = 0; i <= index; i++)
	{
		if (classRosterArray[i]->getStudentId() == studentId)
		{
			double average = 0;
			average += classRosterArray[i]->getDaysInCourse1();
			average += classRosterArray[i]->getDaysInCourse2();
			average += classRosterArray[i]->getDaysInCourse3();
			average = average / 3.0;
			cout << "The student with id " << studentId <<" average days in a course is : " << average << endl;

		}

	}
}
void Roster::printInvalidEmails() 
{
	int invalidEmails = 0;
	for (int i = 0; i <= Roster::index; i++)
	{
		string email = (classRosterArray[i]->getEmailAddress());

		if ((email.find('.') == string::npos)||email.find('@') == string::npos||email.find(' ') != string::npos) // find emails that dont have a @ and a . and/or contain spaces
		{
			{
				invalidEmails++;
				if (invalidEmails == 1) 
				{
					cout << "Invalid Emails: \n" << endl; // print header on first invalid email
				}
				cout << email << "\n" << endl;
			}
		}
	}

}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) //Prints out student information for a degree program specified by an enumerated type
{
	cout << "Printing all students in specified degree program: " << endl; //Print students in SOFTWARE program
	for (int i = 0; i <= this->index; i++)
	{
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram)
		{
			classRosterArray[i]->print();
		}
	}

}
