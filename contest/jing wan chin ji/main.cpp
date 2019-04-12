#include <iostream>
#include<cstdio>
using namespace std;
int main()
{
    //std::ios::sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double l,v1,v2;
        scanf("%lf %lf %lf",&l,&v1,&v2);
        double l1=0.5*9.8*l*l/(v1*v1);
        double l2=l/v1*v2;
        printf("%.6f %.6f\n",l1,l2);
    }
    return 0;
}
