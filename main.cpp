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
		case 7: {
			system("CLS");
			header();

			string name, address;
			char ans = 'Y';
			while (toupper(ans) == 'Y') {
				cout << "\nEnter customer name: ";
				cin.ignore();
				getline(cin, name);

				while (name.empty()) {
					cout << "Field can't be empty. Please enter customer name: ";
					getline(cin, name);
				}

				cout << "Enter customer address: ";
				getline(cin, address);

				while (address.empty()) {
					cout << "Field can't be empty. Please enter customer address: ";
					getline(cin, address);
				}

				Customer newCustomer(name, address);  // Create a new customer with the provided name and address
				c.add_customer(customers, newCustomer);  // Add customer to the queue

				cout << "Add more? (Y/N): ";
				cin >> ans;
				while (toupper(ans) != 'Y' && toupper(ans) != 'N') {
					cout << "Invalid input. Please enter 'Y' or 'N' only: ";
					cin >> ans;
				}
			}
			break;
		}
		case 8: {
			system("CLS");
			header();

			char ans = 'Y';
			while (toupper(ans) == 'Y') {
				int customer_id;

				cout << "Enter Customer ID: ";
				while (true) {
					cin >> customer_id;
					if (cin.fail()) {
						cout << "Invalid input. Please enter an integer value only: ";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					else {
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						break;
					}
				}

				c.display_customer_details(customer_id); // Pass customer_id to display details

				cout << "Display another customer? (Y/N): ";
				cin >> ans;
				while (toupper(ans) != 'Y' && toupper(ans) != 'N') {
					cout << "Invalid input. Please enter 'Y' or 'N' only: ";
					cin >> ans;
				}
			}
			break;
		}
		case 9:
			cr.display_rent(rent);
			break;
		case 10:
			goodbye();
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
