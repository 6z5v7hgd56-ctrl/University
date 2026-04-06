#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <io.h>
#include <ctype.h>

//* Tests
_Bool checkIsFileText(char fPath[]);
_Bool canRead(const char fPath[]);
_Bool canWrite(const char filePath[]);
_Bool checkIsEmpty(const char filePath[]);
_Bool checkMyFile(char fPath[], _Bool isToRead);
//*

//* Service
void printPurpose();
void showMenu();
int scanInt(const int MIN_NUMBER, const int MAX_NUMBER, const char myString[]);
void askTheFilePath(char *buffer, int bufferSize);
void assignFile(char *fPath, int pathSize, _Bool isToRead);
void menuStage(int **dataArray, int *arrayLength);
void readingStage(int **dataArray, int *arraySize); 

//*

//* Array operations
void fillArray(int **arr, int *len);
void fillArrayFromConsole(int **arr, int *len);
void fillArrayFromFile(int **arr, int *len);

void writeArray(const int arr[], const int n);
void writeArrayIntoConsole(const int arr[], const int n);
void writeArrayIntoFile(const int arr[], const int n);
//*

void swap(int **dataArray, int i, int j);
int partition(int **dataArray, const int arrayLength, int low, int high);
void quicksort(int **dataArray, const int arrayLength, int low, int high);

int main(void)
{
    int *dataArray, arrayLength;

    dataArray = NULL;
    arrayLength = 0;

    setlocale(LC_ALL, "Russian");

    printPurpose();
    menuStage(&dataArray, &arrayLength);
    
    return 0; // TODO Удалять массив в конце работы программы
}

void printPurpose()
{
    printf("PURPOSE_PURPOSE_PURPOSE\n\n");
}

void showMenu()
{
    printf("\n====== Меню =====\n");
    printf("0 - Выход\n");
    printf("1 - Ввести массив\n");
    printf("2 - Отсортировать массив\n");
    printf("3 - Вывести массив\n");
    printf("4 - Изменить элемент массива\n");
    printf("5 - Помощь\n");
}

void writeHelp()
{
    printf("\n====== Помощь ======\n");
    printf("Программа позволяет вводить массив через консоль либо через файл, выводить его в консоль либо массив, изменить отдельный элемент массива. \nВводить значения нужно используя стандартные символы ASCII.\n");
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

        if (scanf("%d%c", &number, &ch) == 0 || !(isspace(ch) || ch == EOF) )
        {
            isIncorrect = 1;
            printf("Incorrect input, try again.\n");
            if (isIncorrect)
                while (getchar() != '\n');
        }
        
        if (!isIncorrect && ((number < MIN_NUMBER) || (number > MAX_NUMBER)))
        {
            isIncorrect = 1;
            printf("The number must fit the range [%d,%d]\n", MIN_NUMBER, MAX_NUMBER);
        }

    } while (isIncorrect);

    return number;
}

_Bool checkIsFileText(char fPath[])
{
    int len;
    _Bool result;

    len = 0;
    result = 0;

    len = strlen(fPath);
    result = (len > 3 && strcmp(fPath + len - 4, ".txt") == 0);

    return result;
}

_Bool canRead(const char fPath[])
{
    FILE *testFile;
    _Bool isReady;

    isReady = 0;

    testFile = fopen(fPath, "r");

    if (testFile)
    {
        fclose(testFile);
        isReady = 1;
    }

    return isReady;
}

_Bool canWrite(const char fPath[])
{
    FILE *testFile;
    _Bool isReady;

    isReady = 0;

    testFile = fopen(fPath, "a");

    if (testFile != NULL)
    {
        fclose(testFile);
        isReady = 1;
    }

    return isReady;
}

_Bool checkIsEmpty(const char fPath[])
{
    FILE *testFile;
    _Bool isEmpty;

    isEmpty = 0;

    testFile = fopen(fPath, "r");

    isEmpty = fgetc(testFile) == EOF;

    return isEmpty;
}

// _Bool checkMyFile(char fPath[], _Bool isToRead)
// {
//     FILE *testFileRead, *testFileWrite;
//     _Bool isGood;
//
//     isGood = 0;
//
//     testFileRead = fopen(fPath, "r");
//
//     if (testFileRead == NULL)
//     {
//         printf("Error, file with path <%s> is not exists or cannot be read.\n", fPath);
//     }
//     else
//     {
//         fclose(testFileRead);
//
//         if (!checkIsFileText(fPath))
//             printf("Error, filename is not .txt\n");
//         else
//             if (isToRead && !canRead(fPath))
//                 printf("Error, no access to read the file or file do not exists.\n");
//             else
//                 if (!isToRead && !canWrite(fPath))
//                     printf("Error, no access to write into the file.\n");
//                 else
//                 {
//                     isGood = 1;
//                     printf("Assigning is completed successfully.\n");
//                 }
//     }
//
//     return isGood;
// }

_Bool checkMyFile(char fPath[], _Bool isToRead)
{
    const int EXIST_MODE = 0;

    FILE *testFileRead, *testFileWrite;
    _Bool isGood;

    isGood = 0;

    // testFileRead = fopen(fPath, "r");

    if (_access(fPath, EXIST_MODE) != 0)
    {
        printf("Error, file with path <%s> is not exists or cannot be read.\n", fPath);
    }
    else
    {
        // fclose(testFileRead);

        if (!checkIsFileText(fPath))
            printf("Error, filename is not .txt\n");
        else if (isToRead && !canRead(fPath))
            printf("Error, no access to read the file.\n");
        else if (!isToRead && !canWrite(fPath))
            printf("Error, no access to write into the file.\n");
        else
        {
            isGood = 1;
            printf("Assigning is completed successfully.\n");
        }
    }

    return isGood;
}

