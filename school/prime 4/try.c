#include <math.h>
#include <stdio.h>
int fun(int m);
main()
{
    int m,k=0;
    for (m = 1; m <= 100; m++)
        if (fun(m) == 1)
        {
            printf("%4d", m);
            k++;
            if(k%5==0)
                printf("\n");
        }
}

int fun(int m)
{
    int i, k = 1;
    if (m <= 1)   k = 0;
    for (i = 2; i < m; i++)
    {
        if (m % i == 0) k = 0;
    }
    return k;
}
