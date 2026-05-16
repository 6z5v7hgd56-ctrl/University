#include "stdio.h"
#include "locale.h"
#include "malloc.h"

 int main(void) 
{
    int i;
    i = 1;

    printf("%d\n", i++ + ++i);

    return 0;
}