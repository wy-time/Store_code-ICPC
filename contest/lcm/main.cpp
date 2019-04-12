#include <iostream>
using namespace std;
unsigned long long gcd(unsigned long long a, unsigned long long b);
int main()
{
    std::ios::sync_with_stdio(false);
    unsigned long long a,b;
    cin>>a>>b;
    unsigned long long gc=gcd(a,b);
    cout<<a/gc*b;
    return 0;
}
unsigned long long gcd(unsigned long long a, unsigned long long b)
{
    return b==0?a:gcd(b,a%b);
}
