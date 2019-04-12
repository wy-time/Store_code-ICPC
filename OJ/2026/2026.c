#include<stdio.h>
#include<string.h>
void find(char *a, char *b);
int main()
{
    int i = 0;
    char a[1000];
    char b[1000];
    gets(a);
    find(a, b);
    int len = strlen(b);
    for(i = 0; i < len; i++)
    {
        printf("%c", b[i]);
    }
    printf("\n");
    return 0;
}
void find(char *a, char *b)
{
    int len1 = strlen(a);
    int i = 0, j = 0;
    for(i = 0; i < len1; i++)
    {
        if(a[i] == 'A' || a[i] == 'a' || a[i] == 'E' || a[i] == 'e' || a[i] == 'I' || a[i] == 'i' || a[i] == 'O' || a[i] == 'o' || a[i] == 'U' || a[i] == 'u')
        {
            b[j] = a[i];
            j++;
        }
    }
}
