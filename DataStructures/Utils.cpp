#include "Utils.h"
#include "Stack.h"
#include <iostream>
using namespace std;

void reverse(int* nums, unsigned int size) {
	Stack* s = new Stack;
	initStack(s);
	int i = 0;
	for (i = 0; i < size; i++) {
		push(s, nums[i]);
	}
	i = 0;
	while (!isEmpty(s)) {
		nums[i] = s->data;
		i++;
		pop(s);
	}
}

int* reverse10() {
	return 0;
}