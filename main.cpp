#include <iostream>
#include "header.h"
using namespace std;

int main() {
    Video v;
    Customer c;
    Customer_Rent cr;

    cout << "Hello World!" << endl;

    v.display_all();
    c.add_customer("John Doe", "1234 Main St.");
    cr.rent_video(1);

    return 0;

}