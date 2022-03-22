#include <iostream>
#include <cstring>

#include "customer.h" // header

struct CustomerStruct
{
    char name[20];
    int id;
};

Customer constructorCustomer(char name[20], int id)
{
    Customer customer = new CustomerStruct; // memory instance

    // variables assignament
    strcpy(customer-> name, name);
    customer-> id = id;

    return customer;
}

void toStringCustomer(Customer customer)
{
    printf("Customer name: %s ---- ID: %d", customer-> name, customer-> id);
}
