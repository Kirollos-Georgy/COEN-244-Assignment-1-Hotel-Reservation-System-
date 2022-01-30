#include "Date.h"
#include <iostream>
using namespace std;

Date::Date() {
    day = 0;
    month = 0;
    year = 0;
}

Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

void Date::setDate(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

int Date::getDay() const{
    return day;
}

int Date::getMonth() const{
    return month;
}

int Date::getYear() const{
    return year;
}

void Date::printDate() {
    cout << day << "/" << month << "/" << year << endl;
}