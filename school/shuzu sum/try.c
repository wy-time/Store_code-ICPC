#include<stdio.h>
#include<stdlib.h>
int main ()
{
    int*a,*b;
    int n,i;
    double sum=0;
    printf("Input n\n");
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    b=(int*)malloc(sizeof(int)*n);
    printf("Input array a\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Input array b\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=0;i<n;i++)
    {
        sum+=1.0*a[i]*b[i];
    }
    free(a);
    free(b);
    printf("\n\n");
    printf("sum=%.6f",sum);
    return 0;
}
