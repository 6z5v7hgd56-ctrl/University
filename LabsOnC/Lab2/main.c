#include "stdio.h"
#include "stdlib.h"
#include "algorithms.h"
#include "locale.h"

int main(void) 
{
    int* arr;
    size_t n;
    int min, max;
    long long sum;

    arr = NULL;
    min = 0;
    max = 0;
    sum = 0ll;
    n = 0;


    setlocale(LC_ALL, "Russian");
    fillArray(&arr, &n);
    writeArray(arr, n);

    // 1
    analyze(arr, n, &min, &max, &sum);
    printf("%d  %d  %d\n", min, max, sum);

    // 2
    filter(&arr, &n);
    writeArray(arr, n);

    free(arr);
    arr = NULL;
    return 0;
}