#include <iostream>
#include "Date.h"
#include "information.h"
#include "Guests.h"
#include "Guests_Res_Request.h"
#include "Reservation_Manager.h"

using namespace std;

int main(){
	information* kiro = new information("Kirollos", "George", {18, 5, 2003});
	information* mero = new information("Mariam", "George", { 21, 10, 2010 });
	information* george = new information("George", "Azmy", { 11,4,1968 });
	information* mary = new information("Mary", "Nicola", { 2,10, 1970 });
	information arr1[4] = { *kiro, *mero };
	information arr2[4] = { *george, *mary };
	Guests guest{ {1, 3, 2021}, {7, 3, 2021}, arr1, 5 };
	Guests guest1{ {3, 3, 2021}, {6, 3, 2021}, arr2, 9 };
	Guests_Res_Request request = { guest };
	Guests_Res_Request request1 = { guest1 };
	Reservation_Manager manage;
	manage.status(request);
	manage.status(request1);
	manage.reservationDetails(1);
	manage.cancelReservation(1);
	manage.reservationDetails(1);
	manage.reservationDetails(2);
	request.print_Guests_Reservation_Request();
}
