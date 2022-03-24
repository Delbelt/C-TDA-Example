#include <iostream>
#include <cstring>

// TDA's libraries
#include "bank.h"
#include "customer.h"

using namespace std;

// definitions

int main()
{
    Customer c1 = constructorCustomer("name1", 1111);
    Customer c2 = constructorCustomer("name2", 2222);

    Bank b1 = constructorBank("Bank");
    toStringBank(b1); // expected output: Bank name: Bank ---- Customers amount: 0

    // add customers into the bank
    addCustomer(b1, c1); // expected output: customer [name1] successfully added
    addCustomer(b1, c2); // expected output: customer [name2] successfully added

    // repeat: add customer into the bank (exception)
    addCustomer(b1, c2); // expected output: customer already registered, ID: [2222]

    toStringBank(b1); // expected output: Bank name: Bank ---- Customers amount: 2

    showCustomers(b1); // expected output:

    /*
        CUSTOMERS
        Customer name: name1 ---- ID: 1111
        Customer name: name2 ---- ID: 2222
    */

    bankDestructor(b1);

    //cout << "\n" << endl; // new line

    return 0;
}

// implementations
