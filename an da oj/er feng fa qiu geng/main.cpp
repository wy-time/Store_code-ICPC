#include <iostream>
#include<cstdio>
using namespace std;
double f (int a,int b,int c,int d,int e,double x);
int main()
{
    int a,b,c,d,e;
    int x1,x2;
    scanf("%d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&x1,&x2);
    double down=x2;
    double up=x1;
    double t=(up+down)/2;
    if(f(a,b,c,d,e,up)==0)
        printf("%.10f",up);
    else if(f(a,b,c,d,e,down)==0)
        printf("%.10f",down);
    else
    {
        while(f(a,b,c,d,e,t)!=0)
        {
            double temp1=f(a,b,c,d,e,up);
            double temp2=f(a,b,c,d,e,down);
            double temp3=f(a,b,c,d,e,t);
            if(temp3<0)
            {
                if(-temp3<0.00000000001)
                    break;
            }else
            {
                if(temp3<0.00000000001)
                    break;
            }
            if(temp1*temp3<0)
            {
                down=t;
            }else if(temp3*temp2<0)
            {
                up=t;
            }
            t=(up+down)/2;
        }
        printf("%.10f",t);
    }
    return 0;
}
double f (int a,int b,int c,int d,int e,double x)
{
    return a*x*x*x*x+b*x*x*x+c*x*x+d*x+e;
}
