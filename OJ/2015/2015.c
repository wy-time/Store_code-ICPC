#include<stdio.h>
#include<math.h>
int main ()
{
    int n, i, j, safe;
    scanf("%d", &n);
    for(i = 2; i <= n; i++)
    {
        safe = 1;
        for(j = 2; j <= sqrt(i); j++)
        {
            if(i % j == 0)
            {
                safe = 0;
                break;
            }
        }
        if(safe)
        {
            printf("%d\n", i);
        }

    }
    return 0;
}
