#include <iostream>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include "header.h"
using namespace std;

int main() {
    list<Video> movies;
    queue<Customer> customers; 
    stack<string> rent; 

    Video v;
    Customer c;
    Customer_Rent cr;

    header();
    int choice;

	do {
		cout << "[1] New Video" << endl;
		cout << "[2] Rent a Video" << endl;
		cout << "[3] Return a Video" << endl;
		cout << "[4] Show Video Details" << endl;
		cout << "[5] Display Videos" << endl;
		cout << "[6] Check Video Availability" << endl;
		cout << "[7] Add Customer" << endl;
		cout << "[8] Show Customer Details" << endl;
		cout << "[9] List of Videos Rented by a Customer" << endl;
		cout << "[10] Exit" << endl;
		cout << "What would you like to do?: ";
		cin >> choice;

		switch (choice) {
		case 1:
			v.insert_video(movies, Video("Die Hard", "Action", "20th Century Fox", 5));
			v.insert_video(movies, Video("The Matrix", "Horror", "Warner Bros", 3));
			break;
		case 2:
			cr.rent_video(rent, 1, "1A");
			cr.rent_video(rent, 1, "2H");
			break;
		case 3:
			cr.return_video();
			break;
		case 4:
			v.details_video(1);
			break;
		case 5:
			v.display_all();
			break;
		case 6:
			v.check_video_status(1);
			break;
		case 7:
			c.add_customer(customers, "John Doe", "123 Main St");
			c.add_customer(customers, "Jane Smith", "456 Oak Ave");
			c.add_customer(customers, "Miles Morales", "Earth 317");
			break;
		case 8:
			c.display_customer_details(1);
			break;
		case 9:
			cr.display_rent(rent);
			break;
		case 10:
			cout << "Insert Credits";
			return 0;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
	} while (true);

	//when creating new functions, always include:
	// header();
	// rest of the code

    return 0;

}
