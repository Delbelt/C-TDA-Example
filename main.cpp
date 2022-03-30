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

    // delete a customer the bank

    deleteCustomer(b1, c2);

    cout << "" << endl; // new line

    showCustomers(b1); // expected output:

    /*
        CUSTOMERS
        Customer name: name1 ---- ID: 1111
    */

    // exception: delete a customer that does not exist in the struct
    Customer c3 = constructorCustomer("name3", 5555);
    deleteCustomer(b1, c3); // expected output: Customer name3 not found

    bankDestructor(b1); // deallocate memory of bank

    // cout << "\n" << endl; // new line
}

// implementations
