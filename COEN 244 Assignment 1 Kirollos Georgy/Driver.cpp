#include <iostream>
#include "Date.h"
#include "information.h"
#include "Guests.h"
#include "Guests_Res_Request.h"
#include "Reservation_Manager.h"

using namespace std;

int main(){
	information* information1 = new information("Kirollos", "George", {18, 5, 2003});
	information* information2 = new information("First", "Last", { 21, 10, 2000 });
	information* information3 = new information("Ann", "Max", { 11,4,1980 });
	information* information4 = new information("NameFirst", "NameLast", { 2,10, 1990 });
	information arr1[4] = { *information1, *information2 };
	information arr2[4] = { *information3};
	information arr3[4] = { *information4 };
	Guests guest1{ {1, 3, 2021}, {7, 3, 2021}, arr1, 5 };
	Guests guest2{ {3, 3, 2021}, {6, 3, 2021}, arr2, 15 };
	Guests guest3{ {2, 3, 2021}, {6, 3, 2021}, arr3, 5 };
	Guests_Res_Request request1 = { guest1 };
	Guests_Res_Request request2 = { guest2 };
	Guests_Res_Request request3 = { guest3 };
	Reservation_Manager manage;
	manage.status(request1);
	manage.status(request2);
	manage.status(request3);
	manage.printOccupiedRooms();
	manage.reservationDetails(1);
	manage.cancelReservation(1);
	manage.reservationDetails(1);
	manage.reservationDetails(2);
	manage.reservationDetails(3);
}
