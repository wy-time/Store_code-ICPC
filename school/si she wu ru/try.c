#include<stdio.h>
int main ()
{
    int i=0;
    printf("Old array:\n");
    float a[5]={2.33,2.56,2.65,2.66,2.30};
    for(i=0;i<5;i++)
    {
        printf("a[%d]=%.3f\t",i,a[i]);
    }
    printf("\nnew array:\n");
    for(i=0;i<5;i++)
    {
        printf("a[%d]=%.1f0\t",i,a[i]);
    }
    return 0;
}
