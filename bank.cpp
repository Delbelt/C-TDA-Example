#include <iostream>
#include <cstring>

#include "bank.h" // header

struct BankStruct
{
    char name[20];
    int customersAmount;
};

Bank constructorBank(char name[20], int customersAmount)
{
    Bank bank = new BankStruct; // memory instance

    // variables assignment
    strcpy(bank-> name, name);
    bank-> customersAmount = customersAmount;

    return bank;
}

void toStringBank(Bank bank)
{
    printf("Bank name: %s ---- Customers amount: %d", bank-> name, bank-> customersAmount);
}
