#include "information.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


information::information() { //default constructor
	firstName = nullptr;
	lastName = nullptr;
}


information::information(const char* firstName, const char* lastName, Date date_of_birth) {
	this->firstName = new char[strlen(firstName) + 1];
	strcpy_s(this->firstName, strlen(firstName) + 1, firstName);
	this->lastName = new char[strlen(lastName) + 1];
	strcpy_s(this->lastName, strlen(lastName) + 1, lastName);
	this->date_of_birth = date_of_birth;
}

//setters to set the first name and the last name
void information::setFirstName(char* firstName) {
	this->firstName = new char[strlen(firstName) + 1];
	strcpy_s(this->firstName, strlen(firstName) + 1, firstName);
}

void information::setLastName(char* lastName) {
	this->lastName = new char[strlen(lastName) + 1];
	strcpy_s(this->lastName, strlen(lastName) + 1, lastName);
}

//getters to return the value of all the data members
Date information::getDateOfBirth() const{
	return date_of_birth;
}

char* information::getFirstName() const{
	return firstName;
}

char* information::getLastName() const{
	return lastName;
}

void information::printInformation() { //to print the information of the guest
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
	cout << "Date of Birth: ";
	date_of_birth.printDate();
}

/*information::~information()
{
	delete firstName;
	delete lastName;
}*/
