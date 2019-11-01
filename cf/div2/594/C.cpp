#include <iostream>
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
const ll mod=1e9+7;
ll ksm(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
const int maxn=1e5+5;
ll dp[maxn][2][2];
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
    ll n,m;
    cin>>n>>m;
    if(n==1&&m==1)
        cout<<2<<endl;
    else
    {
        dp[1][1][0]=1;
        dp[1][0][0]=1;
        dp[1][1][1]=0;
        dp[1][0][1]=0;
        dp[2][1][0]=1;
        dp[2][1][1]=1;
        dp[2][0][0]=1;
        dp[2][0][1]=1;
        int i;
        wfor(i,3,maxn)
        {
            dp[i][1][0]=(dp[i-1][0][1]+dp[i-1][1][1])%mod;
            dp[i][1][1]=(dp[i-1][0][1])%mod;
            dp[i][0][1]=(dp[i-1][1][0]+dp[i-1][0][0])%mod;
            dp[i][0][0]=dp[i-1][1][0]%mod;
        }
        ll ans=(((dp[m][0][0]+dp[m][0][1])%mod+dp[m][1][0])%mod+dp[m][1][1])%mod;
        ans=((((ans+dp[n][0][0])%mod+dp[n][0][1])%mod+dp[n][1][0])%mod+dp[n][1][1])%mod;
        //if(n>2)
        //{
        //    n-=2;
        //    if(n%2==0)
        //        ans+=ksm(2,n/2+2);
        //    else
        //        ans+=ksm(2,(n-2)/2+2);
        //}else
        //{
        //    ans+=ksm(2,n);
        //}
        cout<<(ans-2+mod)%mod<<endl;
    }
    return 0;
}
