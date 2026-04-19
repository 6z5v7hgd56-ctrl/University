#include <stdio.h>
#include <stdlib.h>
#include "algorithms.h"

// 20 массив из случайных чисел с неравномерным распределением
// 31 массив с равномерно распределёнными повторениями
// 28 массив с чередующимися возрастающими и убывающими сериями
// 6 почти отсортированный массив (несколько элементов переставлены)
// 15 массив со случайными данными и небольшим числом инверсий

// Элементы массива в диапазоне от 0..10000

int main(void) // Вариант 20
{
    int length;
    int *arr;
    int *sorted;
    long long cc1, sc1;

    // cc = comparisonCount, sc = swapCount
    //arr = (int*)malloc(10 * sizeof(int));
    sorted = (int*)malloc(10 * sizeof(int));

    // arr[0] = 990;
    // arr[1] = 15;
    // arr[2] = 44;
    // arr[3] = 42;
    // arr[4] = 1;
    // arr[5] = 3;
    // arr[6] = 2;
    // arr[7] = -239;
    // arr[8] = -1;
    // arr[9] = 15;

    length = 20;
    cc1 = 0;
    sc1 = 0;

    arr = generateNonuniformRandomArray((size_t)length);

    sorted = selectionSort(arr, length, &cc1, &sc1);

    writeArray(sorted, (size_t)length);
    
    printf("cc = %d, sc = %d\n", cc1, sc1);



    free(sorted);
    free(arr);
    return 0;
}



