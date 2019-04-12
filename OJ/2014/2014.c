#include<stdio.h>
#include<stdlib.h>
int main ()
{
    double x1 = 0, x2 = 0, a = 0;
    scanf("%lf", &a);
    x1 = a / 2;
    x2 = (x1 + (a / x1)) / 2;
    int safe = 1;
    while((x1 - x2) >= 0.00001 || x2 - x1 >= 0.00001)
    {
        x1 = (x2 + a / x2) / 2;
        if((x1 - x2) < 0.00001 && x1 - x2 >= 0 || x2 - x1 < 0.00001 && x2 - x1 >= 0)
        {
            printf("%.3f\n", x1);
            safe = 0;
            break;
        }
        else
        {
            x2 = (x1 + a / x1) / 2;
        }
    }
    if(safe)
    {
        printf("%.3f\n", x2);
    }
    return 0;
}
