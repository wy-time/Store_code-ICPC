#include<stdio.h>
#include<stdlib.h>
int cmp(const void*p, const void *q);
int main ()
{
    int a[10];
    int i;
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    qsort(&a[0], 10, sizeof(a[0]), cmp);
          for(i = 0; i < 10; i++)
{
    printf("%d\n", a[i]);
    }
    return 0;
}
int cmp(const void *p, const void *q)
{
    return(*(int*)p - * (int*)q);
}
