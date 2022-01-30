#pragma once
#include "Date.h"
#include "information.h"

class Guests
{
public:
	Guests();
	Guests(Date checkInDate, Date checkOutDate, information guestInformation[4], int roomNumber);
	void setRoomNumber(int roomNumber);
	Date getCheckInDate() const;
	Date getCheckOutDate() const;
	information getGuestsInformation() const;
	int getRoomNumber() const;
	void printGuests();

private:
	Date check_in_date;
	Date check_out_date;
	information guestInformation[4];
	int roomNumber;
};

