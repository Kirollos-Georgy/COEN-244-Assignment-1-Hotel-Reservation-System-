#include "Date.h"
#include <iostream>
using namespace std;

Date::Date() { //default constructor
    day = 0;
    month = 0;
    year = 0;
}

Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

Date::Date(const Date& other) //copy constructor
{
    this->day = other.getDay();
    this->month = other.getMonth();
    this->year = other.getYear();
}

void Date::setDate(int day, int month, int year) { // setter for the date
    this->day = day;
    this->month = month;
    this->year = year;
}

//getters for all the data members
int Date::getDay() const{
    return day;
}

int Date::getMonth() const{
    return month;
}

int Date::getYear() const{
    return year;
}

void Date::printDate() { //to print the date
    cout << day << "/" << month << "/" << year << endl;
}