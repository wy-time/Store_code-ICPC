#include<stdio.h>
#include<stdlib.h>
int cmp1(const void *p, const void *q);
int cmp2(const void *p, const void *q);
int main ()
{
    int a[10];
    int i;
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    if(a[0] - a[8] < 0)
    {
        qsort(&a[0], 10, sizeof(a[0]), cmp1);
    }
    else
    {
        qsort(&a[0], 10, sizeof(a[0]), cmp2);
    }
    for(i = 0; i < 10; i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}
int cmp1(const void *p, const void *q)
{
    return(*(int*)p - * (int*)q);
}
int cmp2(const void *p, const void *q)
{
    return (*(int*)q - * (int*)p);
}
