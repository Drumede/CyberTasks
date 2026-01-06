#pragma once
#include <iostream>

/*
 Section A – compare
 Compares two values of the same type.
 Returns:
 -1 if the first is greater than the second
  0 if they are equal
  1 if the first is smaller than the second
 The type T must support operators > and ==
*/
template <typename T>
int compare(const T& a, const T& b)
{
	if (a > b)
		return -1;
	if (b > a)
		return 1;
	return 0;
}

/*
 Section B – bubbleSort
 Sorts an array of type T from smallest to largest
 using the Bubble Sort algorithm.
 The type T must support operator >
*/
template <typename T>
void bubbleSort(T arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

/*
 Section C – printArray
 Prints all elements of an array.
 Each element is printed on a separate line.
 The type T must support operator <<
*/
template <typename T>
void printArray(const T arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}
