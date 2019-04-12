#include<stdio.h>
#define PI 3.14159
int main ()
{
    int h,r;
    int safe =1;
    printf("Please input the height and the radius:");
    scanf("height=%d,radius=%d",&h,&r);
    double s=PI*r*r*h;
    s/=1000;
    int i=1;
    for(i=1;s<20;i++)
    {
        s*=i;
        safe =0;
    }
    if(safe)
        printf("%d",i);
    else
        printf("%d",i-1);
    return 0;
}
