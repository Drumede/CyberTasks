#include "Queue.h"
#include <iostream>
using namespace std;

void initQueue(Queue* q, unsigned int size) {
	q->capacity = size;
	q->arr = new int[size];
	q->front = 0;
	q->size = 0;
	q->rear = 0;
}

void cleanQueue(Queue* q) {
	delete[] q->arr;
}

void enqueue(Queue* q, unsigned int newValue) {
	if (isFull(q)) {
		return;
	}
	q->rear = (q->rear + 1) % q->capacity;
	q->arr[q->rear] = newValue;
	q->size++;
}

int dequeue(Queue* q) {
	if (isEmpty(q)) {
		return -1;
	}
	q->front = (q->front + 1) % q->capacity;
	q->size--;
	return q->arr[q->front];
}

bool isEmpty(Queue* s) {
	if (s->size == 0) {
		return true;
	}
	return false;
}

bool isFull(Queue* s) {
	if (s->size == s->capacity) {
		return true;
	}
	return false;
}