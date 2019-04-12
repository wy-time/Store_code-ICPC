#include <iostream>
using namespace std;
int gcd(int a,int b);
int lcm(int a,int b);
int main()
{
    std::ios::sync_with_stdio(false);
    int a,b,c;
    cin>>a>>b>>c;
    cout<<lcm(lcm(a,b),c);
    return 0;
}
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}
