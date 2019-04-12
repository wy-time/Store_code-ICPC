#include<stdio.h>
int main()
{
    int n;
    int i, j;
    int sum, cnt;
    int a[1000];
    scanf("%d", &n);
    for(i = 2; i <=n; i++)
    {
        sum = 0;
        cnt = 0;
        for(j = 1; j < i; j++)
        {
            if(i % j == 0)
            {
                a[cnt] = j;
                sum += j;
                cnt++;
            }
        }
        if(sum == i)
        {
            printf("%d its factors are ",i);
            for(j = 0; j < cnt; j++)
            {
                printf("%d ",a[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
