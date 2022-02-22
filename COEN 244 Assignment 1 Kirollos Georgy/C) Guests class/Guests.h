#pragma once

#include "Date.h"
#include "information.h"

class Guests
{
public:
	Guests(); //default constructor
	Guests(Date checkInDate, Date checkOutDate, information guestInformation[4], int roomNumber);
	//setter
	void setRoomNumber(int roomNumber);
	//getters
	Date getCheckInDate() const;
	Date getCheckOutDate() const;
	information getGuestsInformation() const;
	int getRoomNumber() const;
	void printGuests(); //To print the guest(s) information

private: //data members
	Date check_in_date;
	Date check_out_date;
	information guestInformation[4];
	int roomNumber;
};

