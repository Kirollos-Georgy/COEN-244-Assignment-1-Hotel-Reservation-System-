#pragma once

#include "Guests_Res_Request.h"

class Reservation_Manager
{
public:
	Reservation_Manager();
	//Reservation_Manager(Guests_Res_Request* arr);
	int status(Guests_Res_Request obj);
	void reservationDetails(int Res_ID);
	void cancelReservation(int Res_ID);

private:
	static const int max_no_of_nights = 7;
	static const int no_of_rooms = 20;
	int size;
	Guests_Res_Request* arr = new Guests_Res_Request[size];
	int tableArr[max_no_of_nights][no_of_rooms];
};