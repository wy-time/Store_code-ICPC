#include <iostream>
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
    ll n,p,k;
    cin>>n>>p>>k;
    int i;
    map<ll,ll >ma;
    wfor(i,0,n)
    {
        ll t;
        cin>>t;
        ll temp=((t*t%p*t%p*t%p)-(t*k%p)+p)%p;
        if(ma.count(temp)==0)
            ma.insert(make_pair(temp,1));
        else
            ma[temp]++;
    }
    ll ans=0;
    for(auto j:ma)
    {
        ans+=j.second*(j.second-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}
