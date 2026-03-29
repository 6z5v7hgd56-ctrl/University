#include "stdlib.h"
#include "stdio.h"
#include "string.h"

void printPurpose();

int main(void)
{
    printPurpose();

    return 0;
}

void printPurpose()
{
    printf("PURPOSE_PURPOSE_PURPOSE");
}

int scanInt(const int MIN_NUMBER, const int MAX_NUMBER, char myString[])
{
    _Bool isIncorrect;
    int number;

    isIncorrect = 0;
    number = 0;

    do
    {
        printf(myString);
        isIncorrect = 0;

        scanf("%d", &number);

        // if (cin.fail() || cin.get() != '\n')
        // {
        //     isIncorrect = true;
        //     cout << "Incorrect input, try again." << endl;
        //     cin.clear();
        //     while (cin.get() != '\n');
        // }

        // if (!isIncorrect && ((number < MIN_NUMBER) || (number > MAX_NUMBER)))
        // {
        //     isIncorrect = true;
        //     cout << "The number must fit the range [" << MIN_NUMBER << "," << MAX_NUMBER << "]." << endl;
        // }

    } while (isIncorrect);

    return number;
}