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
    ll n,p,w,d;
    cin>>n>>p>>w>>d;
    ll x=0,y=0;
    while(y<w&&(p-y*d)%w!=0)y++;
    if(y<w)
    {
        x=(p-y*d)/w;
        ll z=n-x-y;
        if(x>=0&&y>=0&&z>=0)
            cout<<x<<" "<<y<<" "<<z<<endl;
        else
            cout<<-1<<endl;
    }else
    {
        cout<<-1<<endl;
    }
    return 0;
}
