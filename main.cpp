#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "header.h"
using namespace std;

int main() {
    list<Video> movies; //linked list implementation
    Video v;
    Customer c;
    Customer_Rent cr;

    cout << "Hello World!" << endl;

    //insert input functions here; ensure same data type as the function
    //cin >> title_input then replace on "Die Hard" below, do the rest for the other variables

    v.insert_video(movies, Video("Die Hard", "Action", "20th Century Fox", 5));

    return 0;

}

//when creating new functions, always include:
// header();
// system("cls");
// rest of the code

