#include <iostream>
#include <string>
#include <list>
#include <queue>
#include "header.h"
using namespace std;

int main() {
    list<Video> movies; //linked list implementation
    queue<Customer> customers; //stack implementation

    Video v;
    Customer c;
    Customer_Rent cr;

    cout << "Hello World!" << endl;

    //insert input functions here; ensure same data type as the function
    //cin >> title_input then replace on "Die Hard" below, do the rest for the other variables
    //v.insert_video(movies, Video("Die Hard", "Action", "20th Century Fox", 5));

    //c.add_customer(customers, "John Doe", "123 Main St");
    //c.add_customer(customers, "Jane Smith", "456 Oak Ave");
    //c.add_customer(customers, "Miles Morales", "Earth 317");

    cr.generate_time();

    return 0;

}

//when creating new functions, always include:
// header();
// system("cls");
// rest of the code

