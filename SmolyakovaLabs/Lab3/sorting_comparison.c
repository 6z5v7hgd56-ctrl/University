#include <stdio.h>
#include <stdlib.h>
#include "algorithms.h"

// 20 массив из случайных чисел с неравномерным распределением
// 31 массив с равномерно распределёнными повторениями
// 28 массив с чередующимися возрастающими и убывающими сериями
// 6 почти отсортированный массив (несколько элементов переставлены)
// 15 массив со случайными данными и небольшим числом инверсий

int main(void) // Вариант 20
{
    int length;
    int arr[] = {50, 2, -32, 34, 17, 555, 999, -213, 1, 2};
    int *sorted;
    // cc = comparisonCount, sc = swapCount
    int cc1, sc1;

    length = 10;
    cc1 = 0;
    sc1 = 0;

    sorted = insertionSort(arr, 10, &cc1, &sc1);

    writeArray(sorted);
    printf("cc = %d, sc = %d\n", cc1, sc1);



    return 0;
}



