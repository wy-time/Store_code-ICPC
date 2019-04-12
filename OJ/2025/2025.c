#include<stdio.h>
#include<string.h>
void cat (char *a, char *b, char*c);
int main ()
{
    int i;
    char a[1000];
    char b[1000];
    char c[2000];
    gets(a);
    gets(b);
    cat(a, b, c);
    int len = strlen(c);
    for(i = 0; i < len; i++)
    {
        printf("%c", c[i]);
    }
    printf("\n");
    return 0;
}
void cat (char *a, char *b, char*c)
{
    int len1, len2;
    len1 = strlen(a);
    len2 = strlen(b);
    int i = 0, j = 0;
    for(i = 0; i < len1; i++)
    {
        c[i] = a[i];
    }
    for(j = 0; j < len2; j++)
    {
        c[i] = b[j];
        i++;
    }
    c[i] = '\0';
}
