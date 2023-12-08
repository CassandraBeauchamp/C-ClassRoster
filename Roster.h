#pragma once

#ifndef roster_h
#define roster_h

#include "degree.h"
#include "student.h"

class Roster{
    private:
    int index = -1; // Index we will use to add students and keep track of size
    const static int students = 5; // size to set our array to, best practice not to hard code

    public:

     ~Roster(); // Destructor


    //parse through a string to get attributes to make a student
    void parseAndAdd(string studentData);

    // Make our array of pointers
    Student* classRosterArray[students];

    //Methods for the roster
    Student* get(int index);
    void add(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(std::string studentId);
    void printAll();
    void printAverageDaysInCourse(std::string studentId);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);


};
#endif 