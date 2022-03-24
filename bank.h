#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED

#include "customer.h"

struct BankStruct; // structure signature

typedef struct BankStruct *Bank; // pointer to a structure

Bank constructorBank(char name[20]);

void toStringBank(Bank bank); // show the bank
void showCustomers(Bank bank); // show bank's customers

void modifyBank(Bank bank); // modify attributes of bank
int searchEmptySpace(Bank bank); // search empty space into customers list
int searchID(Bank bank, int customerID); // verify if already register customer (ID) into the bank
void addCustomer(Bank bank, Customer customer); // add Customer into the bank

// getters

char *getBankName(Bank bank);
int getCustomersAmount(Bank bank);

// setters

void setBankName(Bank bank, char name[]);
void setCustomersAmount(Bank bank, int amount);

// destroyer
void bankDestructor(Bank bank);

#endif // BANK_H_INCLUDED
