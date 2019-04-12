#include<stdio.h>
typedef struct
{
    int year;
    int mon;
    int day;
} date;
int main ()
{
    date a;
    int result=0;
    scanf("%d %d %d",&a.year,&a.mon,&a.day);
    int b[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    if((a.year%4==0&&a.year%100!=0)||(a.year%400==0))
    {
        result =1;
    }
    int i=0;
    for(i=0;i<=a.mon-2;i++)
    {
        result+=b[i];
    }
    result+=a.day;
    printf("%d",result);
    return 0;
}
