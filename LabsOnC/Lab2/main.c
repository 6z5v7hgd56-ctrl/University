#include "stdio.h"
#include "stdlib.h"
#include "algorithms.h"
#include "locale.h"

int main(void) 
{
    int* arr;
    size_t n;

    setlocale(LC_ALL, "Russian");
    fillArray(&arr, &n);
    printf("¬ведЄнный массив: ");
    writeArray(arr, n);

    output1(arr, n);
    output2(&arr, &n);
    output3(arr, n);
    output4(arr, n);
    output5(&arr, &n);

    free(arr);
    arr = NULL;
    return 0;
}