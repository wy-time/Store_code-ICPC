#include <iostream>
#include <cstring> 
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
struct st
{
    ll num[5];
    ll sum[7];
    ll number;
    st(){
        memset(num,0,sizeof(num));
        memset(sum,0,sizeof(sum));
    }
};
st info[maxn];
ll dp[maxn][10];
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
    ll i;
    ll tot=0;
    wfor(i,1,n+1)
    {
        ll k;
        cin>>k;
        ll j;
        wfor(j,0,k)
        {
            ll c,v;
            cin>>c>>v;
            if(c==1)
            {
                if(v>info[i].num[0])
                {
                    info[i].num[2]=info[i].num[1];
                    info[i].num[1]=info[i].num[0];
                    info[i].num[0]=v;
                }
                else if(v>info[i].num[1])
                {
                    
                    info[i].num[2]=info[i].num[1];
                    info[i].num[1]=v;
                }
                else if(v>info[i].num[2])
                    info[i].num[2]=v;
            }else if(c==2)
            {
                if(v>info[i].num[3])
                    info[i].num[3]=v;
            }else 
                if(v>info[i].num[4])
                    info[i].num[4]=v;
        }
        info[i].sum[1]=max(info[i].num[0],max(info[i].num[3],info[i].num[4]));
        info[i].sum[2]=max(info[i].num[0]!=0&&info[i].num[3]!=0?info[i].num[0]+info[i].num[3]:0,info[i].num[0]!=0&&info[i].num[1]!=0?info[i].num[1]+info[i].num[0]:0);
        if(info[i].num[2]!=0)
            info[i].sum[3]=info[i].num[2]+info[i].num[1]+info[i].num[0];
        else
            info[i].sum[3]=0;
        info[i].sum[4]=info[i].sum[1]*2;
        if(info[i].sum[2]!=0)
        {
            ll temp=0;
            if(info[i].num[1]!=0)
                temp=info[i].num[0]*2+info[i].num[1];
            if(info[i].num[3]!=0)
                temp=max(temp,info[i].num[0]+info[i].num[3]+max(info[i].num[0],info[i].num[3]));
            info[i].sum[5]=temp;
        }else
            info[i].sum[5]=0;
        if(info[i].sum[3]!=0)
            info[i].sum[6]=info[i].num[2]+info[i].num[1]+info[i].num[0]*2;
        else
            info[i].sum[6]=0;
        if(info[i].sum[3]!=0)
            info[i].number=3;
        else if(info[i].sum[2]!=0)
            info[i].number=2;
        else
            info[i].number=1;
    }
    wfor(i,1,n+1)
    {
        ll j;
        tot+=info[i].number;
        ll temp=info[i].number;
        wfor(j,0,10)
        {
            if(j>tot)
                break;
            if(j!=0)
            {
                if(tot<10)
                    dp[i][j]=max(dp[i-1][j],max(tot-temp>=(j+9)%10&&info[i].sum[1]!=0?dp[i-1][(j+9)%10]+info[i].sum[1]:0,max(tot-temp>=(j+8)%10&&info[i].sum[2]!=0?dp[i-1][(j+8)%10]+info[i].sum[2]:0,tot-temp>=(j+7)%10&&info[i].sum[3]!=0?dp[i-1][(j+7)%10]+info[i].sum[3]:0)));
                else
                {
                    if(j==1)
                        dp[i][j]=max(dp[i-1][j],max(tot-temp>=(j+9)%10&&info[i].sum[1]!=0?dp[i-1][(j+9)%10]+info[i].sum[1]:0,max(tot-temp>=(j+8)%10&&info[i].sum[5]!=0?dp[i-1][(j+8)%10]+info[i].sum[5]:0,tot-temp>=(j+7)%10&&info[i].sum[6]!=0?dp[i-1][(j+7)%10]+info[i].sum[6]:0)));
                    else if(j==2)
                        dp[i][j]=max(dp[i-1][j],max(tot-temp>=(j+9)%10&&info[i].sum[1]!=0?dp[i-1][(j+9)%10]+info[i].sum[1]:0,max(tot-temp>=(j+8)%10&&info[i].sum[2]!=0?dp[i-1][(j+8)%10]+info[i].sum[2]:0,tot-temp>=(j+7)%10&&info[i].sum[6]!=0?dp[i-1][(j+7)%10]+info[i].sum[6]:0)));
                    else
                        dp[i][j]=max(dp[i-1][j],max(tot-temp>=(j+9)%10&&info[i].sum[1]!=0?dp[i-1][(j+9)%10]+info[i].sum[1]:0,max(tot-temp>=(j+8)%10&&info[i].sum[2]!=0?dp[i-1][(j+8)%10]+info[i].sum[2]:0,tot-temp>=(j+7)%10&&info[i].sum[3]!=0?dp[i-1][(j+7)%10]+info[i].sum[3]:0)));
                }
            }
            else if(tot>=10)
                dp[i][j]=max(dp[i-1][j],max(tot-temp>=(j+9)%10&&info[i].sum[4]!=0?dp[i-1][(j+9)%10]+info[i].sum[4]:0,max(tot-temp>=(j+8)%10&&info[i].sum[5]!=0?dp[i-1][(j+8)%10]+info[i].sum[5]:0,tot-temp>=(j+7)%10&&info[i].sum[6]!=0?dp[i-1][(j+7)%10]+info[i].sum[6]:0)));
            else
                dp[i][j]=0;
        }
    }
    ll ans=0;
    wfor(i,0,10)
        ans=max(ans,dp[n][i]);
    cout<<ans<<endl;
    return 0;
}
