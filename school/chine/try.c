#include <stdio.h>
#include<stdlib.h>
int main()
{
    int i = 0;
    char str[6] = {'C', 'h', 'i', 'n', 'a', '\0'}, *ptr, *ptr1, *ptr2 , str2[6]="China";
    while (str[i] != '\0')
    {
        putchar(str[i]);
        i++;
    }
    ptr=(char*)malloc(sizeof(char)*6);
    ptr1=(char*)malloc(sizeof(char)*6);
    ptr2=(char*)malloc(sizeof(char)*6);
    scanf("%s", ptr);
    puts(ptr);
    ptr1 = str;
    puts(ptr1);
    ptr2 = "China";
    puts(ptr2);
    printf("%s", str2);
    free(ptr);
    free(ptr1);
    free(ptr2);
    return 0;
}
