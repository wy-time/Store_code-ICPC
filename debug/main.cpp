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
int ma[105][105];
int numf[105];
int numl[105];
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
    int n,m,h;
    cin>>n>>m>>h;
    int i,j;
    wfor(i,0,m)
    {
        cin>>numf[i];
    }
    wfor(i,0,n)
    {
        cin>>numl[i];
    }
    wfor(i,0,n)
    {
        wfor(j,0,m)
        {
            cin>>ma[i][j];
        }
    }
    wfor(i,0,n)
    {
        wfor(j,0,m)
        {
            if(ma[i][j]==1)
                ma[i][j]=min(numl[i],numf[j]);
        }
    }
    wfor(i,0,n)
    {
        wfor(j,0,m)
        {
            cout<<ma[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
