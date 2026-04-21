#include "list.h"

int main(void)
{
    node* head;

    setlocale(LC_ALL, "Russian");

    head = (node*)malloc(sizeof(node));
    head->next = NULL;
    head->data = 0;

    fillList(head);

    printf("  A%dA  \n", head->next->data);

    showNumberedList(head);


    return 0;
}

