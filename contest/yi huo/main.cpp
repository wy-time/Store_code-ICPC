#include <iostream>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b);
int main()
{
    std::ios::sync_with_stdio(false);
    ll a,b,c,d;
    while(cin>>a>>b>>c>>d)
    {
        ll cnt=0;
        if(c>=a&&c<=b)
        {
            cnt=min(b-c+1,d-c+1);
        }
        else if(d>=a&&d<=b)
        {
            cnt=min(d-c+1,d-a+1);
        }
        else if(c<a&&d>b)
            cnt=b-a+1;
        ll mom=(b-a+1)*(d-c+1);
        if(cnt!=0)
        {
            while(1)
            {
                ll t=gcd(mom,cnt);
                if(t==1)
                    break;
                else
                {
                    mom/=t;
                    cnt/=t;
                }
            }
        }else
            mom=1;
        cout<<cnt<<"/"<<mom<<endl;
    }
    return 0;
}
ll gcd(ll a,ll b)
{
    return b==0?a:gcd(b,a%b);
}
