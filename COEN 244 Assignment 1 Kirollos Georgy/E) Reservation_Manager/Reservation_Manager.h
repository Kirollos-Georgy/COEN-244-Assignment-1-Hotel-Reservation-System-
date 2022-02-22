#pragma once

#include "Guests_Res_Request.h"

class Reservation_Manager
{
public:
	Reservation_Manager();
	Reservation_Manager(const Reservation_Manager& other);
	int status(Guests_Res_Request obj); //This function add the reservation request to the reservation request array, if the room is available for the full duration of the stay
	void reservationDetails(int Res_ID); //This function print the resevation details of a successful reservation
	void cancelReservation(int Res_ID); //Function that delete a reservation request
	void printOccupiedRooms(); // This function print a table of the rooms on the specified dates with the reservation ID

private: //data members
	static const int max_no_of_nights = 7;
	static const int no_of_rooms = 20;
	int size;
	Guests_Res_Request* arr_of_requests = new Guests_Res_Request[size];
	int occupied_rooms[max_no_of_nights][no_of_rooms];
	static int count; //to count the number of successful reservations and add them to the size
};