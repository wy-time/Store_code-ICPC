#include <stdio.h>
#define END  -1
long Factorial(int x);
int main()
{
    int x;
    while (1)
    {
        printf("input x:");
        scanf("%d",&x);
        if (x <= END)
            break;
        else
            printf("%d! = %ld\n", x, Factorial(x));
    }
    return 0;
}

long Factorial(int x)
{
    int i;
    int result=1;
    for (i=1;i<=x;i++)
        result *= i;
    return result;
}
