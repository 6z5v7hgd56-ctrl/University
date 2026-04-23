#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "algorithms.h"

void writePurpose()
{
    printf("Программа генерирует массивы из элементов в диапазоне [-10000,10000] по определённым правилам или обладающим определёнными свойствами. Далее сортирует каждый массив тремя способами и отображает в таблице сравнительную характеристику по количеству сравнений среди элементов и их обменов.\n");
}

void printAnalysis()
{
    printf("Вывод: в среднем, лучшей сортировкой можно считать сортировку вставками. ");
}

void printTableOnNonuniformGeneratedArray(int* arr, int length)
{
    long long compCount, swapCount;
    int *sorted;
    int i, whatSortIsBetter, sortIndex; //0 - Bubble   1 - Insertion  2 - Selection 

    sortIndex = 0;
    whatSortIsBetter = 0;

    compCount = 0;
    swapCount = 0;

    printf("Не отсортированный массив из случайных чисел с неравномерным распределением:\n");
    writeArray(arr, length);
    
    sorted = bubbleSort(arr, length, &compCount, &swapCount);
    printf("\nПосле сортировки:\n");
    writeArray(sorted, length);
    printf("\n");

    printf("/=_Массив из случайных чисел с неравномерным распределением_=\\\n");
    printf("|____________________________________________________________|\n");
    printf("| Размер |    Алгоритм    | Число сравнений | Число обменов  |\n");
    printf("|------------------------------------------------------------|\n");
    printf("| %6d | Bobble sort    | %-15d | %-14d |\n", length, compCount, swapCount);
    
    sortIndex = compCount + swapCount * 3;

    compCount = 0;
    swapCount = 0;

    sorted = insertionSort(arr, length, &compCount, &swapCount);

    printf("|--------|----------------|-----------------|----------------|\n");
    printf("| %6d | Insertion sort | %-15d | %-14d |\n", length, compCount, swapCount);

    if (sortIndex > compCount + swapCount * 3)
    {
        sortIndex = compCount + swapCount * 3;
        whatSortIsBetter = 1;
    }

    compCount = 0;
    swapCount = 0;

    sorted = selectionSort(arr, length, &compCount, &swapCount);

    printf("|--------|----------------|-----------------|----------------|\n");
    printf("| %6d | Selection sort | %-15d | %-14d |\n", length, compCount, swapCount);
    printf("\\------------------------------------------------------------/\n\n");

    if (sortIndex > compCount + swapCount * 3)
    {
        sortIndex = compCount + swapCount * 3;
        whatSortIsBetter = 2;
    }

    switch(whatSortIsBetter)
    {
        case 0: 
            printf("Лучшей при генерации массива из случайных чисел с неравномерным распределением считается сортировка пузырьком.\n\n\n");
            break;
        case 1: 
            printf("Лучшей при генерации массива из случайных чисел с неравномерным распределением считается сортировка вставками.\n\n\n");
            break;
        case 2: 
            printf("Лучшей при генерации массива из случайных чисел с неравномерным распределением считается сортировка выбором.\n\n\n");
            break;
    }

}

