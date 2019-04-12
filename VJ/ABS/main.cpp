#include <iostream>
#include<math.h>
#include<cstdio>
using namespace std;
int main()
{
    double a;
    while(scanf("%lf",&a)!=EOF)
    {
        printf("%.2f\n",fabs(a));
    }
    return 0;
}
