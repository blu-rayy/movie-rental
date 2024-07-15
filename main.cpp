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
	int choice, genre_choice, user_quantity, user_customer_id;
	string user_title, user_genre, user_production, user_video_id;
	char another;

	do {
		cr.first_instance = true;

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
		cout << "\nWhat would you like to do?: ";
		cin >> choice;

		switch (choice) {
		case 1:
			do {
				system("cls");
				header();
				cout << "YOU ARE NOW ADDING TO THE DATABASE FOR VIDEOS..." << endl << endl;

				cout << "Enter the title of the movie: ";
				cin.ignore();
				getline(cin, user_title);
				do {
					cout << "\n[1] Action" << endl << "[2] Comedy" << endl << "[3] Horror" << endl << "[4] Romance" << endl << "[5] Sci-Fi" << endl;
					cout << "Select A Genre: ";
					cin >> genre_choice;

					if (cin.fail()) {
						cin.clear();
						cin.ignore();
						cout << "Invalid choice" << endl;
						continue;
					}
					else cin.ignore();

					switch (genre_choice) {
					case 1: user_genre = "Action"; break;
					case 2: user_genre = "Comedy"; break;
					case 3: user_genre = "Horror"; break;
					case 4: user_genre = "Romance"; break;
					case 5: user_genre = "Sci-Fi"; break;
					default:
						cout << "\nInvalid choice. Enter a number between 1-5" << endl;
						continue;
					}
					cout << "Enter Production Company of Movie: ";
					getline(cin, user_production);
					cout << "How many copies of the movie do you have?: ";
					cin >> user_quantity;

					v.insert_video(movies, Video(user_title, user_genre, user_production, user_quantity));
					break;
				} while (true);

				cout << "Add another video? [Y/N]: ";
				cin >> another;
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "Invalid choice" << endl;
					continue;
				}
				else cin.ignore();
			} while (toupper(another) != 'N');
			system("cls");
			header();
			break;
		case 2:

			do {
				system("cls");
				header();
				cout << "YOU ARE NOW RENTING A VIDEO..." << endl << endl;

				do {
					cout << "Enter Customer ID: ";
					cin >> user_customer_id;

					// Prompt to display customer details
					system("cls");
					header();
					cout << "YOU ARE NOW RENTING A VIDEO..." << endl << endl;

					cout << "Is this you? \n" << endl;
					c.display_customer_details(user_customer_id);
					cout << "\nConfirm? [Y/N]: ";
					cin >> another;

					if (toupper(another) == 'Y') {
						break; // Proceed to rent a video
					}
					else {
						system("cls");
						header();
						cout << "YOU ARE NOW RENTING A VIDEO..." << endl << endl;

						cout << "Please enter your Customer ID again.\n" << endl;
					}
				} while (true);

				// Proceed to rent a video
				system("cls");
				header();
				cout << "YOU ARE NOW RENTING A VIDEO..." << endl << endl;

				v.display_all_movies();

				cout << "\nEnter Video ID to rent: ";
				cin.ignore();
				getline(cin, user_video_id);
				transform(user_video_id.begin(), user_video_id.end(), user_video_id.begin(), ::toupper);

				cr.rent_video(rent, user_customer_id, user_video_id);
				cout << "Rent another video? [Y/N]: ";
				cin >> another;
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "Invalid choice" << endl;
					continue;
				}
				else cin.ignore();

			} while (toupper(another) != 'N');

			break;
		case 3:
			cr.return_video();
			break;
		case 4:
			v.details_video(1);
			break;
		case 5:
			v.display_all_movies();
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
