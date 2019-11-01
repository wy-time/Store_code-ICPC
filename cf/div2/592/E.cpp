#include <iostream>
#include <map> 
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
map<ll,ll>ma;
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
    ll n,k;
    cin>>n>>k;
    ll i;
    wfor(i,0,n)
    {
        ll t;
        cin>>t;
        if(ma.count(t)==0)
            ma.insert(make_pair(t,1));
        else
            ma[t]++;
    }
    ll ans=ma.rbegin()->first-ma.begin()->first;
    while(k&&ma.size()>1)
    {
        ll maxnum=ma.rbegin()->first;
        ll maxcnt=ma.rbegin()->second;
        ll minnum=ma.begin()->first;
        ll mincnt=ma.begin()->second;
        if(maxcnt<mincnt)
        {
            ll last=(++ma.rbegin())->first;
            if((maxnum-last)*maxcnt<=k)
            {
                k-=(maxnum-last)*maxcnt;
                ma[last]+=maxcnt;
                ma.erase(maxnum);
            }else
            {
                ll cnt=k/maxcnt;
                ma[maxnum-cnt]+=maxcnt;
                if(cnt!=0)
                    ma.erase(maxnum);
                k=0;
            }
        }else
        {
            ll last=(++ma.begin())->first;
            if((last-minnum)*mincnt<=k)
            {
                k-=(last-minnum)*mincnt;
                ma[last]+=mincnt;
                ma.erase(minnum);
            }else
            {
                ll cnt=k/mincnt;
                ma[minnum+cnt]+=mincnt;
                if(cnt!=0)
                    ma.erase(minnum);
                k=0;
            }
        }
        ans=ma.rbegin()->first-ma.begin()->first;
    }
    cout<<ans<<endl;
    return 0;
}
