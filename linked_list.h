#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

struct NodeStruct; // structure signature

typedef struct NodeStruct *Node; // pointer to a structure

struct LinkedListStruct; // structure signature

typedef struct LinkedListStruct *LinkedList; // pointer to a structure

// constructors
Node node(int value, Node next);
LinkedList linkedList();

// functions
int isEmpty(LinkedList linkedList);
int getElement(LinkedList linkedList, int *value, int position);
int getSize(LinkedList linkedList, int *length);

void toStringList(LinkedList linkedList); // show the List

// inserts
int insertStart(LinkedList linkedList, int value);
int insertPosition(LinkedList linkedList, int value, int position);
int insertEnd(LinkedList linkedList, int value);

// removes
int removeStart(LinkedList linkedList);
int removePosition(LinkedList linkedList, int position);
int removeEnd(LinkedList linkedList);

int handleException(int error, char *origin); // exceptions

int destructorList(LinkedList linkedList); // destroyer

#endif // LINKED_LIST_H_INCLUDED
