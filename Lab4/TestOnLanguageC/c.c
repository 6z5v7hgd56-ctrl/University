#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>

// #ifdef WIN32
// #include <io.h>
// #define F_OK 0
// #define access _access
// #endif

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
char *askTheFilePath();

//*

int main(void)
{
    int a;

    setlocale(LC_ALL, "Russian");

    printPurpose();

    for (int i = 0; i < 6; ++i)
    {
        checkMyFile(askTheFilePath(), 1);
        printf("b"); // !
    }

    return 0;
}

void printPurpose()
{
    printf("PURPOSE_PURPOSE_PURPOSE\n");
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

    testFile = fopen(fPath, "w");

    if (testFile)
    {
        fclose(testFile);
        isReady = 1;
    }

    return canWrite;
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

_Bool checkMyFile(char fPath[], _Bool isToRead)
{
    FILE testFile;
    _Bool isGood;

    isGood = 0;

    printf("c"); // !

    // testFile.open(filePath);

    if (access(fPath, F_OK) == 0)
    {
        printf("Error, file with path <%s> is not exists or cannot be read.\n", fPath);
        printf("d"); // !
    }
    else if (!checkIsFileText(fPath))
        printf("Error, filename is not .txt\n");
    else if (isToRead && !canRead(fPath))
        printf("Error, no access to read the file.\n");
    else if (!isToRead && !canWrite(fPath))
        printf("Error, no access to write into the file.\n");
    else
    {
        isGood = 1;
        printf("Assigning is completed successfully.\n");
        printf("e"); // !
    }

    printf("f"); // !

    // testFile.close();

    return isGood;
}

char *askTheFilePath()
{
    const int maxLen = 255;
    char fPath[maxLen];
    // fPath = "";

    printf("Write the existing file path: ");

    fgets(fPath, maxLen, stdin);

    printf("a"); // !

    return fPath;
}