void printTableOnArrayWithUniformRepetitions(int* arr, int length)
{
    long long compCount, swapCount;
    int *sorted;
    int i, whatSortIsBetter, sortIndex; //0 - Bubble   1 - Insertion  2 - Selection 

    sortIndex = 0;
    whatSortIsBetter = 0;

    compCount = 0;
    swapCount = 0;

    printf("Не отсортированный массив с равномерно распределёнными повторениями:\n");
    writeArray(arr, length);
    
    sorted = bubbleSort(arr, length, &compCount, &swapCount);
    printf("\nПосле сортировки:\n");
    writeArray(sorted, length);
    printf("\n");

    printf("/=_____Массив с равномерно распределёнными повторениями_____=\\\n");
    printf("|____________________________________________________________|\n");
    printf("| Размер |    Алгоритм    | Число сравнений | Число обменов  |\n");
    printf("|------------------------------------------------------------|\n");
    printf("| %6d | Bobble sort    | %-15d | %-14d |\n", length, compCount, swapCount);

    sortIndex = compCount + swapCount * 3;
    
    compCount = 0;
    swapCount = 0;

    sorted = insertionSort(arr, length, &compCount, &swapCount);

    printf("|--------|----------------|-----------------|----------------|\n");
    printf("| %6d | Insertion sort | %-15d | %-14d |\n", length, compCount, swapCount);

    if (sortIndex > compCount + swapCount * 3)
    {
        sortIndex = compCount + swapCount * 3;
        whatSortIsBetter = 1;
    }

    compCount = 0;
    swapCount = 0;

    sorted = selectionSort(arr, length, &compCount, &swapCount);

    printf("|--------|----------------|-----------------|----------------|\n");
    printf("| %6d | Selection sort | %-15d | %-14d |\n", length, compCount, swapCount);
    printf("\\------------------------------------------------------------/\n\n");

    if (sortIndex > compCount + swapCount * 3)
    {
        sortIndex = compCount + swapCount * 3;
        whatSortIsBetter = 2;
    }

    switch(whatSortIsBetter)
    {
        case 0: 
            printf("Лучшей при генерации массива с равномерно распределёнными повторениями считается сортировка пузырьком.\n\n\n");
            break;
        case 1: 
            printf("Лучшей при генерации массива с равномерно распределёнными повторениями считается сортировка вставками.\n\n\n");
            break;
        case 2: 
            printf("Лучшей при генерации массива с равномерно распределёнными повторениями считается сортировка выбором.\n\n\n");
            break;
    }
}

void printTableOnAlternatingSeriesArray(int* arr, int length)
{
    long long compCount, swapCount;
    int *sorted;
    int i, whatSortIsBetter, sortIndex; //0 - Bubble   1 - Insertion  2 - Selection 

    sortIndex = 0;
    whatSortIsBetter = 0;

    compCount = 0;
    swapCount = 0;

    printf("Не отсортированный массив с чередующимися возрастающими и убывающими сериями:\n");
    writeArray(arr, length);
    
    sorted = bubbleSort(arr, length, &compCount, &swapCount);
    printf("\nПосле сортировки:\n");
    writeArray(sorted, length);
    printf("\n");

    printf("/=_Массив с чередующимися возрастающими и убывающими сериями_=\\\n");
    printf("|_____________________________________________________________|\n");
    printf("| Размер |    Алгоритм    | Число сравнений |  Число обменов  |\n");
    printf("|-------------------------------------------------------------|\n");
    printf("| %6d | Bobble sort    | %-15d | %-15d |\n", length, compCount, swapCount);

    sortIndex = compCount + swapCount * 3;
    
    compCount = 0;
    swapCount = 0;

    sorted = insertionSort(arr, length, &compCount, &swapCount);

    printf("|--------|----------------|-----------------|-----------------|\n");
    printf("| %6d | Insertion sort | %-15d | %-15d |\n", length, compCount, swapCount);

    if (sortIndex > compCount + swapCount * 3)
    {
        sortIndex = compCount + swapCount * 3;
        whatSortIsBetter = 1;
    }

    compCount = 0;
    swapCount = 0;

    sorted = selectionSort(arr, length, &compCount, &swapCount);

    printf("|--------|----------------|-----------------|-----------------|\n");
    printf("| %6d | Selection sort | %-15d | %-15d |\n", length, compCount, swapCount);
    printf("\\-------------------------------------------------------------/\n\n");

    if (sortIndex > compCount + swapCount * 3)
    {
        sortIndex = compCount + swapCount * 3;
        whatSortIsBetter = 2;
    }

    switch(whatSortIsBetter)
    {
        case 0: 
            printf("Лучшей при генерации массива с чередующимися возрастающими и убывающими сериями считается сортировка пузырьком.\n\n\n");
            break;
        case 1: 
            printf("Лучшей при генерации массива с чередующимися возрастающими и убывающими сериями считается сортировка вставками.\n\n\n");
            break;
        case 2: 
            printf("Лучшей при генерации массива с чередующимися возрастающими и убывающими сериями считается сортировка выбором.\n\n\n");
            break;
    }
}

