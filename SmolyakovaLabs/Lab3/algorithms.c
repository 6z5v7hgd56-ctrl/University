#include <stdio.h>
#include <stdlib.h>
#include "algorithms.h"
//#include <time.h>

// struct SortMetrics
// {
//     long long comparisons;
//     long long swaps;
// };

void swap(int **dataArray, int i, int j)
{
    (*dataArray)[i] = (*dataArray)[i] + (*dataArray)[j];
    (*dataArray)[j] = (*dataArray)[i] - (*dataArray)[j];
    (*dataArray)[i] = (*dataArray)[i] - (*dataArray)[j];
}

int* selectionSort(int *arr, size_t length, long long *comparisonCount, long long *swapCount) 
{
    int j, i;

    *comparisonCount = 0ll;
    *swapCount = 0ll;

    for (i = 0; i < length - 1; ++i) 
    {
      
        int min_idx = i;
        
        for (j = i + 1; j < length; ++j) 
        {
            if (arr[j] < arr[min_idx]) 
            {
                min_idx = j;
            }
            (*comparisonCount)++;
        }
        
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
        (*swapCount)++;
    }

    return arr;
}

int* insertionSort(int *arr, size_t length, long long *comparisonCount, long long *swapCount) 
{

    int key, i, j;

    *comparisonCount = 0ll;
    *swapCount = 0ll;
    key = 0;

    for (i = 1; i < length; i++) 
    {
        key = arr[i]; 
        j = i - 1;

        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
            (*swapCount)++;
            (*comparisonCount)++; // ???
        }
        if (j >= 0)
            (*comparisonCount)++;

        arr[j + 1] = key;
    }

    return arr;
}

int* bubbleSort(int *unsortedArray, size_t length, long long *comparisonCount, long long *swapCount)
{
    _Bool isSwapped;
    int i;

    isSwapped = 0;
    *comparisonCount = 0ll;
    *swapCount = 0ll;

    do
    {
        isSwapped = 0;
        for (i = 1; i < length; ++i)
        {
            if (unsortedArray[i - 1] > unsortedArray[i])
            {
                swap(&unsortedArray, i - 1, i);
                isSwapped = 1;
                (*swapCount)++;
            }
            (*comparisonCount)++;
        }

    } while (isSwapped);
    
    return unsortedArray; 
}

int* generateNonuniformRandomArray(size_t length)
{
    const int MAX_ELEMENT = 10000;
    int i;
    int *arr;

    arr = (int*)malloc(length * sizeof(int));

    for (i = 0; i < length; ++i)
    {
        arr[i] = rand() % (MAX_ELEMENT / 2 + 1) + rand() % (MAX_ELEMENT / 2 + 1);
    }

    return arr;
}






void writeArray(const int *arr, const size_t n)
{
    size_t i;
    i = 0;

    if (arr != NULL && n != 0)
    {
        printf("BB %d %d\n", n, i);
        for (i = 0; i < n; ++i)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else
        printf("Ошибка состояния массива.\n");
}