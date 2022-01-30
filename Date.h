#pragma once

class Date
{
public:
	Date();
	Date(int day, int month, int year);
	void setDate(int day, int month, int year);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void printDate();

private:
	int day;
	int month;
	int year;
};