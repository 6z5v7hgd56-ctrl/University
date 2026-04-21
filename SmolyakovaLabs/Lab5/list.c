#include "list.h"

node* fillList(node* head)
{
    const int MAX_LENGTH  =   100;
    const int MAX_ELEMENT =  1000;
    const int MIN_ELEMENT = -1000;

    node* curr;
    node* newElement;
    int listLength, i, element;

    element = 0;
    listLength = 0;

    curr = head;

    printf("%s", "Введите длину будущего списка\n");
    listLength = scanInt(1, MAX_LENGTH, "> ");
    printf("\n");

    for (i = 0; i < listLength; ++i)
    { 
        newElement = (node*)malloc(sizeof(node));
        curr->next = newElement;
        curr = curr->next;

        printf("%s", "Введите значение элемента [%d]\n", i + 1);
        element = scanInt(MIN_ELEMENT, MAX_ELEMENT, "> ");
        curr->data = element;
    }

    return head;
} 

void showList(node* head)
{
    node* curr;

    printf("Лист:\n");

    while (curr->next != NULL)
    { 
        curr = curr->next;
        printf("%d ", curr->data);
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
        printf("%s", myString);
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



