/*#include <iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const double PI=acos(-1.0);
const double e=exp(1.0);
int main()
{
    //std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    double result=sqrt(2*PI*n)/e;
    double a=n/e;
    int t=n;
    while(t--)
    {
        result*=a;
        if(result>998244353)
            result=(long long)result%998244353;
    }
    if(result>998244353)
            result=(long long)result%998244353;
    printf("%.0f",result);
    return 0;
}*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double e=exp(1.0);
int main()
{
    //std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    long long result=1;
    while(n)
    {
        result=(result*(n%998244353))%998244353;
        n--;
    }
    double t=result%998244353/e;
    printf("%.0f",t);
    return 0;
}
