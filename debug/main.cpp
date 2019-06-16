#include <iostream>
#include <algorithm> 
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
    int n,h,m;
    cin>>n>>h>>m;
    int num[51]={0};
    fill(num,num+n,h);
    int i;
    wfor(i,0,m)
    {
        int l,r,ma;
        cin>>l>>r>>ma;
        int j;
        wfor(j,l-1,r)
        {
            num[j]=min(num[j],ma);
        }
    }
    ll ans=0;
    wfor(i,0,n)
    {
        ans+=num[i]*num[i];
    }
    cout<<ans<<endl;
    return 0;
}
