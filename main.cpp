#include <iostream>
#include <cstring>

// TDA's libraries
#include "bank.h"
#include "customer.h"

using namespace std;

// definitions

int main()
{
    enum orderBy {asc = -1, desc = 1};

    // create customers
    Customer c1 = constructorCustomer("name1", 1111, 125);
    Customer c2 = constructorCustomer("name2", 2222, 171);
    Customer c3 = constructorCustomer("name3", 1234, 200);

    Bank b1 = constructorBank("Bank");
    toStringBank(b1); // expected output: Bank name: Bank ---- Customers amount: 0

    // add customers
    addCustomer(b1, c1); // expected output: customer [name1] successfully added
    addCustomer(b1, c2); // expected output: customer [name2] successfully added
    addCustomer(b1, c3); // expected output: customer [name3] successfully added

    toStringBank(b1); // expected output: Bank name: Bank ---- Customers amount: 3

    // test: setter money customer
    setCustomerMoney(c1, (getCustomerMoney(c1)) + 125);

    // TODO add "withdrawMoney" and "depositMoney"

    showCustomers(b1); // expected output:

    /*
        CUSTOMERS
        Customer name: name1 ---- ID: 1111 ---- Money 250.00 test passed!!! previous value: 125 -> current value: 250
        Customer name: name2 ---- ID: 2222 ---- Money 171.00
        Customer name: name3 ---- ID: 1234 ---- Money 200.00
    */

    bankDestructor(b1); // deallocate memory of bank

    // cout << "\n" << endl; // new line
}

// implementations