void printTableOnNearlySortedArray(int* arr, int length)
{
    long long compCount, swapCount;
    int *sorted;
    int i, whatSortIsBetter, sortIndex; //0 - Bubble   1 - Insertion  2 - Selection 

    sortIndex = 0;
    whatSortIsBetter = 0;

    compCount = 0;
    swapCount = 0;

    printf("Почти отсортированный массив:\n");
    writeArray(arr, length);
    
    sorted = bubbleSort(arr, length, &compCount, &swapCount);
    printf("\nПосле сортировки:\n");
    writeArray(sorted, length);
    printf("\n");

    printf("/=________________Почти отсортированный массив_______________=\\\n");
    printf("|_____________________________________________________________|\n");
    printf("| Размер |    Алгоритм    | Число сравнений |  Число обменов  |\n");
    printf("|-------------------------------------------------------------|\n");
    printf("| %6d | Bobble sort    | %-15d | %-15d |\n", length, compCount, swapCount);

    sortIndex = compCount + swapCount * 3;
    
    compCount = 0;
    swapCount = 0;

    sorted = insertionSort(arr, length, &compCount, &swapCount);

    printf("|--------|----------------|-----------------|-----------------|\n");
    printf("| %6d | Insertion sort | %-15d | %-15d |\n", length, compCount, swapCount);

    if (sortIndex > compCount + swapCount * 3)
    {
        sortIndex = compCount + swapCount * 3;
        whatSortIsBetter = 1;
    }

    compCount = 0;
    swapCount = 0;

    sorted = selectionSort(arr, length, &compCount, &swapCount);

    printf("|--------|----------------|-----------------|-----------------|\n");
    printf("| %6d | Selection sort | %-15d | %-15d |\n", length, compCount, swapCount);
    printf("\\-------------------------------------------------------------/\n\n\n");

    if (sortIndex > compCount + swapCount * 3)
    {
        sortIndex = compCount + swapCount * 3;
        whatSortIsBetter = 2;
    }

    switch(whatSortIsBetter)
    {
        case 0: 
            printf("Лучшей при генерации почти отсортированного массива считается сортировка пузырьком.\n\n\n");
            break;
        case 1: 
            printf("Лучшей при генерации почти отсортированного массива считается сортировка вставками.\n\n\n");
            break;
        case 2: 
            printf("Лучшей при генерации почти отсортированного массива считается сортировка выбором.\n\n\n");
            break;
    }
}

void printTableOnLowVarianceArray(int* arr, int length)
{
    long long compCount, swapCount;
    int *sorted;
    int i, whatSortIsBetter, sortIndex; //0 - Bubble   1 - Insertion  2 - Selection 

    sortIndex = 0;
    whatSortIsBetter = 0;

    compCount = 0;
    swapCount = 0;

    printf("Не отсортированный массив, где каждый следующий элемент отличается на небольшую величину:\n");
    writeArray(arr, length);
    
    sorted = bubbleSort(arr, length, &compCount, &swapCount);
    printf("\nПосле сортировки:\n");
    writeArray(sorted, length);
    printf("\n");

    printf("/=Массив, где следующий элемент немного отлич. от предыдущего=\\\n");
    printf("|_____________________________________________________________|\n");
    printf("| Размер |    Алгоритм    | Число сравнений |  Число обменов  |\n");
    printf("|-------------------------------------------------------------|\n");
    printf("| %6d | Bobble sort    | %-15d | %-15d |\n", length, compCount, swapCount);

    sortIndex = compCount + swapCount * 3;
    
    compCount = 0;
    swapCount = 0;

    sorted = insertionSort(arr, length, &compCount, &swapCount);

    printf("|--------|----------------|-----------------|-----------------|\n");
    printf("| %6d | Insertion sort | %-15d | %-15d |\n", length, compCount, swapCount);

    if (sortIndex > compCount + swapCount * 3)
    {
        sortIndex = compCount + swapCount * 3;
        whatSortIsBetter = 1;
    }

    compCount = 0;
    swapCount = 0;

    sorted = selectionSort(arr, length, &compCount, &swapCount);

    printf("|--------|----------------|-----------------|-----------------|\n");
    printf("| %6d | Selection sort | %-15d | %-15d |\n", length, compCount, swapCount);
    printf("\\-------------------------------------------------------------/\n\n");

    if (sortIndex > compCount + swapCount * 3)
    {
        sortIndex = compCount + swapCount * 3;
        whatSortIsBetter = 2;
    }

    switch(whatSortIsBetter)
    {
        case 0: 
            printf("Лучшей при генерации массива где следующий элемент немного отличается от предыдущего считается сортировка пузырьком.\n\n\n");
            break;
        case 1: 
            printf("Лучшей при генерации массива где следующий элемент немного отличается от предыдущего считается сортировка вставками.\n\n\n");
            break;
        case 2: 
            printf("Лучшей при генерации массива где следующий элемент немного отличается от предыдущего считается сортировка выбором.\n\n\n");
            break;
    }
}

