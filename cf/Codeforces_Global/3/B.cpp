#include <iostream>
#include <algorithm> 
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
const ll maxn=2e5+5;
ll numa[maxn];
ll numb[maxn];
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
    ll n,m,ta,tb,k;
    cin>>n>>m>>ta>>tb>>k;
    ll i;
    wfor(i,0,n)
    {
        cin>>numa[i];
    }
    wfor(i,0,m)
    {
        cin>>numb[i];
    }
    ll flag=0;
    ll ans=0;
    if(k>=n||k>=m)
        flag=1;
    if(!flag)
    {
        wfor(i,0,n)
        {
            ll rest=k-i;
            if(rest<0)
                break;
            ll now=numa[i]+ta;
            ll pos=lower_bound(numb,numb+m,now)-numb;
            pos+=rest;
            if(pos>=m)
            {
                flag=1;
                break;
            }else
                ans=max(ans,numb[pos]+tb);
        }
    }
    if(flag)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
    return 0;
}
