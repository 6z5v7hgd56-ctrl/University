#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <io.h>

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
void menuStage();
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

int main(void)
{
    const int maxBuffer = 255;

    // int a;
    // char fPath[maxBuffer];

    setlocale(LC_ALL, "Russian");

    printPurpose();

    // assignFile(fPath, maxBuffer, 1);

    menuStage();

    return 0;
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
    printf("2 - Получить результат\n");
    printf("3 - Изменить массив\n");
    printf("4 - Помощь\n");
}

void fillArrayMenu()
{
}

int scanInt(const int MIN_NUMBER, const int MAX_NUMBER, const char myString[])
{
    _Bool isIncorrect;
    int number;

    isIncorrect = 0;
    number = 0;

    do
    {
        printf(myString);
        isIncorrect = 0;

        if (scanf("%d", &number) != 1) // ! Считает 5 если написать "5abcd"
        {
            isIncorrect = 1;
            printf("Incorrect input, try again.\n");
        }

        if (!isIncorrect && ((number < MIN_NUMBER) || (number > MAX_NUMBER)))
        {
            isIncorrect = 1;
            printf("The number must fit the range [%d,%d]\n", MIN_NUMBER, MAX_NUMBER);
        }

        if (isIncorrect)
            while (getchar() != '\n')
                ;

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

    if (arr == NULL) 
    {
        printf("\nМассив пуст, сначала введите массив.\n");    
    }
    else
    {
        printf("\n====== Метод вывода ======\n");
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

}

void readingStage(int **dataArray, int *arraySize)
{
    const int MIN_NUMBER = -10000;
    const int MAX_NUMBER = 10000;
    const int MAX_BUFFER = 255;

    _Bool isFromFile, isAllUndone, isToRead;
    char fPath[MAX_BUFFER];

    isToRead = 0;
    isAllUndone = 0;
    // isFromFile = workWithConsoleOrFile(isOutput); //! ИЗМЕНИТЬ

    if (isFromFile)
    {
        isAllUndone = 1;

        do
        {
            assignFile(fPath, MAX_BUFFER, isToRead);
            // dataArray = readArrayFromFile(MIN_NUMBER, MAX_NUMBER, fPath, arraySize);

            if (dataArray == 0)
                printf("Error with reading data, bad file read.\n");
            else
                isAllUndone = 0;

        } while (isAllUndone);
    }
    else
        fillArrayFromConsole(dataArray, arraySize);
}

void menuStage()
{
    const int MIN_MENU = 0;
    const int MAX_MENU = 4;

    _Bool isDoNotStop;
    int menuOption;
    int *dataArray, arrayLength;

    isDoNotStop = 1;
    menuOption = 0;
    dataArray = NULL;
    arrayLength = 0;

    do
    {
        showMenu();

        printf("\n");
        menuOption = scanInt(MIN_MENU, MAX_MENU, "> ");

        if (menuOption == 1)
        {
            fillArray(&dataArray, &arrayLength);
        }
        else 
            if (menuOption == 2)
            {
                writeArray(dataArray, arrayLength);
            }
            else 
                if (menuOption == 3)
                {
                    changeElement(&dataArray, &arrayLength);    
                }
                else 
                    if (menuOption == 4)
                {

                }
                else 
                    if (menuOption == 0) // ! В последнюю очередь
                        isDoNotStop = 0;

    } while (isDoNotStop);
}