int scanInt(const int MIN_NUMBER, const int MAX_NUMBER, const char myString[])
{
    _Bool isIncorrect;
    int number;
    char ch;

    isIncorrect = 0;
    number = 0;
    ch = 0;

    do
    {
        printf(myString);
        isIncorrect = 0;

        if (scanf("%d%c", &number, &ch) == 0 || !(isspace(ch) || ch == EOF))
        {
            isIncorrect = 1;
            printf("Некорректный ввод, повторите попытку\n");
            while (getchar() != '\n');
        }

        if (!isIncorrect && ((number < MIN_NUMBER) || (number > MAX_NUMBER)))
        {
            isIncorrect = 1;
            printf("Число должно входить в диапазон [%d,%d]\n", MIN_NUMBER, MAX_NUMBER);
        }

    } while (isIncorrect);

    return number;
}

int* generateNonuniformRandomArray(size_t length)
{
    const int MAX_ELEMENT = 10000;
    int i;
    int *arr;

    arr = (int*)malloc(length * sizeof(int));

    for (i = 0; i < length; ++i)
    {
        arr[i] = rand() % (MAX_ELEMENT / 2 + 1) + rand() % (MAX_ELEMENT / 2 + 1);\

        if (rand() % 2 == 0)
            arr[i] = arr[i] * (-1);
    }

    return arr;
}

int* generateArrayWithUniformRepetitions(size_t length)
{
    const int MAX_ELEMENT = 10000;
    int i, repetitionsLength, maxRep;
    int *arr;

    maxRep = 0;
    repetitionsLength = 0;

    if (length < 2) 
    {
        repetitionsLength = length;
    } 
    else 
    {
        maxRep = length / 2;
        if (maxRep < 2) 
            maxRep = 2;
        repetitionsLength = 2 + rand() % (maxRep - 1);
    }

    arr = (int*)malloc(length * sizeof(int));

    if (!arr) 
        return NULL;

    for (i = 0; i < length; ++i) 
    {
        if (i < repetitionsLength) 
        {
            arr[i] = rand() % (MAX_ELEMENT + 1);
            if (rand() % 2 == 0)
                arr[i] = arr[i] * (-1);
        } 
        else 
        {
            arr[i] = arr[i - repetitionsLength];
        }
    }
    return arr;
}

