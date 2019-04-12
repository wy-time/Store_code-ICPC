#include <stdio.h>
int MaxCommonFactor(int a, int b);
int main()
{
    int a, b, x;

    scanf("%d,%d", &a, &b);

    x = MaxCommonFactor(a, b);
    if (x < 0)
        printf("-1");
    else
        printf("%d\n", x);
    return 0;
}

int MaxCommonFactor(int a,int b)
{
    int c;
    if (a <= 0 || b <= 0)
        return -1;
    if(a<b)
    {
        c=a;
        a=b;
        b=c;
    }
    c=a%b;
    while(c!=0)
    {
        a=b;
        b=c;
        c=a%b;
    }
    return  b;
}
