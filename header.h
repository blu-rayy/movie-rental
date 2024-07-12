#pragma once
#include <iostream>
using namespace std;

class Video {
private:
    int video_id;
    string movie_title;
    string genre;
    string production;
    string quantity;
public:
    Video();
    void insert_video(string movie_title, string genre, string production, string quantity);
    void rent_video(int video_id);
    void return_video(int video_id);
    void details_video(int video_id);
    void display_all();
    bool check_video_status(int video_id);
};

class Customer {
private:
    int customer_id;
    string customer_name;
    string customer_address;
public:
    Customer();
    void add_customer(string customer_name, string customer_address);
    void display_customer_details(int customer_id);
    void display_all();
};

class Customer_Rent {
private:
    int customer_id;
public:
    Customer_Rent();
    void rent_video(int customer_id);
    void return_video();
    void display_all(); // Prints all rented videos by each customer
};