int* generateAlternatingSeriesArray(size_t length) 
{
    const int MAX_ELEMENT = 10000;
    const int MIN_SERIES_LEN = 2;
    const int MAX_SERIES_LEN = 7;
    int *arr;
    size_t i;
    int prev, direction, seriesRemaining, low, high, newVal;

    arr = (int*)malloc(length * sizeof(int));
    if (!arr || length == 0) 
        return arr;

    arr[0] = rand() % (MAX_ELEMENT + 1);
    prev = arr[0];
    direction = 1;
    seriesRemaining = 1;

    for (i = 1; i < length; ++i) 
    {
        if (seriesRemaining == 0) 
        {
            seriesRemaining = MIN_SERIES_LEN + rand() % (MAX_SERIES_LEN - MIN_SERIES_LEN + 1);
            direction = !direction;
        }

        if (direction) 
        {
            // Возрастание: следующее число должно быть больше prev
            low = prev + 1;
            high = MAX_ELEMENT;
        } 
        else 
        {
            // Убывание: следующее число должно быть меньше prev
            low = -10000;
            high = prev - 1;
        }

        if (low > high) 
        {
            newVal = prev;
        } 
        else 
        {
            newVal = low + rand() % (high - low + 1);
            if (rand() % 2 == 0)
                arr[i] = arr[i] * (-1);
        }

        arr[i] = newVal;
        prev = newVal;
        seriesRemaining--;
    }

    return arr;
}

int* generateNearlySortedArray(size_t length) 
{
    const int MAX_ELEMENT = 10000;
    const int MAX_SWAPS = 8;    
    
    int *arr;
    size_t i;
    size_t idx1, idx2;
    int swapCount, temp;
    long long unusedA, unusedB;

    unusedA = 0;
    unusedB = 0;
    swapCount = 0;
    temp = 0;
    idx1 = 0;
    idx2 = 0;

    arr = (int*)malloc(length * sizeof(int));

    if (!arr || length == 0) 
        return arr;

    for (i = 0; i < length; ++i) 
    {
        arr[i] = rand() % (MAX_ELEMENT + 1);
        if (rand() % 2 == 0)
            arr[i] = arr[i] * (-1);
    }

    arr = selectionSort(arr, length, &unusedA, &unusedB);

    // Перестановки от 1 до MAX_SWAPS, но не более половины длины
    if (length < 2) 
        return arr;

    if (length < 16)
        swapCount = 1 + rand() % (length % 3 + 1); 
    else    
        swapCount = 1 + rand() % MAX_SWAPS;


            // Обмены
    for (i = 0; i < (size_t)swapCount; ++i) 
    {
        idx1 = rand() % length;
        idx2 = rand() % length;

        // temp = arr[idx1];
        // arr[idx1] = arr[idx2];
        // arr[idx2] = temp;
        swap(arr, idx1, idx2);
    }

    return arr;
}

int* generateLowVarianceArray(size_t length)
{
    const int MAX_ELEMENT = 10000;
    
    int *arr;
    int i; 

    arr = (int*)malloc(length * sizeof(int));

    arr[0] = rand() % (MAX_ELEMENT + 1);
    if (rand() % 2 == 0)
        arr[0] = arr[0] * (-1);

    for (i = 1; i < length; ++i)
    {
        if (rand() % 2 == 0)
            arr[i] = arr[i - 1] + rand() % 101;
        else    
            arr[i] = arr[i - 1] - rand() % 101;    
    } 

    return arr;
}

