#include <iostream>

#include "linked_list.h" // header

// definitions

#define OK               1
#define FALSE            0
#define NOT_INITIALIZED -1
#define IS_EMPTY        -2
#define INDEX_INVALID   -3
#define IS_NULL         -4

struct NodeStruct // node struct
{
    int value; // value
    Node next; // points null node or next node
};

struct LinkedListStruct // list struct
{
    int length; // save length of the arrayList
    Node initial; // return first position of NodeStruct
};

Node constructorNode(int value, Node next)
{
    Node node = new NodeStruct; // dynamic memory

    node-> value   = value;
    node-> next    = next;

    return node;
}

LinkedList linkedList()
{
    LinkedList linkedList = new LinkedListStruct; // dynamic memory

    linkedList-> initial = NULL;
    linkedList-> length  = 0;

    return linkedList;
}

// functions
int isEmpty(LinkedList linkedList)
{
    if(linkedList == NULL || linkedList-> initial == NULL) return OK; // is empty !!!

    return FALSE; // not empty
}

int getElement(LinkedList linkedList, int *value, int position)
{
    // exceptions
    char origin[11] = "getElement"; // prevent warning: ISO C++ forbids converting a string constant to 'char*'

    if(linkedList == NULL) return handleException(NOT_INITIALIZED, origin); // list not initialized
    if(isEmpty(linkedList)) return handleException(IS_EMPTY, origin); // list is empty
    if(position < 0 || position >= linkedList-> length) return handleException(INDEX_INVALID, origin); // index invalid
    if(value == NULL) return handleException(IS_NULL, origin); // value is null

    Node node = linkedList-> initial;

    int index;

    for(index = 0; index < position; index++)
    {
        node = node -> next;
    }

    *value = node-> value; // value assigned to node variable

    return OK;
}

int getSize(LinkedList linkedList, int *length)
{
    // exceptions
    char origin[8] = "getSize"; // prevent warning: ISO C++ forbids converting a string constant to 'char*'

    if(linkedList == NULL) return handleException(NOT_INITIALIZED, origin); // list not initialized
    if(length == NULL) return handleException(IS_NULL, origin); // value is null

    *length = linkedList->length;

    return OK;
}

void toStringList(LinkedList linkedList)
{
    int index, sizeElement, element;

    getSize(linkedList, &sizeElement);

    printf("[");

    for(index = 0; index < sizeElement; index ++)
    {
        getElement(linkedList, &element, index);
        printf(" %d ", element);
    }

    printf("]\n");
}

// inserts
int insertStart(LinkedList linkedList, int value)
{
    // exception
    char origin[12] = "insertStart"; // prevent warning: ISO C++ forbids converting a string constant to 'char*'
    if(linkedList == NULL) return handleException(IS_NULL, origin); // is null

    Node node = constructorNode(value, linkedList-> initial); // new node instance

    // initial is now the next node

    linkedList-> initial = node; // new node is now the initial node
    linkedList-> length ++; // increase the length to list

    return OK;
}

int insertPosition(LinkedList linkedList, int value, int pos)
{
    // exceptions
    char origin[15] = "insertPosition"; // prevent warning: ISO C++ forbids converting a string constant to 'char*'

    if(linkedList == NULL) return handleException(IS_NULL, origin); // list not initialized
    if(pos < 0 || pos > linkedList-> length) return handleException(INDEX_INVALID, origin); // index invalid

    // in case to position be the initial
    if(pos == 0) return insertStart(linkedList, value);

    Node nodeAux = linkedList-> initial; // auxiliary take the role of initial node

    int index;

    for(index = 0; index < pos -1; index ++) nodeAux = nodeAux-> next; // auxiliary take the next position of node in every iteration

    Node node = constructorNode(value, nodeAux-> next); // new node initialized

    nodeAux-> next = node; // auxiliary is now the next node

    linkedList-> length ++;

    return OK; // OK
}

int insertEnd(LinkedList linkedList, int value)
{
    return insertPosition(linkedList, value, linkedList-> length);
}

// removes
int removeStart(LinkedList linkedList)
{
    // exceptions
    char origin[15] = "removeStart"; // prevent warning: ISO C++ forbids converting a string constant to 'char*'

    if(linkedList == NULL) return handleException(NOT_INITIALIZED, origin); // list not initialized
    if(isEmpty(linkedList)) return handleException(IS_EMPTY, origin); // list is empty

    Node nodeAux = linkedList-> initial; // auxiliary take the value on list initial

    linkedList-> initial = nodeAux-> next; // list initial take the value of next node

    delete nodeAux; // free memory
    nodeAux = NULL; // assing NULL value to node Auxiliary

    linkedList-> length --; // decrease the length to list

    return OK; // OK
}

int removePosition(LinkedList linkedList, int pos)
{
    // exceptions
    char origin[15] = "removePosition"; // prevent warning: ISO C++ forbids converting a string constant to 'char*'

    if(linkedList == NULL) return handleException(NOT_INITIALIZED, origin); // list not initialized
    if(isEmpty(linkedList)) return handleException(IS_EMPTY, origin); // list is empty
    if(pos < 0 || pos >= linkedList-> length) return handleException(INDEX_INVALID, origin); // index invalid

    // in case to position be the initial
    if(pos == 0) return removeStart(linkedList);

    else
    {
        Node nodePrevious = NULL; // is a auxiliary
        Node nodeCurrent = linkedList-> initial; // current node take value to list initial

        int index;

        for(index = 0; index < pos; index ++) // iterate over list nodes
        {
            nodePrevious = nodeCurrent; // take the value to current node
            nodeCurrent = nodeCurrent-> next; // current node is now next node
        }

        nodePrevious-> next = nodeCurrent-> next;

        delete(nodeCurrent); // free memory
        nodeCurrent = NULL; // assing NULL value to node current
    }

    linkedList->length --; // decrease the length to list

    return OK; // OK
}

int removeEnd(LinkedList linkedList)
{
    return removePosition(linkedList, linkedList-> length - 1);
}

int handleException(int error, char *origin)
{
    switch(error)
    {
        case -1: printf("EXCEPTION: NOT INITIALIZED (%s)\n", origin); break;
        case -2: printf("EXCEPTION: IS EMPTY (%s)\n", origin); break;
        case -3: printf("EXCEPTION: INDEX INVALID (%s)\n", origin); break;
        case -4: printf("EXCEPTION: IS NULL (%s)\n", origin); break;
        default: printf("EXCEPTION: ERROR NOT CATCH OR NOT IMPLEMENT (%s)\n", origin); break;
    }

    return error;
}

// destroyer
int destructorList(LinkedList linkedList)
{
    // exception
    char origin[15] = "destructorList"; // prevent warning: ISO C++ forbids converting a string constant to 'char*'
    if(linkedList == NULL) return handleException(NOT_INITIALIZED, origin); // list not initialized

    while(! isEmpty(linkedList)) removeStart(linkedList); // remove all items to list

    linkedList-> initial = NULL; // assing NULL value to node initial
    linkedList-> length = 0; // reset length

    delete linkedList; // free memory

    return OK; // OK
}
