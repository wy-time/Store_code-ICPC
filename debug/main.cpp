#include <iostream>
#include <set> 
#include <map> 
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn=400;
ll ksm(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=ans*a;
        a*=a;
        b>>=1;
    }
    return ans;
}
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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll i;
        map <ll ,ll >ma;
        ll j;
        set <ll>vis;
        wfor(j,0,n)
        {
            int num;
            cin>>num;
            vis.insert(num);
            for(i=2;i*i<=num;i++)
            {
                if(num%i==0)
                {
                    ll cnt=0;
                    while(num%i==0)
                    {
                        num/=i;
                        cnt++;
                    }
                    if(ma.count(i)==0)
                        ma.insert(make_pair(i,cnt));
                    else
                        ma[i]=max(ma[i],cnt);
                }
            }
            if(num>1)
            {
                if(ma.count(num)==0)
                    ma.insert(make_pair(num,1));
                else
                    ma[num]=max(ma[num],1ll);
            }
        }
        ll ans=1;
        ll have=1;
        for(auto k:ma)
        {
            have*=(k.second+1);
            if(have>n+2)
                break;
            ans*=ksm(k.first,k.second);
        }
        if(have==n+2)
        {
            if(vis.count(ans)==0)
                cout<<ans<<endl;
            else
                cout<<-1<<endl;
        }else if (have>n+2)
            cout<<-1<<endl;
        else
        {
            if(ma.size()==1)
                cout<<ans*(ma.begin()->first)<<endl;
            else
                cout<<-1<<endl;
        }
    }
    return 0;
}
