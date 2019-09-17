#include <iostream>
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
    ll x,y,p;
    cin>>x>>y>>p;
    ll ans1=(x+y)/p;
    ll temp1=x%p;
    ll temp2=y%p;
    ll temp=p-max(temp1,temp2);
    ll ans2=0;
    if(min(temp1,temp2)>=temp)
    {
        ans2=temp;
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}