void writeArray(const int *arr, const size_t n)
{
    size_t i;
    i = 0;

    if (arr != NULL && n != 0)
    {
        for (i = 0; i < n; ++i)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else
        printf("Ошибка состояния массива.\n");
}

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
    int *sortedArray, minIdx;

    temp = 0;
    minIdx = 0;

    sortedArray = (int*)malloc(length * sizeof(int));

    memcpy(sortedArray, unsortedArray, length * sizeof(int));

    *comparisonCount = 0ll;
    *swapCount = 0ll;

    for (i = 0; i < length - 1; ++i) 
    {
      
        minIdx = i;
        
        for (j = i + 1; j < length; ++j) 
        {
            if (sortedArray[j] < sortedArray[minIdx]) 
            {
                minIdx = j;
            }
            (*comparisonCount)++;
        }
        
        if (minIdx != i) 
        {
            temp = sortedArray[i];
            sortedArray[i] = sortedArray[minIdx];
            sortedArray[minIdx] = temp;
            (*swapCount)++;
        }
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

        while (j > -1 && sortedArray[j] > key) 
        {
            sortedArray[j + 1] = sortedArray[j];
            j--;
            (*swapCount)++;
            (*comparisonCount)++;
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

void generateAndAnalyze()
{
    int length1, length2, length3, length4;
    int *genArrNRA, *genArrAWUR, *genArrASA, *genArrNSA, *genArrLVA;

    length1 = 50;
    length2 = 100;
    length3 = 500;
    length4 = 1000;

    srand(time(NULL));

    printf("\n===================================================================================================================\n");
    printf("========================                          50 элементов                             ========================\n");
    printf("===================================================================================================================\n\n");

    genArrNRA = generateNonuniformRandomArray(length1);
    genArrAWUR = generateArrayWithUniformRepetitions(length1);
    genArrASA = generateAlternatingSeriesArray(length1);
    genArrNSA = generateNearlySortedArray(length1);
    genArrLVA = generateLowVarianceArray(length1);

    printTableOnNonuniformGeneratedArray(genArrNRA, length1);
    printTableOnArrayWithUniformRepetitions(genArrAWUR, length1);
    printTableOnAlternatingSeriesArray(genArrASA, length1);
    printTableOnNearlySortedArray(genArrNSA, length1);
    printTableOnLowVarianceArray(genArrLVA, length1);

    srand(time(NULL));

    printf("\n===================================================================================================================\n");
    printf("========================                          100 элементов                            ========================\n");
    printf("===================================================================================================================\n\n");

    genArrNRA = generateNonuniformRandomArray(length2);
    genArrAWUR = generateArrayWithUniformRepetitions(length2);
    genArrASA = generateAlternatingSeriesArray(length2);
    genArrNSA = generateNearlySortedArray(length2);
    genArrLVA = generateLowVarianceArray(length2);

    printTableOnNonuniformGeneratedArray(genArrNRA, length2);
    printTableOnArrayWithUniformRepetitions(genArrAWUR, length2);
    printTableOnAlternatingSeriesArray(genArrASA, length2);
    printTableOnNearlySortedArray(genArrNSA, length2);
    printTableOnLowVarianceArray(genArrLVA, length2);

    srand(time(NULL));

    printf("\n===================================================================================================================\n");
    printf("========================                          500 элементов                            ========================\n");
    printf("===================================================================================================================\n\n");

    genArrNRA = generateNonuniformRandomArray(length3);
    genArrAWUR = generateArrayWithUniformRepetitions(length3);
    genArrASA = generateAlternatingSeriesArray(length3);
    genArrNSA = generateNearlySortedArray(length3);
    genArrLVA = generateLowVarianceArray(length3);

    printTableOnNonuniformGeneratedArray(genArrNRA, length3);
    printTableOnArrayWithUniformRepetitions(genArrAWUR, length3);
    printTableOnAlternatingSeriesArray(genArrASA, length3);
    printTableOnNearlySortedArray(genArrNSA, length3);
    printTableOnLowVarianceArray(genArrLVA, length3);

    srand(time(NULL));

    printf("\n===================================================================================================================\n");
    printf("========================                         1000 элементов                            ========================\n");
    printf("===================================================================================================================\n\n");

    genArrNRA = generateNonuniformRandomArray(length4);
    genArrAWUR = generateArrayWithUniformRepetitions(length4);
    genArrASA = generateAlternatingSeriesArray(length4);
    genArrNSA = generateNearlySortedArray(length4);
    genArrLVA = generateLowVarianceArray(length4);

    printTableOnNonuniformGeneratedArray(genArrNRA, length4);
    printTableOnArrayWithUniformRepetitions(genArrAWUR, length4);
    printTableOnAlternatingSeriesArray(genArrASA, length4);
    printTableOnNearlySortedArray(genArrNSA, length4);
    printTableOnLowVarianceArray(genArrLVA, length4);

}