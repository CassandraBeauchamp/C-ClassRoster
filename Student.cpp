#include <stdio.h>
#include "Student.h"
#include "roster.h"
#include "degree.h"
using namespace std;


//Constructor

Student::Student()
{
    this->studentId = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    this->daysInCourse[0] = 0;
    this->daysInCourse[1] = 0;
    this->daysInCourse[2] = 0;
    this->degreeProgram = SOFTWARE;
}
Student::Student(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse[3], DegreeProgram degreeProgram)
{
    this->studentId = studentId;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->daysInCourse[0] = daysInCourse[0];
    this->daysInCourse[1] = daysInCourse[1];
    this->daysInCourse[2] = daysInCourse[2];
    this->degreeProgram = degreeProgram;

}




//Getters for private student variables
string Student::getStudentId() 
{ 
    return this->studentId;
}
string Student::getFirstName() 
{ 
    return this->firstName;
}
string Student::getLastName() 
{
    return this->lastName; 
}
string Student::getEmailAddress()
{ 
    return this->emailAddress; 
}
int Student::getAge() { 
    return age;
}
int Student::getDaysInCourse1()
{
    return this->daysInCourse[0];
}
int Student::getDaysInCourse2()
{
    return this->daysInCourse[1];
}
int Student::getDaysInCourse3()
{
    return this->daysInCourse[2];
}
DegreeProgram Student::getDegreeProgram() 
{ 
    return this->degreeProgram; 
}

//Setters for private student variables
void Student::setStudentId(std::string studentId)
{
    this->studentId = studentId;
}
void Student::setFirstName(std::string firstName)
{
    this->firstName = firstName;
}
void Student::setLastname(std::string lastName) 
{ 
    this->lastName = lastName; 
}
void Student::setEmailAddress(std::string emailAddress)
{ 
    this->emailAddress = emailAddress; 
}
void Student::setAge(int age) 
{ 
    this->age = age;
}
void Student::setDaysInCourse(int daysInCourse[])
{
    this->daysInCourse[0] = daysInCourse[0];
    this->daysInCourse[1] = daysInCourse[1];
    this->daysInCourse[2] = daysInCourse[2];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) 
{
    this->degreeProgram = degreeProgram;
}

//Print Statment
void Student::print()
{
    cout << this->getStudentId(); 
    cout << '\t';
    cout << "First Name: ";
    cout << '\t';
    cout << this->getFirstName();
    cout << '\t';
    cout << "Last Name: ";
    cout << '\t';
    cout << this->getLastName();
    cout << '\t';
    cout << "Age: ";
    cout << '\t';
    cout << this->getAge();
    cout << '\t';
    cout << "daysInCourse: ";
    cout << '\t';
    cout << this->getDaysInCourse1() << " ,";
    cout << this->getDaysInCourse2() << " ,";
    cout << this->getDaysInCourse3();
    cout << "Degree Program: ";
    cout << '\t';
    cout << degreeProgramStrings[this->getDegreeProgram()] << '\n';
}