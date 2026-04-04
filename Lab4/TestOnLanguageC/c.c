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
int scanInt(const int MIN_NUMBER, const int MAX_NUMBER, const char myString[]);
void askTheFilePath(char *buffer, int bufferSize);
void assignFile(char *fPath, int pathSize, _Bool isToRead);

//*

//* Array operations
void fillArrayFromConsole(int **arr, int *n);
void writeArrayIntoConsole(const int arr[], const size_t n);
//*

int main(void)
{
    const int maxBuffer = 255;

    int a;
    char fPath[maxBuffer];

    setlocale(LC_ALL, "Russian");

    printPurpose();

    assignFile(fPath, maxBuffer, 1);

    return 0;
}

void printPurpose()
{
    printf("PURPOSE_PURPOSE_PURPOSE\n\n");
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

        if (scanf("%d", &number) != 1) // ! —читает 5 если написать "5abcd"
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

//     isGood = 0;

//     testFileRead = fopen(fPath, "r");

//     if (testFileRead == NULL)
//     {
//         printf("Error, file with path <%s> is not exists or cannot be read.\n", fPath);
//     }
//     else
//     {
//         fclose(testFileRead);

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

//     return isGood;
// }


_Bool checkMyFile(char fPath[], _Bool isToRead)
{
    const int EXIST_MODE = 0;

    FILE *testFileRead, *testFileWrite;
    _Bool isGood;

    isGood = 0;

    //testFileRead = fopen(fPath, "r");

    if (_access(fPath, EXIST_MODE) != 0)
    {
        printf("Error, file with path <%s> is not exists or cannot be read.\n", fPath);
    }
    else
    {
        //fclose(testFileRead);

        if (!checkIsFileText(fPath))
            printf("Error, filename is not .txt\n");
        else 
            if (isToRead && !canRead(fPath))
                printf("Error, no access to read the file.\n");
            else 
                if (!isToRead && !canWrite(fPath))
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

    // ”дал€ем возможный '\n' в конце
    len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n')
        buffer[len - 1] = '\0';
}

void assignFile(char *fPath, int pathSize, _Bool isToRead)
{
    _Bool isIncorrect;

    isIncorrect = 0;

    printf("===== ASSIGNING =====\n");

    do
    {
        askTheFilePath(fPath, pathSize);
        isIncorrect = !checkMyFile(fPath, isToRead);
    } while (isIncorrect);

    printf("\n");
}

void fillArrayFromConsole(int **arr, int *n)
{
    int testLen, i;

    *n = 0;
    testLen = 0;

    printf("¬ведите длину массива: ");
    scanf("%d", &testLen);

    if (testLen > 0)
    {
        *n = testLen;
        *arr = (int *)malloc(*n * sizeof(int));

        for (i = 0; i < *n; i++)
        {
            printf("Ёлемент [%d]: ", i + 1);
            scanf("%d", &(*arr)[i]);
        }
    }
    else
    {
        printf("ќшибка, не положительна€ длина массива.\n");
        *arr = NULL;
        *n = 0;
    }
}

void writeArrayIntoConsole(const int arr[], const size_t n)
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
        printf("ќшибка состо€ни€ массива.\n");
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
    //isFromFile = workWithConsoleOrFile(isOutput); //! »«ћ≈Ќ»“№

    if (isFromFile)
    {
        isAllUndone = 1;

        do
        {
            assignFile(fPath, MAX_BUFFER, isToRead);
            //dataArray = readArrayFromFile(MIN_NUMBER, MAX_NUMBER, fPath, arraySize);

            if (dataArray == 0)
                printf("Error with reading data, bad file read.\n");
            else
                isAllUndone = 0;

        } while (isAllUndone);
    }
    else
        fillArrayFromConsole(dataArray, arraySize);
}