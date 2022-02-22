#include "Guests.h"

Guests::Guests() { // default constructor
	roomNumber = 0;
}

Guests::Guests(Date checkInDate, Date checkOutDate, information guestInformation[4], int roomNumber) {
	check_in_date = checkInDate;
	check_out_date = checkOutDate;
	for (int i = 0; i < 4; i++)
		this->guestInformation[i] = guestInformation[i];
	this->roomNumber = roomNumber;
}

//setter
void Guests::setRoomNumber(int roomNumber) {
	this->roomNumber = roomNumber;
}

//getters
Date Guests::getCheckInDate() const{
	return check_in_date;
}

Date Guests::getCheckOutDate() const{
	return check_out_date;
}

information Guests::getGuestsInformation() const{
	for (int i = 0; i < 4; i++)
		if (guestInformation[i].getFirstName() != nullptr)
			return guestInformation[i];
}

int Guests::getRoomNumber() const{
	return roomNumber;
}

void Guests::printGuests() { // To print the guest(s) information
	cout << "Check in date: ";
	check_in_date.printDate();
	cout << "Check out date: ";
	check_out_date.printDate();
	cout << endl;
	for (int i = 0; i < 4; i++)
		if (guestInformation[i].getFirstName() != nullptr) {
			guestInformation[i].printInformation();
			cout << endl;
		}
		else
			break;
	cout << "Room Number: " << roomNumber << endl;
}