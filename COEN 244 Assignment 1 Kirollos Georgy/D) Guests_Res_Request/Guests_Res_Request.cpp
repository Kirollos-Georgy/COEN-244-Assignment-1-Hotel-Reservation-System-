#include "Guests_Res_Request.h"

int Guests_Res_Request::count = 0;

Guests_Res_Request::Guests_Res_Request() { //default constructor
	res_ID = 0;
	number_of_nights = 0;
}

Guests_Res_Request::Guests_Res_Request(Guests guests) {
	this->guests = guests;
	count++;
	res_ID = count;
	number_of_nights = guests.getCheckOutDate().getDay() - guests.getCheckInDate().getDay();
}

Guests_Res_Request::Guests_Res_Request(const Guests_Res_Request& other) // copy constructor
{
	this->guests = other.guests;
	this->res_ID = other.res_ID;
	this->number_of_nights = other.number_of_nights;
	this->count = other.count;
}

//getters
Guests Guests_Res_Request::getGuests() const{
	return guests;
}

int Guests_Res_Request::getResID() const{
	return res_ID;
}

int Guests_Res_Request::getNumberOfNights() const{
	return number_of_nights;
}

void Guests_Res_Request::print_Guests_Reservation_Request() { //To print the reservation request
	guests.printGuests();
	cout << "Reservation ID: " << res_ID << endl;
	cout << "Number of Nights: " << number_of_nights << endl;
	cout << endl;
}