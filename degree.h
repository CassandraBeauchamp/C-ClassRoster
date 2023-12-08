#pragma once
#include<iostream>
using namespace std;

#ifndef degree_h
#define degree_h


enum DegreeProgram // declaring enum with the values
{
	SECURITY = 0, NETWORK = 1, SOFTWARE = 2

};

static const string degreeProgramStrings[] = { "SECURITY","NETWORK","SOFTWARE"}; //to be able to print a string of the enum

#endif