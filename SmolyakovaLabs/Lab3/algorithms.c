#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "algorithms.h"
//#include <time.h>

// struct SortMetrics
// {
//     long long comparisons;
//     long long swaps;
// };

// void swap(int **dataArray, int i, int j)
// {
//     (*dataArray)[i] = (*dataArray)[i] + (*dataArray)[j];
//     (*dataArray)[j] = (*dataArray)[i] - (*dataArray)[j];
//     (*dataArray)[i] = (*dataArray)[i] - (*dataArray)[j];
// }

void swap(int *arr, int i, int j)
{
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


int* selectionSort(int *unsortedArray, size_t length, long long *comparisonCount, long long *swapCount) 
{
    int j, i, temp;
    int *sortedArray;

    temp = 0;

    sortedArray = (int*)malloc(length * sizeof(int));

    memcpy(sortedArray, unsortedArray, length * sizeof(int));

    *comparisonCount = 0ll;
    *swapCount = 0ll;

    for (i = 0; i < length - 1; ++i) 
    {
      
        int min_idx = i;
        
        for (j = i + 1; j < length; ++j) 
        {
            if (sortedArray[j] < sortedArray[min_idx]) 
            {
                min_idx = j;
            }
            (*comparisonCount)++;
        }
        
        temp = sortedArray[i];
        sortedArray[i] = sortedArray[min_idx];
        sortedArray[min_idx] = temp;
        (*swapCount)++;
    }

    return sortedArray;
}

int* insertionSort(int *unsortedArray, size_t length, long long *comparisonCount, long long *swapCount) 
{
    int key, i, j;
    int *sortedArray;

    sortedArray = (int*)malloc(length * sizeof(int));

    memcpy(sortedArray, unsortedArray, length * sizeof(int));

    *comparisonCount = 0ll;
    *swapCount = 0ll;
    key = 0;

    for (i = 1; i < length; i++) 
    {
        key = sortedArray[i]; 
        j = i - 1;

        while (j >= 0 && sortedArray[j] > key) 
        {
            sortedArray[j + 1] = sortedArray[j];
            j--;
            (*swapCount)++;
            (*comparisonCount)++; // ???
        }

        (*comparisonCount)++;
        sortedArray[j + 1] = key;
    }

    return sortedArray;
}

int* bubbleSort(int *unsortedArray, size_t length, long long *comparisonCount, long long *swapCount)
{
    _Bool isSwapped;
    int i;
    int *sortedArray;

    sortedArray = (int*)malloc(length * sizeof(int));

    memcpy(sortedArray, unsortedArray, length * sizeof(int));

    isSwapped = 0;
    *comparisonCount = 0ll;
    *swapCount = 0ll;

    do
    {
        isSwapped = 0;
        for (i = 1; i < length; ++i)
        {
            if (sortedArray[i - 1] > sortedArray[i])
            {
                swap(sortedArray, i - 1, i);
                isSwapped = 1;
                (*swapCount)++;
            }
            (*comparisonCount)++;
        }

    } while (isSwapped);
    
    return sortedArray; 
}

