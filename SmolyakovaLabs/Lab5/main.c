#include "list.h"

int main(void)
{
    node* head;

    setlocale(LC_ALL, "Russian");

    head = (node*)malloc(sizeof(node));
    head->next = NULL;
    head->data = 0;

    writePurpose();

    fillList(head);
    showNumberedList(head);

    menuStage(head);

    freeList(head);    
    head = NULL;

    return 0;
}

