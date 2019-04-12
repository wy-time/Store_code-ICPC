#include <iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r1,r2,r3;
        cin>>r1>>r2>>r3;
        double a=1;
        double b=-(r1+r3);
        double c=-(r1*r2+r2*r3);
        double r=0;
        double delat=b*b-4*a*c;
        r=(-b+sqrt(delat))/(2*a);
        printf("%.2f\n",r);
    }
    return 0;
}
