#include<stdio.h>
#include<math.h>
int judge (int x);
int main ()
{
    int x = 0;
    int p;
    scanf("%d", &x);
    p = judge(x);
    if (p == 1)
    {
        printf("not prime\n");
    }
    else
    {
        printf("prime\n");
    }
    return 0;
}
int judge (int x)
{
    if(x == 1)
    {
        return 1;
    }
    int p = 0;
    int i;
    for (i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            p = 1;
            break;
        }
    }
    return p;
}
