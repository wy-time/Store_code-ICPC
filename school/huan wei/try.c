#include<stdio.h>
#include<stdlib.h>
int main ()
{
    int n,m;
    int *a;
    int i;
    printf("the total numbers is:");
    scanf("%d",&n);
    printf("back m:");
    scanf("%d",&m);
    a=(int*)malloc(sizeof(int)*(n+m));
    for(i=0;i<n;i++)
    {
        a[i+m]=i+1;
    }
    for(i=0;i<m;i++)
    {
        a[m-i-1]=a[n+m-1-i];
    }
    for(i=0;i<n-1;i++)
    {
        printf("%d,",a[i]);
    }
    printf("%d",a[i]);
    free(a);
    return 0;
}
