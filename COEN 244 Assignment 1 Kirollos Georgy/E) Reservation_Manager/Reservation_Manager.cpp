#include "Reservation_Manager.h"
#include <iomanip>

int Reservation_Manager::count = 0;

Reservation_Manager::Reservation_Manager() { //default constructor
	size = 0;
	for (int i = 0; i < max_no_of_nights; i++)
		for (int j = 0; j < no_of_rooms; j++)
			occupied_rooms[i][j] = 0;
}

Reservation_Manager::Reservation_Manager(const Reservation_Manager& other)
{
	this->size = other.size;
	this->arr_of_requests = other.arr_of_requests;
	for (int i = 0; i < max_no_of_nights; i++)
		for (int j = 0; j < no_of_rooms; j++)
			this->occupied_rooms[i][j] = other.occupied_rooms[i][j];
}

int Reservation_Manager::status(Guests_Res_Request request) { //This function add the reservation request to the reservation request array, if the room is available for the full duration of the stay
	count++;
	size = count;
	bool successful = false;
	for (int i = 0; i < request.getNumberOfNights(); i++) //Check that the room is free for the whole duration
		if (occupied_rooms[request.getGuests().getCheckInDate().getDay() - 1 + i][request.getGuests().getRoomNumber() - 1] == 0) 
			successful = true;
		else {
			successful = false;
			break;
		}
	if (successful == true) {
		*(arr_of_requests + size - 1) = request;
		cout << "Successful reservation for guest with reservation ID " << (arr_of_requests + size - 1)->getResID() << endl;
		for (int i = 0; i < request.getNumberOfNights(); i++)  //Add the reservation ID to the room for the dates of the stay
			occupied_rooms[request.getGuests().getCheckInDate().getDay() - 1 + i][request.getGuests().getRoomNumber() - 1] = request.getResID();
		return request.getResID();
	}
	else {
		cout << "Room " << request.getGuests().getRoomNumber() << " is unavalibale for the full duration of your stay .Please choose another room. This message is intended for the guest with reservation ID "<<request.getResID()<<"\n\n";
	}
}

void Reservation_Manager::reservationDetails(int res_ID) { //This function print the resevation details of a successful reservation
	bool found = false;
	int index;
	for (int i = 0; i < size; i++) { //To find the index of the reservation request
		if ((arr_of_requests + i)->getResID() == res_ID) {
			found = true;
			index = i;
			break;
		}
	}
	if (found == true) {
		cout << "Reservation details of the guest with reservation ID " << (arr_of_requests + index)->getResID() << ":" << endl;
		(arr_of_requests + index)->print_Guests_Reservation_Request();
		cout << endl;
	}
	else
		cout << "Reservation not found. Please enter a valid reservation ID" << endl << endl;
}

void Reservation_Manager::cancelReservation(int res_ID) { //Function that delete a reservation request
	bool found = false;
	int index = 0;
	for (int i = 0; i < size; i++) { //To find the index of the reservation request
		if ((arr_of_requests + i)->getResID() == res_ID) {
			found = true;
			index = i;
			break;
		}
	}
	if (found == true) {
		cout << "Reservation cancelled of the guest with reservation ID " << (arr_of_requests + index)->getResID() << endl;
		//delete (arr_of_requests + index);
		*(arr_of_requests + index) = *(arr_of_requests + size - 1);
		*(arr_of_requests + size - 1) = {};
		count--;
		size = count;
	}
	else
		cout << "Reservation not found. Please enter a valid reservation ID" << endl << endl;
}

void Reservation_Manager::printOccupiedRooms() // This function print a table of the rooms on the specified dates with the reservation ID
{
	for (int i = 0; i < max_no_of_nights + 1; i++) {
		if (i != 0)
			cout << setw(10) << "Mar " << i << ": ";
		for (int j = 0; j < no_of_rooms; j++) {
			if (j == 0 && i == 0) {
				cout << "Room Number: ";
				for (int k = 1; k < 21; k++) //To print the room number at the top
					cout << k << " ";
			}
			if (i != 0) {
				if (j < 10)
					cout << occupied_rooms[i - 1][j] << " ";
				else
					cout << " " << occupied_rooms[i - 1][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}
