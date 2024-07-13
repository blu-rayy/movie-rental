#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <queue>
#include "header.h"
using namespace std;

Video::Video()
{
	video_id = "";
	movie_title = "";
	genre = "";
	production = "";
	quantity = 0;
}

Video::Video(string title, string genre, string production, int quantity) //parameterized constructor
	: movie_title(title), genre(genre), production(production), quantity(quantity) {} //initialization list

void Video::insert_video(list<Video>& movies, const Video& video) //takes in a list of movies and a video object to add to the list
{

	movies.push_back(video);
		
    ofstream outVideo("movies.txt", ios::app);
    if (!outVideo) {
		cout << "Error opening file: movies.txt" << endl;
		return;
	}
    else
	{
		ifstream countVideo("movies.txt"); //opens file and counts number of lines for Video ID
		if (!countVideo) {
			cout << "Error opening file: movies.txt" << endl;
			return;
		}

		int numLines = 0;
		string line;
		while (getline(countVideo, line)) {
			numLines++;
		}
		countVideo.close();

	string prefix = video.genre.substr(0, 1); //prefix for Video ID
		video_id = to_string(numLines + 1) + prefix; //end of Video ID count 

		outVideo << video_id << ", " 
			<< video.movie_title << ", " 
			<< video.genre << ", " 
			<< video.production << ", " 
			<< video.quantity << endl;

		outVideo.close();
	}

    cout << "\nThe Movie \"" << video.movie_title << "\" with Video ID " << video_id << " has been added to the database" << endl;
}

void Video::rent_video(int video_id)
{
    cout << "Implementations Test: Video Class";
}

void Video::return_video(int video_id)
{
    cout << "Implementations Test: Video Class";
}

void Video::details_video(int video_id)
{
    cout << "Implementations Test: Video Class";
}

void Video::display_all()
{
    cout << "Implementations Test: Video Class" << endl;
}

bool Video::check_video_status(int video_id) {
    	return true;
}


Customer::Customer()
{
	customer_id = 0;
	customer_name = "";
	customer_address = "";
}

Customer::Customer(const string& name, const string& address) //also a parameterized constructor
	: customer_name(name), customer_address(address) {}

void Customer::add_customer(queue<Customer>& customerQueue, const string& name, const string& address)
{
	Customer newCustomer(name, address); 	// Create a new customer with the provided name and address
	newCustomer.customer_id = customerQueue.size() + 1; // Assign a unique ID to the customer

	customerQueue.push(newCustomer);

	ofstream outCustomer("customers.txt");
	if (!outCustomer) {
		cout << "Error opening file: customers.txt" << endl;
		return;
	}

	queue<Customer> tempQueue = customerQueue; // Write all customers from the queue to the file
	while (!tempQueue.empty()) {
		Customer customer = tempQueue.front();
		outCustomer << customer.customer_id << ", "
			<< customer.customer_name << ", "
			<< customer.customer_address << endl;
		tempQueue.pop();
	}
	
	outCustomer.close();

	cout << "\nCustomer " << newCustomer.customer_name << " with ID " << newCustomer.customer_id << " has been added to the database" << endl;
}


void Customer::display_customer_details(int customer_id)
{
	cout << "Implementations Test: Customer Class" << endl;
}

void Customer::display_all()
{
	cout << "Implementations Test: Customer Class" << endl;
}


Customer_Rent::Customer_Rent()
{
	customer_id = 0;
}

void Customer_Rent::rent_video(int customer_id) 
{
    cout << "Implementations Test: Customer_Rent Class: " << customer_id << endl;

}

void Customer_Rent::return_video()
{
	cout << "Implementations Test: Customer_Rent Class" << endl;
}

void Customer_Rent::display_all()
{
	cout << "Implementations Test: Customer_Rent Class" << endl;
}

