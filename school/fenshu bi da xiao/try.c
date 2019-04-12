#include<stdio.h>
int main ()
{
    int a,b,c,d;
    printf("Input two fractions\n");
    scanf("%d/%d,%d/%d",&a,&b,&c,&d);
    if(a*d>c*b)
    {
        printf("%d/%d>%d/%d\n",a,b,c,d);
    }
    else if(a*d<c*b)
    {
        printf("%d/%d<%d/%d\n",a,b,c,d);
    }
    else
        printf("%d/%d=%d/%d\n");
    return 0;
}
