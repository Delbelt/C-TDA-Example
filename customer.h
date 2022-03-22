#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

struct CustomerStruct; // structure signature

typedef struct CustomerStruct *Customer; // pointer to a structure

Customer constructorCustomer(char name[20], int id);

// show the customer
void toStringCustomer(Customer customer);

// TODO add destroyer, getters and setters

#endif // CUSTOMER_H_INCLUDED
