#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED

struct BankStruct; // structure signature

typedef struct BankStruct *Bank; // pointer to a structure

Bank constructorBank(char name[20], int customersAmount);

// show the bank
void toStringBank(Bank bank);

// TODO add destroyer, getters and setters

#endif // BANK_H_INCLUDED
