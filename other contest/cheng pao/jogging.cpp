#include <iostream>
using namespace std;
long long gcd (long long a,long long b);
long long lcm(long long a,long long b);
int main()
{
    long long a,b,c;
    cin>>a>>b>>c;
    long long r=lcm(a,lcm(b,c));
    cout<<r;
    return 0;
}
long long gcd (long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}
long long lcm(long long a,long long  b)
{
    return a*b/gcd(a,b);
}
