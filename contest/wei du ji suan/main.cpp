#include <iostream>
#include<cmath>
#include<cstdio>
#include<iomanip>
using namespace std;
const int R=6371009;
const double PI=acos(-1.0);
int main()
{
    //std::ios::sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double a,b,c,d;
        scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
        a*=PI/180;
        b*=PI/180;
        c*=PI/180;
        d*=PI/180;
        double x=R*sqrt(2-2*(cos(a)*cos(c)*cos(b-d)+sin(a)*sin(c)));
        printf("%.0f\n",2.0*asin(x/(2.0*R))*R-x);
    }
    return 0;
}
