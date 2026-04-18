#include <stdio.h>
#include <stdlib.h>
#include "algorithms.h"
//#include <time.h>

void swap(int **dataArray, int i, int j)
{
    (*dataArray)[i] = (*dataArray)[i] + (*dataArray)[j];
    (*dataArray)[j] = (*dataArray)[i] - (*dataArray)[j];
    (*dataArray)[i] = (*dataArray)[i] - (*dataArray)[j];
}

int* selectionSort(int *arr, size_t length, int *comparisonCount, int *swapCount) 
{
    int j, i;

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
}

int* insertionSort(int *arr, size_t length, int *comparisonCount, int *swapCount) 
{

    int key, i, j;

    *comparisonCount = 0;
    *swapCount = 0;
    key = 0;
    i = 0;
    j = 0;

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
        (*comparisonCount)++;

        arr[j + 1] = key;
    }
}

int* bubbleSort(int *unsortedArray, size_t length, int *comparisonCount, int *swapCount)
{
    _Bool isSwapped;
    int i;

    isSwapped = 0;
    *comparisonCount = 0;
    *swapCount = 0;

    do
    {
        isSwapped = 0;
        for (i = 1; i < length - 1; ++i)
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






void writeArray(const int arr[], const size_t n)
{
    size_t i;
    i = 0;

    if (arr != NULL && n != 0)
    {
        for (i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else
        printf("Ошибка состояния массива.\n");
}