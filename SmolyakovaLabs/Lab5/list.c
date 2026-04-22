#include "list.h"

void showMenu()
{
    printf("\n====== МЕНЮ ======\n");
    printf("1 - Вывод значений списка\n");
    printf("2 - Вставка в начало\n");
    printf("3 - Вставка в конец\n");
    printf("4 - Вставка по индексу\n");
    printf("5 - Удаление элемента\n");
    printf("6 - Поиск элемента\n");
    printf("7 - Проверка отсортирован ли список\n");
    printf("0 - Выход\n\n");
}

void writePurpose()
{
    printf("Программа демонстрирует работу со списками и работу функций добавления, удаления, поиска элементов в нём, а также проверку является ли список отсортированным по не убыванию\n");
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

    curr->next = NULL;

    return head;
} 

void showList(node* head)
{
    node* curr;

    curr = head;

    printf("Список:\n");

    if (head->next == NULL)
    {
        printf("Список пуст\n");
        return;
    }

    while (curr->next != NULL)
    { 
        curr = curr->next;
        printf("%d ", curr->data);
    }
    printf("\n");
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
    curr->next = NULL;

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

node* insert(node* head)
{
    const int MAX_ELEMENT =  1000;
    const int MIN_ELEMENT = -1000;
    node* curr;
    node* prev;
    node* new;
    int length, insIndex, i;

    length = 0;
    insIndex = 0;

    if (head->next == NULL)
    {
        printf("Список пуст\n");
        return head;
    }

    prev = head;
    curr = head->next;

    printf("%s", "Введите индекс элемента для вставки туда\n");
    length = showNumberedList(head);

    insIndex = scanInt(1, length, "> ");

    for (i = 1; i < insIndex; ++i)
    {
        prev = prev->next;
        curr = curr->next;
    }

    new = (node*)malloc(sizeof(node));

    prev->next = new;
    new->next = curr;
    
    printf("%s", "Введите значение элемента\n");
    new->data = scanInt(MIN_ELEMENT, MAX_ELEMENT, "> ");

    return head;
}

node* deleteElement(node* head)
{
    node* curr;
    node* prev;
    int length, delIndex, i;

    length = 0;
    delIndex = 0;

    if (head->next == NULL)
    {
        printf("Список пуст\n");
        return head;
    }

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
    const int MAX_ELEMENT =  1000;
    const int MIN_ELEMENT = -1000;
    node* curr;
    int target, index;
    _Bool isNotFound;

    curr = head->next;
    isNotFound = 1;
    index = 0;
    target = 0;

    if (head->next == NULL)
    {
        printf("Список пуст\n");
        return;
    }

    printf("Введите искомый элемент\n");
    target = scanInt(MIN_ELEMENT, MAX_ELEMENT, "> ");

    while (curr != NULL && isNotFound)
    {
        index++;

        if (curr->data == target)
            isNotFound = 0;
        
        curr = curr->next;
    }

    if (isNotFound)
        printf("Элемент в списке отсутствует\n");
    else
        printf("Элемент найден по индексу %d\n", index);
}

void checkIsSorted(node* head)
{
    node* curr;
    curr = head->next;
    _Bool isSorted;

    isSorted = 1;

    if (head->next == NULL)
    {
        printf("Список пуст\n");
        return;
    }

    while (curr->next != NULL && isSorted)
    {
        if (curr->data > curr->next->data)
            isSorted = 0;
        curr = curr->next;
    }

    if (isSorted)
        printf("Значения списка отсортированы по не убыванию\n");
    else
        printf("Значения списка НЕ являются отсортированными\n");

}

void menuStage(node* head)
{
    const int MAX_OPTION = 7;
    const int MIN_OPTION = 0;
    int option;

    option = 0;

    do {
        showMenu();
        option = scanInt(MIN_OPTION, MAX_OPTION, "> ");
        
        switch(option) {
            case 1: showList(head); 
                break;
            case 2: prepend(head);
                break;
            case 3: append(head);  
                break;
            case 4: insert(head); 
                break;
            case 5: deleteElement(head); 
                break;
            case 6: findElement(head); 
                break;
            case 7: checkIsSorted(head); 
                break;
            case 0: printf("\n====== ВЫХОД ======\n"); 
                break;
        }

    } while (option != 0);
}

void freeList(node* head)
{    
    if (head == NULL) 
        return;  

    freeList(head->next);
    free(head);
}