#include <iostream>
#include <cstring> 
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
const ll maxn=1e5+5;
struct st
{
    ll num;
    ll id;
    bool operator <(const st&other)const
    {
        return num>other.num;
    }
};
st num1[maxn];
st num2[maxn];
int vis[maxn];
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
        memset(vis,0,sizeof(vis));
        ll n;
        cin>>n;
        ll i;
        wfor(i,0,n)
        {
            cin>>num1[i].num>>num2[i].num;
            num1[i].id=num2[i].id=i;
        }
        sort(num1,num1+n);
        sort(num2,num2+n);
        ll j;
        i=j=0;
        ll ans=1e18+5;
        while(i<n&&j<n)
        {
            if(vis[num1[i].id]==0&&vis[num2[j].id]==0)
            {
                if(num1[i].id==num2[j].id)
                {
                    if(j+1==n&&i+1!=n)
                    {
                        ans=min(ans,abs(num1[i+1].num-num2[j].num));
                    }else if(i+1==n&&j+1!=n)
                        ans=min(abs(num1[i].num-num2[j+1].num),ans);
                    else if(i+1!=n&&j+1!=n)
                        ans=min(ans,min(abs(num1[i].num-num2[j+1].num),abs(num1[i+1].num-num2[j].num)));
                    break;
                }else
                {
                    ans=min(ans,abs(num1[i].num-num2[j].num));
                    if(num1[i].num>num2[j].num)
                    {
                        vis[num1[i].id]=2;
                        i++;
                    }
                    else if(num1[i].num<num2[j].num)
                    {
                        vis[num2[j].id]=1;
                        j++;
                    }
                    else
                    {
                        break;
                    }
                }
            }else
            {
                if(vis[num1[i].id]!=0&&vis[num2[j].id]==0)
                {
                    while(vis[num2[j].id]==0)
                    {
                        ans=min(ans,abs(num1[i].num-num2[j].num));
                        vis[num2[j].id]=1;
                        j++;
                    }
                }else if(vis[num1[i].id]==0&&vis[num2[j].id]!=0)
                {
                    while(vis[num1[i].id]==0)
                    {
                        ans=min(ans,abs(num1[i].num-num2[j].num));
                        vis[num1[i].id]=2;
                        i++;
                    }
                }else if(vis[num1[i].id]!=0&&vis[num2[j].id]!=0)
                {
                    ans=min(ans,abs(num1[i].num-num2[j].num));
                }
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
