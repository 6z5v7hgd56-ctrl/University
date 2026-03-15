#include "stdio.h"
#include "algorithms.h"

void analyze(const int *arr, size_t n, int *min, int *max, long long *sum)
{
    int min;
    int max;
    int sum;

    min = arr[0];
    max = arr[0];
    sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < min) 
            min = arr[i];
        if (arr[i] > max) 
            max = arr[i];
        sum += arr[i];
    }
}