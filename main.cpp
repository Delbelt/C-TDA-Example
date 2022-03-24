#include <iostream>
#include <cstring>

// TDA's libraries
#include "bank.h"
#include "customer.h"

using namespace std;

// definitions

int main()
{
    Bank b1 = constructorBank("Bank", 125);
    toStringBank(b1); // expected output: Bank name: Bank ---- Customers amount: 125

    // note: list customer are included in toStringBank

    /* expected output:
        CUSTOMERS:
        Customer name: empty ---- ID: -1 (ten times)
    */

    bankDestructor(b1);

    cout << "\n" << endl; // new line

    return 0;
}

// implementations
