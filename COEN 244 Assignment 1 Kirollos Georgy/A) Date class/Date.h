#pragma once

class Date
{
public:
	Date();  //default constructor
	Date(int day, int month, int year);  
	Date(const Date& other);  //copy constuctor
	void setDate(int day, int month, int year);  //setter for the date
	int getDay() const;  //getters for all the data members
	int getMonth() const;
	int getYear() const;
	void printDate(); //To print the date in the format dd/mm/yyyy

private: //data members
	int day;
	int month;
	int year;
};