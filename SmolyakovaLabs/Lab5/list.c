#include "list.h"

void showMenu()
{
    printf("\n====== МЕНЮ ======\n");
    printf("1 - Вывести значения списка\n");
    printf("2 - Вставка в начало\n");
    printf("3 - Вставка в конец\n");
    printf("4 - Удаление элемента\n");
    printf("5 - Поиск элемента\n\n");
}

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

        printf("Введите значение элемента [%d]\n", i + 1);
        element = scanInt(MIN_ELEMENT, MAX_ELEMENT, "> ");
        curr->data = element;
    }

    return head;
} 

void showList(node* head)
{
    node* curr;

    curr = head;

    printf("Лист:\n");

    while (curr->next != NULL)
    { 
        curr = curr->next;
        printf("%d ", curr->data);
    }
}

int showNumberedList(node* head)
{
    node* curr;
    int counter;

    curr = head;
    counter = 1;

    while (curr->next != NULL)
    { 
        curr = curr->next;
        printf("[%3d] = %d\n", counter, curr->data);
        counter++;
    }

    counter--;

    return counter;
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

node* append(node* head)
{
    const int MAX_ELEMENT =  1000;
    const int MIN_ELEMENT = -1000;
    node* curr;

    curr = head;

    printf("%s", "\nПроизводится вставка нового элемента в конец\n");

    while (curr->next != NULL)
        curr = curr->next;

    curr->next = (node*)malloc(sizeof(node));
    curr = curr->next;
    printf("%s", "Введите значение элемента\n");
    curr->data = scanInt(MIN_ELEMENT, MAX_ELEMENT, "> ");

    return head;
}

node* prepend(node* head)
{    
    const int MAX_ELEMENT =  1000;
    const int MIN_ELEMENT = -1000;

    node* firstElement;

    printf("%s", "\nПроизводится вставка нового элемента в начало\n");

    firstElement = head->next;

    head->next = (node*)malloc(sizeof(node));
    head->next->next = firstElement;

    printf("%s", "Введите значение элемента\n");
    head->next->data = scanInt(MIN_ELEMENT, MAX_ELEMENT, "> ");
    
    return head;
}

node* deleteElement(node* head)
{
    node* curr;
    node* prev;
    int length, delIndex, i;

    length = 0;
    delIndex = 0;

    prev = head;
    curr = head->next;

    printf("%s", "Введите индекс элемента для его удаления\n");
    length = showNumberedList(head);

    delIndex = scanInt(1, length, "> ");

    for (i = 1; i < delIndex; ++i)
    {
        prev = prev->next;
        curr = curr->next;
    }

    if (curr->next == NULL)
        prev->next = NULL;
    else
        prev->next = curr->next;

    free(curr);

    return head;
}

void findElement(node* head)
{
    node* curr;

    curr = head->next;

    
}

