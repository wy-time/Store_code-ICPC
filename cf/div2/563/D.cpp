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
const int maxn=1<<18;
int vis[maxn+5];
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
    int n,k;
    cin>>n>>k;
    int i;
    vis[k]=1;
    int len=0;
    wfor(i,1,1<<n)
    {
        if(vis[i])
            continue;
        vis[i^k]=1;
        len++;
    }
    cout<<len<<endl;
    int temp=0;
    wfor(i,1,1<<n)
    {
        if(vis[i]==0)
        {
            cout<<(temp^i)<<" ";
            temp=i;
        }
    }
    return 0;
}
