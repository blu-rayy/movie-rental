#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip> 
#include <list>
#include <queue>
#include <stack>
#include "header.h"
#include "TextTable.h"

#define TEXTTABLE_ENCODE_MULTIBYTE_STRINGS
#define TEXTTABLE_USE_EN_US_UTF8

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
	header();

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
	ifstream inFile("customers.txt");
	if (!inFile) {
		cout << "Error opening file: customers.txt" << endl;
		return;
	}

	string line;
	while (getline(inFile, line)) {
		stringstream ss(line);
		string id_str, name, address;
		getline(ss, id_str, ',');
		getline(ss, name, ',');
        getline(ss, address, ',');

			// Read the customer details from the line
			if (getline(ss, id_str, ',') && getline(ss, name, ',') && getline(ss, address, ',')) {
				int id = stoi(id_str); // Convert ID string to integer
				if (id == customer_id) {
					cout << "Customer ID: " << id << endl;
					cout << "Customer Name: " << name << endl;
					cout << "Customer Address: " << address << endl;
					found = true;
					break; 
				}
			}
		}

void Video::display_all_movies() {
    ifstream inFile("movies.txt");
    if (!inFile) {
        cout << "Error opening file: movies.txt" << endl;
        return;
    }

    string line;
    cout << "Available Movies" << endl;
    cout << "===================\n" << endl;

    TextTable displaymovies('-', '|', '+');
    displaymovies.add("Video ID   ");
    displaymovies.add("Movie Title  ");
    displaymovies.add("Genre  ");
    displaymovies.add("Production  ");
    displaymovies.add("Copies  ");
    displaymovies.endOfRow();

    while (getline(inFile, line)) {
        stringstream ss(line);
        string video_id, movie_title, genre, production;
        int quantity;

        getline(ss, video_id, ',');
        getline(ss, movie_title, ',');
        getline(ss, genre, ',');
        getline(ss, production, ',');
        ss >> quantity; // Read the quantity

        ss.ignore();

        displaymovies.add(video_id);
        displaymovies.add(movie_title);
        displaymovies.add(genre);
        displaymovies.add(production);
        displaymovies.add(to_string(quantity));
        displaymovies.endOfRow();
    }

    // inFile.close() should be here, after the while loop
    inFile.close();

    cout << displaymovies << endl;
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

void Customer_Rent::return_video(stack<string>& customer_rent_stack, int customer_id, string movie_id)
{
	// Open customers.txt to find the requested customer_id
	ifstream getCustomer_ID("customers.txt");
	if (getCustomer_ID.fail()) {
		cout << "Error opening file: customers.txt" << endl;
		return;
	}

	string customerID_getresult, customer_get_info;
	while (getline(getCustomer_ID, customer_get_info)) {
		if (customer_get_info.find(to_string(customer_id) + ",") == 0) {
			customerID_getresult = customer_get_info;
			break;
		}
	}                                                  
	getCustomer_ID.close();

	if (customerID_getresult.empty()) {
		cout << "Customer ID not found" << endl;
		first_instance = true;
		return;
	}

	// Read the current contents of customer_rent.txt
	ifstream inCustomerRent("customer_rent.txt");
	if (!inCustomerRent) {
		cout << "Error opening file: customer_rent.txt" << endl;
		return;
	}

	string customerID_result, customer_info;
	while (getline(inCustomerRent, customer_info)) {
		int customerID_index = customer_info.find('&');
		int index_start = customerID_index + 2;
		int index_end = customer_info.find(',', index_start);
		string customer_result = customer_info.substr(index_start, index_end - index_start);
		if (customer_id == stoi(customer_result))
		{
			string videoID = customer_info.substr(0, 2);
			cout << "Video ID: " << videoID << endl;
		}
	}

}

void Customer_Rent::display_rent(stack<string>& customer_rent_stack) {
    string customerID;
    cout << "Enter customer ID: ";
    cin >> customerID;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore leftover newline

    ifstream inCustomerInfo("customers.txt");
    if (!inCustomerInfo) {
        cout << "Failed to open customers.txt" << endl;
        return;
    }

    string line;
    bool found = false;
    string customerName, customerAddress;

    // Check if the customer ID exists in customers.txt
    while (getline(inCustomerInfo, line)) {
        stringstream ss(line);
        string id;
        getline(ss, id, ',');
        if (id == customerID) {
            getline(ss, customerName, ',');
            getline(ss, customerAddress, ',');
            // Trim any leading spaces
            customerName = customerName.substr(1);
            customerAddress = customerAddress.substr(1);
            found = true;
            break;
        }
    }

    inCustomerInfo.close();

    if (!found) {
        cout << "Customer ID not found." << endl;
        return;
    }

    TextTable t('-', '|', '+');
    t.add("Customer ID");
    t.add(customerID);
    t.endOfRow();

    t.add("Name");
    t.add(customerName);
    t.endOfRow();

    t.add("Address");
    t.add(customerAddress);
    t.endOfRow();

    vector<string> rentedVideos;
    ifstream inCustomerRent("customer_rent.txt");
    if (!inCustomerRent) {
        cout << "Failed to open customer_rent.txt" << endl;
        return;
    }

    found = false;

    // Check if the customer has rented any videos
    while (getline(inCustomerRent, line)) {
        size_t pos = line.find(" & ");
        if (pos != string::npos) {
            string customerPart = line.substr(pos + 3);
            size_t atPos = customerPart.find(" @ ");
            if (atPos != string::npos) {
                string customerDetails = customerPart.substr(0, atPos);
                if (customerDetails.find(customerID + ",") != string::npos) {
                    string videoPart = line.substr(0, pos);
                    string rentalDate = customerPart.substr(atPos + 3);
                    
                    // Extract Video ID and Movie Title from videoPart
                    stringstream videoStream(videoPart);
                    string videoID, movieTitle;
                    getline(videoStream, videoID, ',');
                    getline(videoStream, movieTitle, ',');
                    movieTitle = movieTitle.substr(1); // Trim leading space
                    
                    rentedVideos.push_back(videoID + ", " + movieTitle + " @ " + rentalDate);
                    found = true;
                }
            }
        }
    }

    inCustomerRent.close();

    if (!found) {
        cout << "No videos found for customer ID " << customerID << "." << endl;
    } else {
        // Create a new TextTable instance for rented videos
        TextTable rentedVideosTable('-', '|', '+');
        
        rentedVideosTable.add("Rented Videos:");
		rentedVideosTable.add("");
		rentedVideosTable.add("");
        rentedVideosTable.endOfRow();

        rentedVideosTable.add("Video ID");
        rentedVideosTable.add("Movie Title");
        rentedVideosTable.add("Rental Date");
        rentedVideosTable.endOfRow();

        for (const auto& video : rentedVideos) {
            size_t atPos = video.find(" @ ");
            string videoInfo = video.substr(0, atPos);
            string rentalDate = video.substr(atPos + 3);
            stringstream ss(videoInfo);
            string videoID, movieTitle;
            getline(ss, videoID, ',');
            getline(ss, movieTitle, ',');
            movieTitle = movieTitle.substr(1); // Trim leading space

            rentedVideosTable.add(videoID);
            rentedVideosTable.add(movieTitle);
            rentedVideosTable.add(rentalDate);
            rentedVideosTable.endOfRow();
        }
        cout << t << endl; // Print customer information table first
        cout << rentedVideosTable << endl; // Print rented videos table
    }
}

string Customer_Rent::generate_time()
{
    auto now = chrono::system_clock::now();
    time_t now_time_t = chrono::system_clock::to_time_t(now);
    tm local_tm;

    localtime_s(&local_tm, &now_time_t); // For Windows
    // localtime_r(&now_time_t, &local_tm); // For Mac

    char time_buffer[80];
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", &local_tm);

    return std::string(time_buffer);
}

