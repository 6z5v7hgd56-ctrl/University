#include <iostream>
#include <iomanip>
#include <string.h>

int main()
{
    char str1[5] = "abcd";
    char str2[20];

    //scanf("%s", &str1);
    fgets(str2, sizeof(str2), stdin);

    size_t len = strlen(str2);
    if (len > 0 && str2[len - 1] == '\n')
    {
        str2[len - 1] = '\0';
    }   

    //printf("%s\n", str1);
    printf("%zu\n", strlen(str2));
    printf("%s\n", str2);
    return 0;
}