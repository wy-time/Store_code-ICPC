#include<stdio.h>
int main()
{
    int n = 0;
    int cnt;
    int i = 0;
    int a[5];
    scanf("%d", &n);
    for(i = 0; n > 0; i++)
    {
        a[i] = n % 10;
        n /= 10;
    }
    cnt = i;
    printf("%d\n", cnt);
    for(i = cnt - 1; i >= 0; i--)
    {
        printf("%d%c", a[i], " \n"[i == 0]);
    }
    for(i = 0; i < cnt - 1; i++)
    {
        printf("%d", a[i]);
    }
    printf("%d\n", a[i]);
    return 0;
}
