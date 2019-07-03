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
int num[maxn];
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
    int now=1;
    wfor(i,2,n+1)
    {
        if(num[i]==0)
        {
            num[i]=now;
            int j;
            for(j=2;j*i<=n;j++)
            {
                if(num[i*j]==0)
                    num[i*j]=now;
            }
            now++;
        }
    }
    wfor(i,2,n+1)
        cout<<num[i]<<" ";
    return 0;
}
