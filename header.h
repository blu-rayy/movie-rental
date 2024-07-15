#pragma once
using namespace std;

void header();
void goodbye();
void sort(vector<string>& vec);

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
<<<<<<< HEAD
    void insert_video(list<Video>& movies, const Video& video);
    void rent_video(int video_id);
    void return_video(int video_id);
=======
    void insert_video(list<Video>& movies, const Video& video);//nilabas ko from the class
>>>>>>> master
    void details_video(int video_id);
    void display_all_movies();
    bool check_video_status(int video_id);
};

<<<<<<< HEAD

class Customer{
<<<<<<< HEAD
=======
class Customer {
>>>>>>> 31bd267026617b858b8045ec051245e835a3d5cd
private:
=======
protected:
>>>>>>> master
    int customer_id;
    string customer_name;
    string customer_address;
public:
    Customer();
    Customer(const string& name, const string& address);
<<<<<<< HEAD
    void add_customer(queue<Customer>& customerQueue, const string& name, const string& address);
=======
    void add_customer(queue<Customer>& customerQueue, Customer& newCustomer);
>>>>>>> 31bd267026617b858b8045ec051245e835a3d5cd
    void display_customer_details(int customer_id);
};

class Customer_Rent : public Customer {
public:
    Customer_Rent();
    void rent_video(stack<string>& customer_rent_stack, int customer_id, string movie_id);
    void decrementMovieQuantity(const string& movie_id);
    void incrementMovieQuantity(const string& movie_id);
    void return_video(stack<string>& customer_rent_stack, int customer_id);
    void display_rent(stack<string>& customer_rent_stack, int customer_id);
    string generate_time();
<<<<<<< HEAD
    bool first_instance;
};
=======
};
>>>>>>> 31bd267026617b858b8045ec051245e835a3d5cd
