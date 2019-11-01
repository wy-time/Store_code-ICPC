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
const ll maxn=1e5+5;
const ll mod=1e9+7;
ll ans[maxn];
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
    ll i;
    ans[1]=1;
    ans[2]=2;
    wfor(i,3,maxn)
    {
        ans[i]=ans[i-1]+ans[i-2];
        ans[i]%=mod;
    }
    string s;
    cin>>s;
    ll flag=1;
    ll cnt1=0;
    ll cnt2=0;
    ll res=1;
    wfor(i,0,s.length())
    {
        if(s[i]=='w'||s[i]=='m')
        {
            flag=0;
            break;
        }else
        {
            if(s[i]=='u')
            {
                if(cnt2!=0)
                {
                    res=res*ans[cnt2]%mod;
                }
                cnt2=0;
                cnt1++;
            }else if(s[i]=='n')
            {
                if(cnt1!=0)
                    res=res*ans[cnt1]%mod;
                cnt1=0;
                cnt2++;
            }else
            {
                if(cnt2!=0)
                {
                    res=res*ans[cnt2]%mod;
                }
                if(cnt1!=0)
                    res=res*ans[cnt1]%mod;
                cnt2=cnt1=0;
            }
        }
    }
    if(cnt2!=0)
    {
        res=res*ans[cnt2]%mod;
    }
    if(cnt1!=0)
        res=res*ans[cnt1]%mod;
    if(flag==1)
        cout<<res<<endl;
    else
        cout<<0<<endl;
    return 0;
}
