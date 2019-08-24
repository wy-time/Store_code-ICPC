#include <iostream>
#include <bitset> 
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
    int i;
    cout<<"? ";
    wfor(i,1,100)
    {
        cout<<(i<<7)<<" ";
    }
    cout<<(i<<7)<<endl;
    int fir;
    cin>>fir;
    cout<<"? ";
    wfor(i,0,99)
        cout<<i<<" ";
    cout<<i<<endl;
    int sec;
    cin>>sec;
    bitset<14>firnum(fir);
    bitset<14>senum(sec);
    mfor(i,13,7)
    {
        firnum[i]=senum[i];
    }
    ll ans=firnum.to_ullong();
    cout<<"! "<<ans<<endl;
    return 0;
}
