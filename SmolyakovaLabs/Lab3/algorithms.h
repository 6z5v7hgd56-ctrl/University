#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <stdlib.h>

void swap(int **dataArray, int i, int j);

int* selectionSort(int *arr, size_t length, int *comparisonCount, int *swapCount);
int* insertionSort(int *arr, size_t length, int *comparisonCount, int *swapCount);
int* bubbleSort(int *unsortedArray, size_t length, int **sortedArray, int *comparisonCount, int *swapCount);

void writeArray(const int arr[], const size_t n);

#endif 