#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <locale.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

int scanInt(const int MIN_NUMBER, const int MAX_NUMBER, const char myString[]);
node* fillList(node* head);
void showList(node* head);
node* append(node* head);
node* prepend(node* head);
int showNumberedList(node* head);
void findElement(node* head);
node* deleteElement(node* head);
void showMenu();
void menuStage(node* head);
void freeList(node* head);
void writePurpose();

#endif
