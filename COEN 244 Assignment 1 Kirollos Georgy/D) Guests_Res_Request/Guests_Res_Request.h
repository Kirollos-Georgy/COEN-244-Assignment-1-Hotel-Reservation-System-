#pragma once
#include "Guests.h"

class Guests_Res_Request
{
public:
	Guests_Res_Request(); //Default constructor
	Guests_Res_Request(Guests guests);
	Guests_Res_Request(const Guests_Res_Request& other); //copy constructor
	//getters
	Guests getGuests() const;
	int getResID() const;
	int getNumberOfNights() const;
	void print_Guests_Reservation_Request(); //To print the information of the reservation request

private: // Data members
	Guests guests;
	int res_ID;
	int number_of_nights;
	static int count; //to count the number of reservation requests and add them to the reservation ID
};

