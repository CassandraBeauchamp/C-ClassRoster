
#include <iostream>
#include "student.h"
#include "roster.h"
using namespace std;

int main()
{
 
    const std::string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Cassie,Beauchamp,cbeau22@wgu.edu,20,4,5,7,SOFTWARE"
    };

    Roster classRoster;

    cout << "Scripting and Programming Applications C867, Language:C++" << endl;
    cout << "StudentId:011631377, Name:Cassandra Beauchamp" << endl;
    
    int students = 5; // number of students in the list
    for (int i = 0; i < students; i++) // iterates through the students
    {
        classRoster.parseAndAdd(studentData[i]); // add students to the array
    }
   
    //Testing Methods
    classRoster.printAll();
    cout << endl; // New Line
    classRoster.printInvalidEmails();
    cout << endl;

    for (int i = 0; i < students; i++) // iterates through the students
    {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentId());
        cout << endl;
    }



    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;
    //Testing remove function
    classRoster.remove("A3"); 
    cout << endl;
    classRoster.printAll();
    cout << endl;
    classRoster.remove("A3");
    cout << endl;


    return 0;  // Deconstructor is called here automatically and memory is freed

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
