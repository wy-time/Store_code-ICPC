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
const int maxn=1e5+5;
int numa[maxn];
int numb[maxn];
ll ans[maxn][3];
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
    int i;
    wfor(i,0,n)
    {
        cin>>numa[i];
    }
    wfor(i,0,n)
    {
        cin>>numb[i];
    }
    ans[0][0]=0;
    ans[0][1]=numa[0];
    ans[0][2]=numb[0];
    wfor(i,1,n)
    {
        ans[i][0]=max(ans[i-1][0],max(ans[i-1][1],ans[i-1][2]));
        ans[i][1]=1ll*numa[i]+max(ans[i-1][0],ans[i-1][2]);
        ans[i][2]=1ll*numb[i]+max(ans[i-1][0],ans[i-1][1]);
    }
    cout<<max(ans[n-1][0],max(ans[i-1][1],ans[i-1][2]))<<endl;
    return 0;
}
