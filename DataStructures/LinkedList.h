#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedList
{
	int data;
	LinkedList* next;
	LinkedList(int val) : data(val), next(nullptr) {}


} LinkedList;

void pushList(LinkedList* l, unsigned int val);
void popList(LinkedList* l);

#endif /* LINKEDLIST_H */