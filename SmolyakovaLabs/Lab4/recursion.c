#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

void quicksort(int **dataArray, const int arrayLength, int low, int high);
int partition(int **dataArray, const int arrayLength, int low, int high);
void swap(int **dataArray, int i, int j);
int scanInt(const int MIN_NUMBER, const int MAX_NUMBER, const char myString[]);
void fillArray(int **arr, int *n);
int binaryFind(int* arr, int length, int left, int right, int target);
void writeArray(const int arr[], const size_t n);
void writeAnswer(int tarIndex);
void writePurpose();

int main(void) 
{
    const int MAX_ELEMENT =  1000;
    const int MIN_ELEMENT = -1000;
    int *arr;
    int length, target, tarIndex;

    length = 0;
    target = 0;

    setlocale(LC_ALL, "Russian");

    writePurpose();

    fillArray(&arr, &length);
    quicksort(&arr, length, 0, length - 1);
    printf("Массив после сортировки:\n");
    writeArray(arr, (size_t)length);
    target = scanInt(MIN_ELEMENT, MAX_ELEMENT, "Введите число, которое хотите найти бинарным поиском: ");
    tarIndex = binaryFind(arr, length, 0, length - 1, target);
    writeAnswer(tarIndex);

    return 1;
}

void writePurpose()
{
    printf("Программа демонстрирует реализацию рекурсивного бинарного поиска. Пользователь вводит массив, массив сортирует методом быстрой сортировки Хоара, пользователь вводит элемент, индекс которого хочет найти в отсортированном массиве, после чего программа выводит результат.\n");
}

void writeAnswer(int tarIndex)
{
    if (tarIndex == -1)
    {
        printf("Элемент отсутствует во введённом массиве\n");
    }
    else
    {
        printf("Элемент найден в отсортированном массиве по индексу %d\n", tarIndex + 1);
    }
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

void swap(int **dataArray, int i, int j)
{
    (*dataArray)[i] = (*dataArray)[i] + (*dataArray)[j];
    (*dataArray)[j] = (*dataArray)[i] - (*dataArray)[j];
    (*dataArray)[i] = (*dataArray)[i] - (*dataArray)[j];
}

int partition(int **dataArray, const int arrayLength, int low, int high)
{
    int pivot, randomIndex, i, j;
    _Bool isDoNotStop;

    randomIndex = 0;
    pivot = 0;
    i = low;
    j = high;
    isDoNotStop = 1;

    randomIndex = low + rand() % (high - low);
    pivot = (*dataArray)[randomIndex];

    while (isDoNotStop)
    {
        while ((*dataArray)[i] < pivot)
            i = i + 1;

        while ((*dataArray)[j] > pivot)
            j = j - 1;

        if (i >= j)
            isDoNotStop = 0;
        else
            swap(dataArray, i++, j--);
    }

    return j;
}

void quicksort(int **dataArray, const int arrayLength, int low, int high)
{
    int point;
    point = 0;

    if (*dataArray == NULL || dataArray == NULL)
        printf("Массив пуст, сначала введите массив через соответствующий пункт меню\n");
    else if (low < high)
    {
        point = partition(dataArray, arrayLength, low, high);
        quicksort(&(*dataArray), arrayLength, low, point);
        quicksort(&(*dataArray), arrayLength, point + 1, high);
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

void fillArray(int **arr, int *n)
{
    const int MAX_ELEMENT =  1000;
    const int MIN_ELEMENT = -1000;
    const int MAX_LENGTH = 100;
    size_t i;
    int testLen;

    *n = 0;
    testLen = 0;

    printf("Введите длину массива: ");
    testLen = scanInt(1, MAX_LENGTH, "");

    if (testLen > 0)
    {
        *n = testLen;
        *arr = (int *)malloc(*n * sizeof(int));

        for (i = 0; i < *n; i++)
        {
            printf("Элемент [%zu]: ", i + 1);
            (*arr)[i] = scanInt(MIN_ELEMENT, MAX_ELEMENT, "");
        }
    }
    else
    {
        printf("Ошибка, не положительная длина массива.\n");
        *arr = NULL;
        *n = 0;
    }
}

int binaryFind(int* arr, int length, int left, int right, int target)
{
    int index; 
    int middle;

    index = -1;

    if (left == right && arr[left] == target)
        return left;
    else
        if (left == right)
            return -1;

    middle = (left + right) / 2; 

    if (arr[middle] < target)
        index = binaryFind(arr, length, middle + 1, right, target);
    else
        index = binaryFind(arr, length, left, middle, target);

    return index;
}