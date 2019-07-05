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
const ll INF=(1ll<<32)-1;
ll num[100005];
int vis[100005];
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
    ll now=0;
    ll flag=0;
    ll cnt=0;
    wfor(i,0,n)
    {
        string s;
        cin>>s;
        if(flag||now>INF)
        {
            flag=1;
            break;
        }
        if(s=="add")
        {
            ll i;
            ll temp=1;
            wfor(i,0,cnt)
            {
                temp*=num[i];
                if(now+temp>INF)
                {
                    flag=1;
                    break;
                }
            }
            if(!flag)
                now+=temp;
        }
        else if(s=="for")
        {
            ll t;
            cin>>t;
            if(t!=1)
                num[cnt++]=t;
            else
                vis[cnt]++;
        }else
        {
            if(vis[cnt])
                vis[cnt]--;
            else
                cnt--;
        }
    }
    if(now>INF)
        flag=1;
    if(flag)
        cout<<"OVERFLOW!!!"<<endl;
    else
        cout<<now<<endl;
    return 0;
}
