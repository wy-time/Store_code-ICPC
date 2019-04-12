#include <iostream>
#include<iomanip>
#include<cstdio>
using namespace std;
int main()
{
    //std::ios::sync_with_stdio(false);
    int n;
    scanf("%d",&n);
    while(n--)
    {
        double a,v1,v2;
        scanf("%lf %lf %lf",&a,&v1,&v2);
        if(a==0)
            printf("0.0000000000\n");
        else if(v1<=v2||v1<=0)
            printf("Infinity\n");
        else
        {
            printf("%.10f\n",a*v1/(v1*v1-v2*v2));
        }
    }
    return 0;
}
