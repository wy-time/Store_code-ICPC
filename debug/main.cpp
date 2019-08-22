#include <iostream>
#include <string> 
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
int main()
{
    std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("F:\\Desktop\\question\\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
    freopen("/home/time/debug/debug/in","r",stdin);
    freopen("/home/time/debug/debug/out","w",stdout);
    #endif
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a,b;
        cin>>a>>b;
        string s;
        cin>>s;
        ll i;
        ll ans=n*a+2*b;
        char last='0';
        wfor(i,1,n)
        {
            if(s[i]!=last)
            {
                ans+=2*b+a;
            }else
                ans+=(last-'0'+1)*b;
            last=s[i];
        }
        last='0';
        ll sub=0;
        ll add=0;
        ll flag=0;
        wfor(i,1,n)
        {
            if(flag&&s[i]==last)
                add+=b;
            if(s[i]!=last&&last=='1')
            {
                sub+=a;
                flag=1;
            }else if(s[i]!=last&&flag)
            {
                flag=0;
                sub+=a;
                if(sub>add)
                    ans-=sub-add;
                sub=0;
                add=0;
            }
            last=s[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
