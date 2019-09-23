#include <iostream>
#include <queue> 
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
struct st
{
    ll a;
    ll b;
};
const ll maxn=7005;
st stud[maxn];
map<ll,ll>ma;
map<ll,ll>ma2;
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
    wfor(i,0,n)
    {
        cin>>stud[i].a;
        ma[stud[i].a]++;
    }
    wfor(i,0,n)
    {
        cin>>stud[i].b;
        ma2[stud[i].a]+=stud[i].b;
    }
    queue<ll>qu;
    for(auto k:ma)
    {
        if(k.second>=2)
            qu.push(k.first);
    }
    ll sum=0;
    while(!qu.empty())
    {
        ll temp=qu.front();
        qu.pop();
        sum+=ma2[temp];
        ma2.erase(temp);
        for (ll i = temp; i; i = (i - 1) &temp)
        {
            if(ma2.count(i)!=0)
            {
                sum+=ma2[i];
                ma2.erase(i);
                qu.push(i);
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
