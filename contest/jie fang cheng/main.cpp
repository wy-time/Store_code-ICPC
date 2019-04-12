#include <iostream>
#include<cmath>
#include<cstdio>
using namespace std;
double f(double x);
int main()
{
    //std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        double y;
        cin>>y;
        double l=0,r=100.0;
        double mid=0;
        if(f(0)>y||f(100)<y)
        {
            cout<<-1<<endl;
            continue;
        }
        while(l<=r)
        {
            mid=(l+r)/2.0;
            if(f(mid)<y)
                l=mid;
            else if(f(mid)>y)
                r=mid;
            else
                break;
            if(fabs(f(mid)-y)<0.00001)
                break;
        }
            printf("%.4f\n",mid);
    }
    return 0;
}
double f(double x)
{
    return 2018*pow(x, 4) + 21*x + 5*pow(x, 3) + 5*x*x + 14;
}
