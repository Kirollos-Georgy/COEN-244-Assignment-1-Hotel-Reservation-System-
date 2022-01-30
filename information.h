#pragma once
#include "Date.h"
#include <iostream>

using namespace std;

class information
{
public:
	information();
	information(const char* firstName, const char* lastName, Date date_of_birth);
	void setFirstName(char* firstName);
	void setLastName(char* lastName);
	Date getDateOfBirth() const;
	char* getFirstName() const;
	char* getLastName() const;
	void printInformation();
	//~information();

private:
	char* firstName;
	char* lastName;
	Date date_of_birth;
};