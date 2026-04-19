#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <stdlib.h>

void swap(int **dataArray, int i, int j);

int* selectionSort(int *arr, size_t length, long long *comparisonCount, long long *swapCount);
int* insertionSort(int *arr, size_t length, long long *comparisonCount, long long *swapCount);
int* bubbleSort(int *unsortedArray, size_t length, long long *comparisonCount, long long *swapCount);

int* generateNonuniformRandomArray(size_t length);

void writeArray(const int arr[], const size_t n);

#endif 