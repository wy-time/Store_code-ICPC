#include <iostream>
#include <algorithm> 
#include <cmath> 
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
const ll mod=998244353;
struct st
{
    ll number;
    ll len;
    bool operator <(const st&other)const
    {
        return len>other.len;
    }
}num[maxn];
ll base[22];
void init()
{
    ll i;
    base[0]=1;
    wfor(i,1,22)
        base[i]=base[i-1]*10%mod;
}
ll sum[maxn][12];
ll ans[10];
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
    ll n;
    cin>>n;
    init();
    ll i;
    wfor(i,1,n+1)
    {
        cin>>num[i].number;
        num[i].len=log10(num[i].number)+1;
    }
    sort(num+1,num+n+1);
    sum[1][num[1].len]++;
    wfor(i,2,n+1)
    {
        ll j;
        wfor(j,1,11)
        {
            if(j==num[i].len)
                sum[i][num[i].len]=sum[i-1][num[i].len]+1;
            else
                sum[i][j]=sum[i-1][j];
        }
    }
    wfor(i,1,n+1)
    {
        ll temp=num[i].number;
        ll cnt=0;
        while(temp)
        {
            ll t=temp%10;
            ll T=(base[cnt]%mod+base[cnt+1]%mod)%mod*i%mod;
            ans[t]=(ans[t]+T)%mod;
            temp/=10;
            cnt+=2;
        }
    }
    
    wfor(i,1,n+1)
    {
        ll j;
        wfor(j,1,11)
        {
            ll apper=(sum[n][j]-sum[i][j])%mod;
            if(apper<=0)
                continue;
            ll temp=num[i].number%(ll)pow(10,j);
            ll cnt=0;
            while(temp)
            {
                ll t=temp%10;
                ll T=(base[cnt]%mod+base[cnt+1]%mod)%mod*apper%mod;
                ans[t]=(ans[t]+T)%mod;
                temp/=10;
                cnt+=2;
            }
            cnt=j*2;
            temp=num[i].number/pow(10,j);
            while(temp)
            {
                ll t=temp%10;
                ll T=base[cnt]%mod*2ll*apper%mod;
                ans[t]=(ans[t]+T)%mod;
                cnt++;
                temp/=10;
            }
        }
    }
    ll res=0;
    wfor(i,1,10)
    {
        res=(res+1ll*ans[i]*i%mod)%mod;
    }
    cout<<res<<endl;
    return 0;
}
