#include<stdio.h>
int main ()
{
    int a[12];
    int i;
    printf("\n");
    for(i=6;i<12;i++)
    {
        scanf("%d\n",&a[i]);
        printf("%d ",a[i]);
    }
    printf("\n");
    i=0;
    int j=0;
    for(i=1;i<6;i++)
    {
        a[6-i]=a[12-i];
        for(j=6-i;j<=11-i;j++)
        {
            printf("%d ",a[j]);
        }
        printf("\n");
    }
    return 0;
}
