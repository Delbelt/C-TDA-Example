#include <iostream>
#include <cstring>

#include "customer.h" // header

struct CustomerStruct
{
    char name[20];
    int id;
    float money;
};

Customer constructorCustomer(char name[20], int id, float money)
{
    Customer customer = new CustomerStruct; // memory instance

    // variables assignament
    strcpy(customer-> name, name);
    customer-> id = id;
    customer-> money = money;

    return customer;
}

void toStringCustomer(Customer customer)
{
    printf("Customer name: %s ---- ID: %d ---- Money %.2f",
    getCustomerName(customer), getCustomerId(customer), getCustomerMoney(customer));
}

void modifyCustomer(Customer customer)
{
    // variables aux
    char nameAux[20];
    int idAux;

    printf("Name: ");
    fflush(stdin);
    gets(nameAux);

    printf("\nId: ");
    scanf("%d", &idAux);

    setCustomerName(customer, nameAux);
    setCustomerId(customer, idAux);

    printf("customer modified successfully!!!\n");
}

// getters

char *getCustomerName(Customer customer)
{
    return customer-> name;
}

int getCustomerId(Customer customer)
{
	return customer-> id;
}

float getCustomerMoney(Customer customer)
{
	return customer-> money;
}

// setters

void setCustomerName(Customer customer, char name[])
{
	strcpy(customer-> name, name);
}

void setCustomerId(Customer customer, int id)
{
	customer-> id = id;
}

void setCustomerMoney(Customer customer, float money)
{
	customer-> money = money;
}

void customerDestructor(Customer customer)
{
    delete customer; // free memory
}
