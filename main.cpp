#include <iostream>
#include <cstring>

// TDA's libraries
#include "bank.h"
#include "customer.h"
#include "local_date.h"
#include "local_time.h"
#include "linked_list.h"

using namespace std;

// definitions

int main()
{
    int length;

    LinkedList List = linkedList();

    insertStart(List, 51); // [51]
    insertStart(List, 77); // [77, 51]
    insertPosition(List, 99, 1); // [77, 99, 51]
    insertEnd(List, 43); // [77, 99, 51, 43]

    //removeStart(List); // [99, 51, 43]
    //removePosition(List, 1); // [77, 51, 43]
    //removeEnd(List); // [77, 99, 51]

    toStringList(List); // show the list, expected output: [77, 99, 51, 43]

    getSize(List, &length); // get size to list
    cout << "length: " << length << endl; // expected output: length: 4

    destructorList(List);

    //cout << "" << endl; // new line

    return 0;
}

// implementations
