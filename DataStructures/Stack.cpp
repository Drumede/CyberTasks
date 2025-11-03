#include "Stack.h"
#include <iostream>
using namespace std;

void push(Stack* s, unsigned int element)
{
	if (isEmpty(s)) {
		s->data = element;
		s->next = nullptr;
		return;
	}
	Stack* oldNode = new Stack();
	initStack(oldNode);
	oldNode->data = s->data;
	oldNode->next = s->next;
	s->data = element;
	s->next = oldNode;
}

int pop(Stack* s) {
	if (isEmpty(s))
		return -1;
	if (s->next == nullptr) {
		int oldData = s->data;
		s->data = -1;
		return oldData;
	}
	int oldData = 0;
	Stack* oldNext = s->next;
	oldData = oldNext->data;
	s->data = oldNext->data;
	s->next = oldNext->next;
	delete oldNext;
	return oldData;
}

void initStack(Stack* s) {
	s->data = -1;
	s->next = nullptr;
}

void cleanStack(Stack* s) {
	Stack* lasttemp = s;
	Stack* temp = s->next;
	while (temp != nullptr) {
		lasttemp = temp;
		delete(lasttemp);
		temp = lasttemp->next;
	}
	s->data = -1;
}

bool isEmpty(Stack* s) {
	if (s->data == -1)
		return true;
	return false;
}
bool isFull(Stack* s) {
	return false;
}