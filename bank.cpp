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

Bank constructorBank(char name[20])
{
    Bank bank = new BankStruct; // memory instance - dynamic memory

    // variables assignment
    strcpy(bank-> name, name);
    bank-> customersAmount = 0;

    int i;

    for(i = 0; i < CUSTOMER_TOTAL; i++)
    {
        bank-> customers[i] = constructorCustomer("empty", -1); // create empty customers
    }

    return bank;
}

void toStringBank(Bank bank)
{
    printf("\nBank name: %s ---- Customers amount: %d \n\n", getBankName(bank), getCustomersAmount(bank));
}

void showCustomers(Bank bank)
{
    int i;

    printf("CUSTOMERS\n");

    for(i = 0; i < CUSTOMER_TOTAL; i++)
    {
        if(getCustomerId(bank-> customers[i]) != -1) // prevent show empty customers
        {
            toStringCustomer(bank-> customers[i]); // show bank's customers
            printf("\n"); // new line
        }
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

int searchEmptySpace(Bank bank)
{
	int pos = -1; // flag and position
	int i = 0;

    while(i < CUSTOMER_TOTAL && pos == -1) // break the loop in case find empty pos
    {
        if(getCustomerId(bank-> customers[i]) == -1)
        {
            pos = i;
        }
            i++;
    }

    return pos; // first position empty
}

int searchID(Bank bank, int customerID)
{
	int condition = -1; // flag and conditional
	int i = 0;

	while(i < CUSTOMER_TOTAL && condition == -1)
	{
		if(getCustomerId(bank-> customers[i]) == customerID)
		{
			condition = 1;
		}

		else
		{
			if (i + 1 == CUSTOMER_TOTAL)
			{
				condition = 0;
			}
		}
                i++;
	}

	return condition;
}

void addCustomer(Bank bank, Customer customer)
{
	int emptyPlace = searchEmptySpace(bank); // save the empty position

	int repeat = searchID(bank, getCustomerId(customer)); // verify ID

    // repeat value 0: mean that the ID value customer doesn't exist into the bank
	// repeat value 1: mean that the ID value customer exist into the bank

	if (repeat == 0)
	{
		bank-> customers[emptyPlace] = customer;
		setCustomersAmount(bank, emptyPlace + 1);

		printf ("customer [%s] successfully added\n", getCustomerName(customer));
	}

	else // repeat == 1
	{
		printf ("customer already registered, ID: [%d] \n", getCustomerId(customer)); //PARA AVISAR AL USUARIO QUE NO ES POSIBLE AGREGARLO
	}
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
