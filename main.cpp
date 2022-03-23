#include <iostream>
#include <cstring>

// TDA librarys
#include "bank.h"
#include "customer.h"

using namespace std;

// definitions

int main()
{
    Bank b1 = constructorBank("Bank", 125);
    modifyBank(b1); // expect input: Bank name: "other name" ---- Customer amount: 250
    toStringBank(b1); // expected output: Bank name: other name ---- Customers amount: 250

    cout << "\n" << endl; // new line

    Customer c1 = constructorCustomer("Delbelt", 1111);
    toStringCustomer(c1); // expected output: Customer name: Delbelt ---- ID: 1111

    cout << "\n" << endl; // new line

    return 0;
}

// implementations
