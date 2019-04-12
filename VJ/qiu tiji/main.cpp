#include <iostream>
#include<cstdio>
#define PI 3.1415927
using namespace std;
int main()
{
    double n;
    while(scanf("%lf",&n)!=EOF)
    {
        printf("%.3f\n",(4.0/3.0)*PI*n*n*n);
    }
    return 0;
}
