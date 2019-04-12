#include<stdio.h>
int main ()
{
    printf("Please input 10 interger number\n");
    int a[10];
    int b[10]= {-5,-89,-89,0,0,0,75,93,48,2};
    int i=0,j=9,k=0;
    for(i=0; i<10; i++)
    {
        scanf("%d",&a[i]);
    }
    /*for(i=0; i<10; i++)
    {
        if(a[i]>0)
        {
            b[j]=a[i];
            j--;
        }
        else if(a[i]<0)
        {
            b[k]=a[i];
            k++;
        }
    }*/
    for(i=0; i<10; i++)
    {
        printf("%5d",b[i]);
    }
    return 0;
}
