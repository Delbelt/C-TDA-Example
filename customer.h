#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

struct CustomerStruct; // structure signature

typedef struct CustomerStruct *Customer; // pointer to a structure

Customer constructorCustomer(char name[20], int id, float money);

void toStringCustomer(Customer customer); // show the customer
void modifyCustomer(Customer customer); // modify attributes of customer

// getters

char *getCustomerName(Customer customer);
int getCustomerId(Customer customer);
float getCustomerMoney(Customer customer);

// setters

void setCustomerName(Customer customer, char name[]);
void setCustomerId(Customer customer, int id);
void setCustomerMoney(Customer customer, float money);

// destroyer
void customerDestructor(Customer customer);

#endif // CUSTOMER_H_INCLUDED
