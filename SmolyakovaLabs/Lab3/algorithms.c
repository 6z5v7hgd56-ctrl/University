#include <stdio.h>
#include <stdlib.h>
#include "algorithms.h"

void swap(int **dataArray, int i, int j)
{
    (*dataArray)[i] = (*dataArray)[i] + (*dataArray)[j];
    (*dataArray)[j] = (*dataArray)[i] - (*dataArray)[j];
    (*dataArray)[i] = (*dataArray)[i] - (*dataArray)[j];
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