#include<stdio.h>
int main ()
{
    char s;
    while((s=getchar())!='a')
    {
        putchar(s);
    }
    return 0;
}
