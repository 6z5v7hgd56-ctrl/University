// #include <stdio.h>
// #include <stdlib.h>

// typedef struct sNode
// {
//     int value;
//     struct sNode *prev;
//     struct sNode *next;
// } tNode;

// tNode *createList(int n)
// {
//     tNode *p_begin = NULL;
//     tNode *p = NULL;
//     // заполним односвязный список
//     p_begin = (tNode *)malloc(sizeof(tNode));
//     p = p_begin;
//     p->next = NULL;
//     p->prev = NULL;
//     p->value = 1;

//     for (int k = 1; k < n; k++)
//     {
//         p->next = (tNode *)malloc(sizeof(tNode));
//         // шагнуть вперед !!!
//         p->next->prev = p;
//         p = p->next;
//         // заполнить _новую_ структуру данных
//         p->next = NULL;
//         p->value = k + 1;
//     }

//     p->next = p_begin;
//     p_begin->prev = p;

//     return p_begin;
// }

// void printList(tNode *p_begin)
// {
//     tNode *p = p_begin;

//     do
//     {
//         printf("%d ", p->value);
//         p = p->next;
//     }
//     while (p != NULL && p->value > p->prev->value);
//     printf("\n");
// }

// void printCountingRhyme(tNode *p_begin, int len, int countRhyme)
// {
//     tNode *p = p_begin;
//     size_t i, j;

//     i = 1;

//     // while (j > 0)
//     // {
//     //     if (p != NULL)
//     //     {
//     //         if (i == count)
//     //         {
//     //             printf("%d ", p->value);
//     //             i = 1;
//     //             j--;
//     //         }
//     //     }
//     //     else
//     //         p = p_begin;

//     //     p = p->next;
//     //     i++;
//     // }
// }

// void deleteElement(tNode **deletedElement)
// {
//     (*deletedElement)->prev->next = (*deletedElement)->next;
//     (*deletedElement)->next->prev = (*deletedElement)->prev;
//     free(*deletedElement);
// }

// void deleteList(tNode **p_begin)
// {
//     tNode *p = *p_begin;

//     if (p->prev->next != NULL)
//         p->prev->next = NULL;

//     while (p != NULL)
//     {
//         tNode *tmp;
//         tmp = p;

//         p = p->next;
//         // if (p->prev != NULL)
//         //     p->prev = NULL;
//         free(tmp);
//         tmp = NULL;
//     }
// }

// int main(void)
// {
//     tNode *myList;
//     int len;

//     len = 0;

//     scanf("%d", &len);
//     myList = createList(len);

//     printList(myList);
//     //printCountingRhyme(myList, 2);
//     deleteElement(&myList->next);
//     printList(myList);

//     deleteList(&myList);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Node
{
    int number;
    struct Node *next;
} Node;

Node *buildCircle(int n)
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->number = 1;
    head->next = head;

    Node *tail = head;
    for (int i = 2; i <= n; i++)
    {
        Node *node = (Node *)malloc(sizeof(Node));
        node->number = i;
        node->next = head;
        tail->next = node;
        tail = node;
    }
    return head;
}

int countingRhyme(int n, int k, int order[])
{
    Node *cur = buildCircle(n);

    Node *prev = cur;
    while (prev->next != cur)
        prev = prev->next;

    int count = 0;
    while (cur->next != cur)
    {
        for (int step = 1; step < k; step++)
        {
            prev = cur;
            cur = cur->next;
        }
        order[count++] = cur->number;

        Node *del = cur;
        prev->next = cur->next;
        cur = cur->next;
        free(del);
    }

    int last = cur->number;
    order[count] = last;
    free(cur);
    return last;
}

int main(void)
{
    int n, k;

    setlocale(LC_ALL, "Russian");

    printf("Введите количество ребят N: ");
    scanf("%d", &n);
    if (n < 1)
    {
        printf("N должно быть >= 1\n");
        return 1;
    }

    printf("Введите шаг k: ");
    scanf("%d", &k);
    if (k < 1)
    {
        printf("k должно быть >= 1\n");
        return 1;
    }

    int *order = (int *)malloc((n + 1) * sizeof(int));
    int last = countingRhyme(n, k, order);

    printf("\nN = %d, k = %d\n", n, k);
    printf("Порядок выбывания: ");
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d", order[i]);
        if (i < n - 2)
            printf(", ");
    }
    printf("\nОстаётся: %d\n", last);
    free(order);

    printf("\n=== Таблица для N = 1..64, k = %d ===\n\n", k);
    printf(" N  | Порядок выбывания\n");
    printf("----|-------------------\n");

    int *buf = (int *)malloc(65 * sizeof(int));
    for (int i = 1; i <= 64; i++)
    {
        last = countingRhyme(i, k, buf);
        printf("%3d | ", i);
        for (int j = 0; j < i - 1; j++)
        {
            printf("%d", buf[j]);
            if (j < i - 2)
                printf(", ");
        }
        printf(" -> [%d]\n\n", last);
    }
    free(buf);

    return 0;
}