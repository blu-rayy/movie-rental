#include "header.h"

Video::Video()
{
    video_id = 0;
    movie_title = "";
    genre = "";
    production = "";
    quantity = "";
}

void Video::insert_video(string movie_title, string genre, string production, string quantity)
{
    video_id++;
    this->movie_title = movie_title;
    this->genre = genre;
    this->production = production;
    this->quantity = quantity;
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

void Customer::add_customer(string customer_name, string customer_address)
{
	cout << "Implementations Test: Customer Class" << endl;
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
    cout << "Implementations Test: Customer_Rent Class" << customer_id << endl;

}

void Customer_Rent::return_video()
{
	cout << "Implementations Test: Customer_Rent Class" << endl;
}

void Customer_Rent::display_all()
{
	cout << "Implementations Test: Customer_Rent Class" << endl;
}

