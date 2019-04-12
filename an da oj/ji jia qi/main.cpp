#include <iostream>
#include<cstdio>
using namespace std;
int main()
{
    int x;
    double s;
    scanf("%d %lf",&x,&s);
    double sum=0;
    if(x==1)
    {
        if(s<=2.5)
        {
            sum=8;
        }else if(s>2.5&&s<=15)
        {
            sum=8;
            sum+=(s-2.5)*1.4;
        }else
        {
            sum=8+(15-2.5)*1.4;
            sum+=(s-15)*2.1;
        }
    }else
    {
        if(s<=2.5)
        {
            sum=9;
        }else if(s>2.5&&s<=15)
        {
            sum=9;
            sum+=(s-2.5)*1.4;
        }else
        {
            sum=9+(15-2.5)*1.4;
            sum+=(s-15)*2.1;
        }
    }
    printf("%.0f",sum);
    return 0;
}
