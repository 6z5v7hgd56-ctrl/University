#include "stdio.h"
#include "stdlib.h"
#include "algorithms.h"

void fillArray(int** arr, size_t* n)
{
    size_t i;

    *n = 0;

    printf("Введите длину массива: ");
    scanf("%zu", &*n);

    *arr = (int*)malloc(*n * sizeof(int));

    for (i = 0; i < *n; i++)
    {
        scanf("%d", &(*arr)[i]);
    }
}

void writeArray(const int arr[], const size_t n)
{
    int i;
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
        printf("Ошибка состояния массива.");
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

void filter(int** arr, size_t* n)
{
    int old, new;
    int* temp;
    size_t newLength;

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

    printf("%zu\n", newLength);

    temp = (int*)realloc(*arr, newLength * sizeof(int));

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
    else    
        if (k == 0 || k > n)
        {
            printf("Невозмоно провести операцию нахождения суммы подряд идущих элементов из-за некорректрой длины скользящего окна k.\n");    
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
