#include <iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t=0;
    scanf("%d",&t);
    while(t--)
    {
        double a,b;
        scanf("%lf %lf",&a,&b);
        printf("%.6f",a/b);
    }
    return 0;
}
