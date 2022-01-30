#pragma once
#include "Guests.h"

class Guests_Res_Request
{
public:
	Guests_Res_Request();
	Guests_Res_Request(Guests guests);
	//void setNumberOfNights(int numberOfNights);
	Guests getGuests() const;
	int getResID() const;
	int getNumberOfNights() const;
	void print_Guests_Reservation_Request();

private:
	Guests guests;
	int res_ID;
	int number_of_nights;
	int count = 0;
};

