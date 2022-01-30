#include "Reservation_Manager.h"

Reservation_Manager::Reservation_Manager() {
	//arr = nullptr;
	size = 0;
	for (int i = 0; i < max_no_of_nights; i++)
		for (int j = 0; j < no_of_rooms; j++)
			tableArr[i][j] = 0;
}

/*Reservation_Manager::Reservation_Manager(Guests_Res_Request* arr) {
	this->arr = new Guests_Res_Request[sizeof(arr) + 1];
	for (int i = 0; i < this->arr->getNumberOfNights(); i++) {
		tableArr[this->arr->getGuests().getCheckInDate().getDay() - 1][this->arr->getGuests().getRoomNumber() - 1] = this->arr->getResID();
	}
}*/

int Reservation_Manager::status(Guests_Res_Request request) {
	size++;
	bool successful = false;
	for (int i = 0; i < request.getNumberOfNights(); i++)
		if (tableArr[request.getGuests().getCheckInDate().getDay() - 1 + i][request.getGuests().getRoomNumber() - 1] == 0) 
			successful = true;
		else {
			successful = false;
			break;
		}
	if (successful == true) {
		*(arr + size - 1) = request;
		for (int i = 0; i < request.getNumberOfNights(); i++)
			tableArr[request.getGuests().getCheckInDate().getDay() - 1 + i][request.getGuests().getRoomNumber() - 1] = request.getResID();
		return request.getResID();
	}
}

void Reservation_Manager::reservationDetails(int res_ID) {
	bool found = false;
	int index;
	for (int i = 0; i < sizeof(arr); i++) {
		if ((arr + i)->getResID() == res_ID) {
			found = true;
			index = i;
			break;
		}
	}
	if (found == true) {
		(arr + index)->print_Guests_Reservation_Request();
	}
	else
		cout << "Reservation not found. Please enter a valid reservation ID" << endl;
}

void Reservation_Manager::cancelReservation(int res_ID) {
	bool found = false;
	int index;
	for (int i = 0; i < sizeof(arr); i++) {
		if ((arr + i)->getResID() == res_ID) {
			found = true;
			index = i;
			break;
		}
	}
	if (found == true)
		delete(arr + index);
	else
		cout << "Reservation not found. Please enter a valid reservation ID" << endl;
}