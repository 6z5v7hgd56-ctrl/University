#include "stdio.h"
#include "stdlib.h"
#include "algorithms.h"
#include "locale.h"

int main(void) 
{
    int* arr;
    size_t n;
    int min, max, maxSeq;
    long long sum;

    arr = NULL;
    min = 0;
    max = 0;
    maxSeq = 0;
    sum = 0ll;
    n = 0;


    setlocale(LC_ALL, "Russian");
    fillArray(&arr, &n);
    writeArray(arr, n);

    // 1
    printf("\n====1====\n");
    analyze(arr, n, &min, &max, &sum);
    printf("%d  %d  %d\n", min, max, sum);

    // 2
    printf("\n====2====\n");
    filter(&arr, &n);
    writeArray(arr, n);

    // 3
    printf("\n====3====\n");
    maxSeq = maxSequentially(arr, n);
    printf("%d", maxSeq);

    free(arr);
    arr = NULL;
    return 0;
}