#include "Guests_Res_Request.h"

Guests_Res_Request::Guests_Res_Request() {
	res_ID = 0;
	number_of_nights = 0;
}

Guests_Res_Request::Guests_Res_Request(Guests guests) {
	this->guests = guests;
	count++;
	res_ID = count;
	number_of_nights = guests.getCheckOutDate().getDay() - guests.getCheckInDate().getDay();
}

/*void Guests_Res_Request::setNumberOfNights(int numberOfNights) {
	number_of_nights = numberOfNights;
}*/

Guests Guests_Res_Request::getGuests() const{
	return guests;
}

int Guests_Res_Request::getResID() const{
	return res_ID;
}

int Guests_Res_Request::getNumberOfNights() const{
	return number_of_nights;
}

void Guests_Res_Request::print_Guests_Reservation_Request() {
	guests.printGuests();
	cout << "Reservation ID: " << res_ID << endl;
	cout << "Number of Nights: " << number_of_nights << endl;
	cout << endl;
}