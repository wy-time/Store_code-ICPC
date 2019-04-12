#include<stdio.h>
#include<math.h>
int main ()
{
    int i=0;
    for(i=0;i<=5;i++)
    {
        printf("2 power %d is %d, -3 power %d is %d\n",i,(int)pow(2,i),i,(int)pow(-3,i));
    }
    return 0;
}
