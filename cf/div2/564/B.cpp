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
    int n;
    cin>>n;
    int ans=(n+1)%2==0?(n+1)/2:(n+1)/2+1;
    cout<<ans<<endl;
    int i;
    wfor(i,0,ans)
    {
        cout<<1<<" "<<i+1<<endl;
    }
    int j=2;
    for(;i<n;i++)
    {
        cout<<j<<" "<<ans<<endl;
        j++;
    }
    return 0;
}
