#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip> 
#include <list>
#include <queue>
#include <stack>
#include "header.h"
using namespace std;

void header() {
	system("cls");
	cout << "Welcome to the Video Rental System" << endl;
	cout << "==================================" << endl;
}

void goodbye() {
	cout << "\nThank you for using the Video Rental System!" << endl;
	cout << "\nDEVELOPERS:" << endl;
	cout << "Kristian Bautista" << endl << "Patricia Damaso" << endl << "Wayne Garcia" << endl << "Angel Letada" << endl << "Marianne Santos" << endl;
}

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

    cout << "\nThe Movie \"" << video.movie_title << "\" with Video ID " << video_id << " has been added to the database!" << endl;
	system("pause");
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
	//header();

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

void Customer_Rent::rent_video(stack<string>& customer_rent_stack, int customer_id, string movie_id) {
    string current_time = generate_time();

    // Open movies.txt to find the requested movie_id
    ifstream getVideo_ID("movies.txt");
    if (getVideo_ID.fail()) {
        cout << "Error opening file: movies.txt" << endl;
        return;
    }

    string videoID_result, movie_info;
    while (getline(getVideo_ID, movie_info)) {
        if (movie_info.find(movie_id + ",") == 0) {
            videoID_result = movie_info;
            break;
        }
    }
    getVideo_ID.close();

    if (videoID_result.empty()) {
        cout << "Movie ID not found" << endl;
		first_instance = true;
        return;
    }

    // Open customers.txt to find the requested customer_id
    ifstream getCustomer_ID("customers.txt");
    if (getCustomer_ID.fail()) {
        cout << "Error opening file: customers.txt" << endl;
        return;
    }

    string customerID_result, customer_info;
    while (getline(getCustomer_ID, customer_info)) {
        if (customer_info.find(to_string(customer_id) + ",") == 0) {
            customerID_result = customer_info;
            break;
        }
    }
    getCustomer_ID.close();

    if (customerID_result.empty()) {
        cout << "Customer ID not found" << endl;
		first_instance = true;
        return;
    }

    // Create rental record
    string rental_record = videoID_result + " & " + customerID_result + " @ " + current_time;

    // Check if the rental record already exists in customer_rent_stack
    stack<string> temp_stack = customer_rent_stack;
    while (!temp_stack.empty()) {
        if (temp_stack.top() == rental_record) {
            cout << "Duplicate rental record found" << endl;
            return;
        }
        temp_stack.pop();
    }

    customer_rent_stack.push(rental_record);

    // Read the current contents of customer_rent.txt
    ifstream inCustomerRent("customer_rent.txt");
    if (!inCustomerRent) {
        cout << "Error opening file: customer_rent.txt" << endl;
        return;
    }
    vector<string> records;
    string line;
    while (getline(inCustomerRent, line)) {
        records.push_back(line);
    }
    inCustomerRent.close();

    // Write the new rental record at the top of the file
    ofstream outCustomerRent("customer_rent.txt");
    if (!outCustomerRent) {
        cout << "Error opening file: customer_rent.txt" << endl;
        return;
    }
    outCustomerRent << rental_record << endl;
    for (const auto& rec : records) {
        outCustomerRent << rec << endl;
    }
    outCustomerRent.close();

    decrementMovieQuantity(movie_id);

    cout << rental_record << " has been added to the database" << endl;
}

void Customer_Rent::decrementMovieQuantity(const string& movie_id) {
	ifstream inFile("movies.txt");
	if (inFile.fail()) {
		cout << "Error opening file: movies.txt" << endl;
		return;
	}

	ofstream outFile("temp.txt");
	if (outFile.fail()) {
		cout << "Error opening file: temp.txt" << endl;
		return;
	}

	string movie_info, updated_movie_info;
	bool movieFound = false;

	while (getline(inFile, movie_info)) {
		if (movie_info.find(movie_id) != string::npos) {
			string quantity = movie_info.substr(movie_info.find_last_of(",") + 2);
			int quantity_int = stoi(quantity);
			quantity_int--;
			updated_movie_info = movie_info.substr(0, movie_info.find_last_of(",") + 2) + to_string(quantity_int);
			outFile << updated_movie_info << endl;
			movieFound = true;
		}
		else {
			outFile << movie_info << endl;
		}
	}

	inFile.close();
	outFile.close();

	if (!movieFound) {
		cout << "Video ID not found" << endl;
		remove("temp.txt");
		return;
	}

	if (remove("movies.txt") != 0) {
		cout << "Error deleting original file" << endl;
		return;
	}

	if (rename("temp.txt", "movies.txt") != 0) {
		cout << "Error renaming temporary file" << endl;
		return;
	}

	cout << "Quantity updated successfully." << endl;
}

void Customer_Rent::return_video()
{
	cout << "Implementations Test: Customer_Rent Class" << endl;
}

void Customer_Rent::display_rent(stack<string>& customer_rent_stack) {
	cout << "Implementations Test: Customer_Rent Class" << endl;
}

string Customer_Rent::generate_time()
{
	auto now = chrono::system_clock::now();
	time_t now_time_t = chrono::system_clock::to_time_t(now); // Convert to time_t (epoch time)
	tm local_tm; // Convert to local time using localtime_s
	localtime_s(&local_tm, &now_time_t);
	char time[80];
	strftime(time, sizeof(time), "%Y-%m-%d %H:%M:%S", &local_tm); // Format time as a string

	return string(time);
}

