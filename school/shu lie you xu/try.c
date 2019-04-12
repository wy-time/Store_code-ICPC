#include<stdio.h>
#include<stdlib.h>
int cmp (const void *a,const void *b)
{
    int *c=(int*)a;
    int *d=(int*)b;
    return *c>*d;
}
int main ()
{
    int a[20]={2,4,6,8,10,12,14,16};
    printf("Enter n:");
    scanf("%d",&a[8]);
    qsort(a,9,sizeof(int),cmp);
    int i=0;
    for(i=0;i<9;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
