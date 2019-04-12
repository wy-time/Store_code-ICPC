#include<stdio.h>
int main ()
{
    int i = 100;
    int t, sum;
    for(i = 100; i < 1000; i++)
    {
        t = i;
        sum = 0;
        while(t != 0)
        {
            sum += (t % 10) * (t % 10) * (t % 10);
            t /= 10;
        }
        if(sum == i)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}
