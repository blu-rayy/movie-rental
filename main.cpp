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
    cout << "Hello World!" << endl;

    //insert input functions here; ensure same data type as the function
    //cin >> title_input then replace on "Die Hard" below, do the rest for the other variables
    //v.insert_video(movies, Video("Die Hard", "Action", "20th Century Fox", 5));
    //v.insert_video(movies, Video("The Matrix", "Horror", "Warner Bros", 3));

    //c.add_customer(customers, "John Doe", "123 Main St");
    //c.add_customer(customers, "Jane Smith", "456 Oak Ave");
    //c.add_customer(customers, "Miles Morales", "Earth 317");

    cr.rent_video(rent, 1, "1A");
    cr.rent_video(rent, 1, "2H");

    return 0;

}

//when creating new functions, always include:
// header();
// rest of the code

