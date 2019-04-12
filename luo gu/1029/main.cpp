#include <iostream>
using namespace std;
int gcd(long long a,long long b);
int main()
{
    std::ios::sync_with_stdio(false);
    int x,y;
    cin>>x>>y;
    long long ji=x*y;
    int cnt=0;
    int i;
    for(i=2; i<x; i++)
    {
        if(x%i==0)
        {
            int temp=gcd(x/i,y*i);
            if(temp==x&&ji/temp==y)
                cnt++;
        }
    }
    for(i=2; i<y; i++)
    {
        if(y%i==0)
        {
            int temp=gcd(x*i,y/i);
            if(temp==x&&ji/temp==y)
                cnt++;
        }
    }
    if(cnt!=0)
        cout<<cnt+1;
    else
        cout<<cnt;
    return 0;
}
int gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}
