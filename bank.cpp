#include <iostream>
#include <cstring>

#include "bank.h" // header
#include "customer.h" // important!!! include customer.h

#define CUSTOMER_TOTAL 10 // const

struct BankStruct
{
    char name[20];
    int customersAmount;
    Customer customers[CUSTOMER_TOTAL];
};

Bank constructorBank(char name[20], int customersAmount)
{
    Bank bank = new BankStruct; // memory instance - dynamic memory

    // variables assignment
    strcpy(bank-> name, name);
    bank-> customersAmount = customersAmount;

    int i;

    for(i = 0; i < CUSTOMER_TOTAL; i++)
    {
        bank-> customers[i] = constructorCustomer("empty", -1); // create empty customers
    }

    return bank;
}

void toStringBank(Bank bank)
{
    printf("Bank name: %s ---- Customers amount: %d", getBankName(bank), getCustomersAmount(bank));

    int i;

    printf("\n\nCUSTOMERS\n");

    for(i = 0; i < CUSTOMER_TOTAL; i++)
    {
        toStringCustomer(bank-> customers[i]); // show bank's customers
        printf("\n"); // new line
    }
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

void bankDestructor(Bank bank)
{
    delete bank; // free memory
}
