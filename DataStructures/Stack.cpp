#include "Stack.h"
#include <iostream>
using namespace std;

void push(Stack* s, unsigned int element)
{
	Stack* oldNode = new Stack();
	initStack(oldNode)
	oldNode->next = s->next;
	s->data = val;
	s->next = oldNode;
}

int pop(Stack* s) {
	if (isEmpty(s))
		return -1;
	Stack* oldNext = s->next;
	s->data = oldNext->data;
	s->next = oldNext->next;
	delete oldNext;
}

void initStack(Stack* s) {
	s->data = 0;
	s->next = nullptr;
}

void cleanStack(Stack* s) {
	if (s->next == nullptr) {
		delete(s);
		return;
	}
	cleanStack(s->next);
	delete(s);
}

bool isEmpty(Stack* s) {
	if (s == nullptr)
		return true;
	return false;
}
bool isFull(Stack* s) {
	return false;
}