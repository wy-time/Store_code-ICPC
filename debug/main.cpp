#include <iostream>
#include <cmath> 
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
int bit[33];
void init()
{
    int i;
    wfor(i,0,32)
    {
        bit[i]=1<<i;
    }
}
const int maxn=5e3+5;
int num[maxn];
int maxnum[maxn][30];
int minnum[maxn][30];
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
    int n,q;
    cin>>n>>q;
    int i;
    init();
    wfor(i,1,n+1)
    {
        cin>>num[i];
    }
    int j;
    int en=log2(n);
    wfor(i,1,n+1)
    {
        maxnum[i][0]=num[i];
        minnum[i][0]=num[i];
    }
    wfor(j,1,en+2)
    {
        wfor(i,1,n+1)
        {
            if(i+bit[j-1]<=n)
            {
                maxnum[i][j]=max(maxnum[i][j-1],maxnum[i+bit[j-1]][j-1]);
                minnum[i][j]=min(minnum[i][j-1],minnum[i+bit[j-1]][j-1]);
            }
        }
    }
    wfor(i,0,q)
    {
        int l,r;
        cin>>l>>r;
        int len=r-l+1;
        int t=log2(len);
        int x=max(maxnum[l][t],maxnum[r-bit[t]+1][t]);
        int y=min(minnum[l][t],minnum[r-bit[t]+1][t]);
        cout<<x-y<<endl;
    }
    return 0;
}