void askTheFilePath(char *buffer, int bufferSize)
{
    size_t len;

    len = 0;

    printf("Write the existing file path: ");
    fgets(buffer, bufferSize, stdin);

    // Удаляем возможный '\n' в конце
    len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n')
        buffer[len - 1] = '\0';
}

void assignFile(char *fPath, int pathSize, _Bool isToRead)
{
    _Bool isIncorrect;

    isIncorrect = 0;

    printf("\n====== ASSIGNING ======\n");

    do
    {
        askTheFilePath(fPath, pathSize);
        isIncorrect = !checkMyFile(fPath, isToRead);
    } while (isIncorrect);

    printf("\n");
}

void fillArray(int **arr, int *len)
{
    int inputMethod;

    inputMethod = 0;

    printf("\n====== Метод ввода ======\n");
    printf("0 - Ввод через консоль\n");
    printf("1 - Ввод через файл\n\n");

    inputMethod = scanInt(0, 1, "> ");

    if (inputMethod == 0)
    {
        fillArrayFromConsole(arr, len);
    }
    else
        fillArrayFromFile(arr, len);
}

void fillArrayFromConsole(int **arr, int *len)
{
    const int MIN_ELEMENT = -1000000;
    const int MAX_ELEMENT =  1000000;

    int testLen, i;
    int *temp;

    testLen = 0;

    printf("\nВведите длину массива\n");
    testLen = scanInt(1, 100, "> ");

    if (*arr == NULL)
    {
        *arr = (int *)malloc(testLen * sizeof(int));
        *len = testLen;
    }
    else
    {
        temp = (int *)realloc(*arr, testLen * sizeof(int));

        if ((temp) == NULL)
        {
            printf("Ошибка при изменении массива.");
        }
        else
        {
            *arr = (int *)malloc(testLen * sizeof(int));
            memcpy(*arr, temp, sizeof(temp));
            free(temp);
            *len = testLen;
        }
    }

    for (i = 0; i < *len; i++)
    {
        printf("Элемент [%d]: \n", i + 1);
        (*arr)[i] = scanInt(MIN_ELEMENT, MAX_ELEMENT, "> ");
    }
}

void fillArrayFromFile(int **arr, int *n)
{
}

void writeArray(const int *arr, const int n)
{
    int outputMethod;

    outputMethod = 0;

    printf("\n====== Вывод массива ======\n");

    if (arr == NULL) 
    {
        printf("Массив пуст, сначала введите массив через соответствующий пункт меню..\n");    
    }
    else
    {
        printf("Выберите метод вывода массива:\n");
        printf("0 - Вывод в консоль\n");
        printf("1 - Вывод в файл\n\n");

        outputMethod = scanInt(0, 1, "> ");

        if (outputMethod == 0)
            writeArrayIntoConsole(arr, n);
        else
            writeArrayIntoFile(arr, n);
    }
}

void writeArrayIntoConsole(const int *arr, const int n)
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
        printf("Ошибка состояния массива.\n");
}

void writeArrayIntoFile(const int *arr, const int n)
{
}

void changeElement(int **arr, int *n)
{
    const int MIN_ELEMENT = -1000000;
    const int MAX_ELEMENT =  1000000;
    
    int newElement, index;

    newElement = 0;
    index = 0;

    printf("\n====== Изменение элемента ======\n");

    if (*arr == NULL) 
    {
        printf("Изменение массива невозможно, так как массив пуст. Сначала введите массив через соответствующий пункт меню.\n");
    }
    else
    {

        printf("Введённый массив: ");
        writeArrayIntoConsole(*arr, *n);
        printf("Введите индекс элемента, который хотите изменить в диапазоне [1;%d]:\n", *n);
    
        index = scanInt(1, *n, "> ");
    
        printf("Вы хотите заменить элемент под номером %d со значением %d на новое значение:\n");
        newElement = scanInt(MIN_ELEMENT, MAX_ELEMENT, "> ");
    
        (*arr)[index - 1] = newElement;
        printf("Элемент успешно изменён.");
    }
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

    printf("\n====== Сортировка ======\n");

    if (*dataArray == NULL)
        printf("Массив пуст, сначала введите массив через соответствующий пункт меню.\n");
    else
        if (low < high)
        {
            point = partition(dataArray, arrayLength, low, high);
            quicksort(&(*dataArray), arrayLength, low, point);
            quicksort(&(*dataArray), arrayLength, point + 1, high);
        }
}

void menuStage(int **dataArray, int *arrayLength)
{
    const int MIN_MENU = 0;
    const int MAX_MENU = 5;

    _Bool isDoNotStop;
    int menuOption;

    isDoNotStop = 1;
    menuOption = 0;

    do
    {
        showMenu();

        printf("\n");
        menuOption = scanInt(MIN_MENU, MAX_MENU, "> ");

        if (menuOption == 1)
        {
            fillArray(&*dataArray, &*arrayLength);
        }
        else 
            if (menuOption == 2)  
            {
                quicksort(&*dataArray, *arrayLength, 0, *arrayLength - 1);
            }
            else 
                if (menuOption == 3)
                {
                    writeArray(*dataArray, *arrayLength);  
                }
                else 
                    if (menuOption == 4)
                    {
                        changeElement(&*dataArray, &*arrayLength); 
                    }
                    else 
                        if (menuOption == 5)
                        {
                            writeHelp(); 
                        }
                        else
                            if (menuOption == 0)
                                isDoNotStop = 0;

    } while (isDoNotStop);
}