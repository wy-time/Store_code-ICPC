#include<stdio.h>
int main ()
{
    char a[4], b[4];
    while(gets(a) != NULL)
    {
        if(a[0] >= a[1] && a[0] >= a[2])
        {
            b[2] = a[0];
            if(a[1] >= a[2])
            {
                b[1] = a[1];
                b[0] = a[2];
            }
            else
            {
                b[1] = a[2];
                b[0] = a[1];
            }
        }
        else if(a[1] >= a[0] && a[1] >= a[2])
        {
            b[2] = a[1];
            if(a[0] >= a[2])
            {
                b[0] = a[2];
                b[1] = a[0];
            }
            else
            {
                b[0] = a[0];
                b[1] = a[2];
            }
        }
        else if(a[2] >= a[0] && a[2] >= a[1])
        {
            b[2] = a[2];
            if(a[0] >= a[1])
            {
                b[0] = a[1];
                b[1] = a[0];
            }
            else
            {
                b[0] = a[0];
                b[1] = a[1];
            }
        }
        printf("%c %c %c\n", b[0], b[1], b[2]);
    }
    return 0;
}
