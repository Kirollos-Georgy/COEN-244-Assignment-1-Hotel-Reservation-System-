#pragma once
#include "Date.h"
#include <iostream>

using namespace std;

class information
{
public:
	information(); //default constructor 
	information(const char* firstName, const char* lastName, Date date_of_birth);
	void setFirstName(char* firstName); //setters for the first name and last name
	void setLastName(char* lastName);
	Date getDateOfBirth() const;	//getters for all the data members
	char* getFirstName() const;
	char* getLastName() const;
	void printInformation(); //print all the information of the guest
	//~information();

private: //data members
	char* firstName;
	char* lastName;
	Date date_of_birth;
};