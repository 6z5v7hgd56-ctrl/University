#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <stdlib.h>

int* selectionSort(int *unsortedArray, size_t length, long long *comparisonCount, long long *swapCount);
int* insertionSort(int *unsortedArray, size_t length, long long *comparisonCount, long long *swapCount);
int* bubbleSort(int *unsortedArray, size_t length, long long *comparisonCount, long long *swapCount);

void swap(int *arr, int i, int j);

#endif 