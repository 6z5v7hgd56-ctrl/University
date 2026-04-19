#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "algorithms.h"

int* generateNonuniformRandomArray(size_t length);
int* generateArrayWithUniformRepetitions(size_t length);
int* generateAlternatingSeriesArray(size_t length);
int* generateNearlySortedArray(size_t length);
int* generateLowVarianceArray(size_t length);

void printTableOnNonuniformGeneratedArray(int* arr, int length);

int scanInt(const int MIN_NUMBER, const int MAX_NUMBER, const char myString[]);
void writeArray(const int *arr, const size_t n);

// 20 массив из случайных чисел с неравномерным распределением
// 31 массив с равномерно распределёнными повторениями
// 28 массив с чередующимися возрастающими и убывающими сериями
// 6 почти отсортированный массив (несколько элементов переставлены)
// 44 массив, где каждый следующий элемент отличается на небольшую величину

// Элементы массива в диапазоне от 0..10000

int main(void) // Вариант 20
{
    int length;
    int *genArrNRA, *genArrAWUR, *genArrASA, *genArrNSA, *genArrLVA;
    long long cc1, sc1;

    length = 0;

    srand(time(NULL));
    setlocale(LC_ALL, "Russian");

    length = scanInt(1, 1000, "Введите длину: ");

    genArrNRA = generateNonuniformRandomArray(length);
    genArrAWUR = generateArrayWithUniformRepetitions(length);
    genArrASA = generateAlternatingSeriesArray(length);
    genArrNSA = generateNearlySortedArray(length);
    genArrLVA = generateLowVarianceArray(length);

    printTableOnNonuniformGeneratedArray(genArrNRA, length);



    free(genArrNRA);
    free(genArrAWUR);
    free(genArrASA);
    free(genArrNSA);
    free(genArrLVA);
    return 0;
}

void printTableOnNonuniformGeneratedArray(int* arr, int length)
{
    long long compCount, swapCount;
    int *sorted;
    int i;

    compCount = 0;
    swapCount = 0;

    printf("Не отсортированный массив из случайных чисел с неравномерным распределением:\n");
    writeArray(arr, length);
    printf("\nПосле сортировки:\n");
    writeArray(sorted, length);
    printf("\n");

    sorted = bubbleSort(arr, length, &compCount, &swapCount);

    printf("___________________________________________________________\n");
    printf("| Размер |   Алгоритм   | Число сравнений | Число обменов |\n");
    printf("|---------------------------------------------------------|\n");
    printf("| %6d | Bobble sort  | %-14d | %-14d |\n", length, compCount, swapCount);
    

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
            printf("Число должно сходить в диапазон [%d,%d]\n", MIN_NUMBER, MAX_NUMBER);
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
        arr[i] = rand() % (MAX_ELEMENT / 2 + 1) + rand() % (MAX_ELEMENT / 2 + 1);
    }

    return arr;
}

int* generateArrayWithUniformRepetitions(size_t length)
{
    const int MAX_ELEMENT = 10000;
    int i, repetitionsLength;
    int *arr;

    // Безопасное вычисление длины повторяющегося блока
    if (length < 2) {
        repetitionsLength = length;
    } else {
        int maxRep = length / 2;
        if (maxRep < 2) maxRep = 2;
        repetitionsLength = 2 + rand() % (maxRep - 1);
    }

    arr = (int*)malloc(length * sizeof(int));
    if (!arr) return NULL;

    for (i = 0; i < length; ++i) {
        if (i < repetitionsLength) {
            arr[i] = rand() % (MAX_ELEMENT + 1);
        } else {
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
            low = 0;
            high = prev - 1;
        }

        if (low > high) 
        {
            newVal = prev;
        } 
        else 
        {
            newVal = low + rand() % (high - low + 1);
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
        swap(&arr, idx1, idx2);
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

