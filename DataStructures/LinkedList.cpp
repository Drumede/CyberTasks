#include "LinkedList.h"
#include <iostream>
using namespace std;

void pushList(LinkedList* l, unsigned int val) {
	LinkedList* oldNode = new LinkedList(l->data);
	oldNode->next = l->next;
	l->data = val;
	l->next = oldNode;
}

void popList(LinkedList* l) {
	LinkedList* oldNext = l->next;
	l->data = oldNext->data;
	l->next = oldNext->next;
	delete oldNext;
}

