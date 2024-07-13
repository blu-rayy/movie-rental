#pragma once
using namespace std;

class Video {
private:
    string video_id;
    string movie_title;
    string genre;
    string production;
    int quantity;

public:
    Video();
    Video(string title, string genre, string production, int quantity);
    void insert_video(list<Video>& movies, const Video& video);//nilabas ko from the class
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
    Customer(const string& name, const string& address);
    void add_customer(queue<Customer>& customerQueue, const string& name, const string& address);
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
    void generate_time();
};