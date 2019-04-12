#include<stdio.h>
int main ()
{
    int a, b, t, sum,cnt;
    int n;
    int i = 0, j;
    scanf("%d", &n);
    while (n--)
    {
        cnt=0;
        scanf("%d %d", &a, &b);
        if(a > b)
        {
            t = a;
            a = b;
            b = t;
        }
        for(i = a; i <= b; i++)
        {
            sum=0;
            for(j = 1; j < i; j++)
            {
                if(i % j == 0)
                {
                    sum += j;
                }
            }
            if(sum==i){
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
