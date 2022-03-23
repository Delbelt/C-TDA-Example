#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED

struct BankStruct; // structure signature

typedef struct BankStruct *Bank; // pointer to a structure

Bank constructorBank(char name[20], int customersAmount);

void toStringBank(Bank bank); // show the bank
void modifyBank(Bank bank); // modify attributes of bank

// getters

char *getBankName(Bank bank);
int getCustomersAmount(Bank bank);

// setters

void setBankName(Bank bank, char name[]);
void setCustomersAmount(Bank bank, int amount);


// TODO add destroyer

#endif // BANK_H_INCLUDED
