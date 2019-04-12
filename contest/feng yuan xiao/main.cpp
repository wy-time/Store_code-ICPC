#include <iostream>
using namespace std;
long long ksm(long long a,long long b,long long e);
int main()
{
    std::ios::sync_with_stdio(false);
    long long a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    long long a1=((a%e)*(b%e))%e;
    long long b1=c*d;
    if(a==0||b==0||c==0||d==0)
        cout<<0;
    else
        cout<<ksm(a1,b1,e);
    return 0;
}
long long ksm(long long a,long long b,long long e)
{
    long long ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=((ans%e)*(a%e))%e;
        }
        a=((a%e)*(a%e))%e;
        b>>=1;
    }
    return ans;
}
