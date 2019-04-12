#include<stdio.h>
#include<string.h>
void trance(char*p, int len1);
int main ()
{
    char a[10000];
    gets(a);
    int i=0;
    int len = strlen(a);
    trance(a, len);
    for(i = 0; i < len; i++)
    {
        printf("%c", a[i]);
    }
    printf("\n");
    return 0;
}
void trance(char*p, int len1)
{
    int i;
    char t;
    for(i = 0; i < len1 / 2; i++)
    {
        t = p[i];
        p[i] = p[len1 - 1 - i];
        p[len1 - 1 - i] = t;
    }
}
