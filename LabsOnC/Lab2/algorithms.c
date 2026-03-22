#include "stdio.h"
#include "stdlib.h"
#include "algorithms.h"

void fillArray(int **arr, size_t *n)
{
    size_t i;
    int testLen;

    *n = 0;
    testLen = 0;

    printf("Введите длину массива: ");
    scanf("%d", &testLen);

    if (testLen > 0)
    {
        *n = testLen;
        *arr = (int *)malloc(*n * sizeof(int));

        for (i = 0; i < *n; i++)
        {
            printf("Элемент [%zu]: ", i + 1);
            scanf("%d", &(*arr)[i]);
        }
    }
    else
    {
        printf("Ошибка, не положительная длина массива.\n");
        *arr = NULL;
        *n = 0;
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

void analyze(const int *arr, size_t n, int *min, int *max, long long *sum)
{
    if (n > 0)
    {
        *min = arr[0];
        *max = arr[0];
        *sum = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] < *min)
                *min = arr[i];
            if (arr[i] > *max)
                *max = arr[i];
            *sum += arr[i];
        }
    }
}

void filter(int **arr, size_t *n)
{
    size_t newLength, old, new;
    int *temp;

    old = 0;
    new = 0;

    newLength = *n;

    if (*arr != NULL && *n > 0)
    {
        for (old = 0; old < *n; old++)
        {
            if ((*arr)[old] != x)
            {
                (*arr)[new] = (*arr)[old];
                new++;
            }
            else
                newLength--;
        }
    }

    temp = (int *)realloc(*arr, newLength * sizeof(int));

    if ((temp) == NULL)
    {
        printf("Ошибка при изменении размера массива.");
    }
    else
    {
        *arr = temp;
        *n = newLength;
    }
}

int maxSequentially(const int arr[], const size_t n)
{
    size_t i, j;
    int sum, max;

    sum = 0;
    max = 0;

    if (n == 0 || arr == NULL)
    {
        printf("Невозмоно провести операцию нахождения суммы подряд идущих элементов так как массив имеет длину 0.\n");
    }
    else if (k == 0 || k > n)
    {
        printf("Невозмоно провести операцию нахождения суммы подряд идущих элементов из-за несоответствия длины скользящего окна k и длинны массива n.\n");
    }
    else
    {
        for (i = 0; i < n - k + 1; i++)
        {
            sum = 0;
            for (j = i; j < i + k; j++)
            {
                if (i == 0)
                {
                    max = max + arr[j];
                }
                else
                {
                    sum = sum + arr[j];
                    if (j == i + k - 1 && sum > max)
                        max = sum;
                }
            }
        }
    }

    return max;
}

int minSequentially(const int *arr, size_t n)
{
    size_t left, right, min_len, len;
    int current_sum;

    left = 0;
    min_len = n + 1;
    current_sum = 0;

    for (right = 0; right < n; right++)
    {
        current_sum += arr[right];

        while (current_sum >= s)
        {
            len = right - left + 1;

            if (len < min_len)
                min_len = len;

            current_sum = current_sum - arr[left];
            left++;
        }
    }

    if (min_len == n + 1)
    {
        min_len = -1;
        printf("Ошибка при поиске минимальной длины массива, сумма элементов которого будет больше чем та, что задана в условии варианта.\n");
    }

    return (int)min_len;
}

void deleteRepetitions(int **arr, size_t *n)
{
    int i, j, arrLen;
    _Bool isNotSorted;
    int* temp;

    temp = NULL;
    isNotSorted = 1;
    arrLen = *n;

    while (isNotSorted)
    {
        isNotSorted = 0;
        for (i = 0; i < arrLen - 1; ++i)
        {
            j = i + 1;

            if ((*arr)[i] == (*arr)[j])
            {
                while (j < *n)
                {
                    (*arr)[j] = (*arr)[j + 1];
                    j++;
                }
                arrLen--;
                isNotSorted = 1;
            }
        }
    }


    temp = (int *)realloc(*arr, arrLen * sizeof(int));

    if ((temp) == NULL)
    {
        printf("Ошибка при изменении размера массива.");
    }
    else
    {
        *arr = temp;
        *n = arrLen;
    }
}

void sort(int **arr, size_t *n)
{
    int i, j, key;

    key = 0;

    if ((*arr) != NULL && *n > 1)
    {
        for (i = 1; i < *n; i++)
        {
            key = (*arr)[i];
            j = i - 1;

            while (j > -1 && (*arr)[j] > key)
            {
                (*arr)[j + 1] = (*arr)[j];
                j--;
            }

            (*arr)[j + 1] = key;
        }

        for (i = 1; i < *n; i++)
        {
            key = (*arr)[i];
            j = i - 1;
        }
    }
    deleteRepetitions(arr, n);
}

void output1(int *arr, size_t n)
{
    int min, max;
    long long sum;

    min = 0;
    max = 0;
    sum = 0ll;

    printf("\n====Анализ====\n");
    analyze(arr, n, &min, &max, &sum);
    printf("Минимальное значение массивa: %d\nМаксимальное значение массива: %d\nСуммa элементов: %lld\n", min, max, sum);
}

void output2(int **arr, size_t *n)
{
    printf("\n====Фильтрация====\n");
    filter(&(*arr), &(*n));
    printf("Удаляемый элемент: %d\n", x);
    printf("Элементы, удовлетворяющие условию варианта: ");
    writeArray(*arr, *n);
    printf("Новый размер массива: %zu\n", *n);
}

void output3(int *arr, size_t n)
{
    int maxSeq;
    maxSeq = 0;

    printf("\n====Максимальная_сумма====\n");
    maxSeq = maxSequentially(arr, n);
    printf("k: %d\n", k);
    printf("%d\n", maxSeq);
}

void output4(int *arr, size_t n)
{
    int minSeq;
    minSeq = 0;

    printf("\n====Длина_минимального_подотрезка====\n");
    minSeq = minSequentially(arr, n);
    printf("S: %d\n", s);
    printf("%d\n", minSeq);
}

void output5(int **arr, size_t *n)
{
    printf("\n====Сортировка====\n");
    sort(&(*arr), &(*n));
    writeArray(*arr, *n);
}

void printMy()
{
    printf("x = 11, k = 4, S = 19\n");
}