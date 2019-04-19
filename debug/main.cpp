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
    int x,y,z;
    while(cin>>x>>y>>z)
    {
        ll ans=0;
        int G1[100][100]={{0}};
        int G2[100][100]={{0}};
        int G3[100][100]={{0}};
        int i,j;
        wfor(i,0,x)
        {
            wfor(j,0,y)
            {
                cin>>G1[i][j];
                ans+=G1[i][j];
            }
        }
        wfor(i,0,y)
        {
            wfor(j,0,z)
            {
                cin>>G2[i][j];
                ans+=G2[i][j];
            }
        }
        wfor(i,0,z)
        {
            wfor(j,0,x)
            {
                cin>>G3[i][j];
                ans+=G3[i][j];
            }
        }
        wfor(i,0,x)
        {
            ans-=G1[i][y-1]&G3[z-1][i];
        }
        wfor(i,0,y)
        {
            ans-=G1[0][i]&G2[i][z-1];
        }
        wfor(i,0,z)
        {
            ans-=G2[y-1][i]&G3[i][0];
        }
        cout<<ans<<endl;
    }
    return 0;
}
