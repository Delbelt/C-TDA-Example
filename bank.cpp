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
    printf("Bank name: %s ---- Customers amount: %d", getBankName(bank), getCustomersAmount(bank));
}

void modifyBank(Bank bank)
{
    // variables aux
    char nameAux[20];
    int customersAmountAux;

    printf("Name: ");
    fflush(stdin);
    gets(nameAux);

    printf("\nCustomers amount: ");
    scanf("%d", &customersAmountAux);

    setBankName(bank, nameAux);
    setCustomersAmount(bank, customersAmountAux);

    printf("bank modified successfully!!!\n");
}

// getters

char *getBankName(Bank bank)
{
    return bank-> name;
}

int getCustomersAmount(Bank bank)
{
	return bank-> customersAmount;
}

// setters

void setBankName(Bank bank, char name[])
{
	strcpy(bank-> name, name);
}

void setCustomersAmount(Bank bank, int amount)
{
	bank-> customersAmount = amount;
}
