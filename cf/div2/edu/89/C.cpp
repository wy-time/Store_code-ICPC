#include <iostream>
#include <queue> 
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
    freopen("./in","r",stdin);
    freopen("./out","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        int ma[31][31];
        int n,m;
        cin>>n>>m;
        int i,j;
        wfor(i,0,n)
        {
            wfor(j,0,m)
            {
                cin>>ma[i][j];
            }
        }
        int ans=0;
        if(m>=n)
        {
            wfor(i,0,m)
            {
                int x=0;int y=i;
                int x1=n-1;int y1=m-1-i;
                int num[2]={0};
                num[ma[x][y]]++;
                num[ma[x1][y1]]++;
                while(x+1<n&&y-1>=0)
                {
                    x++,y--;
                    num[ma[x][y]]++;
                }
                while(x1-1>=0&&y1+1<m)
                {
                    x1--,y1++;
                    num[ma[x1][y1]]++;
                }
                if(y1<=i)
                    break;
                ans+=min(num[0],num[1]);
            }
        }else
        {
            wfor(i,0,n)
            {
                int x=i;int y=0;
                int x1=n-1-i;int y1=m-1;
                int num[2]={0};
                num[ma[x][y]]++;
                num[ma[x1][y1]]++;
                while(y+1<m&&x-1>=0)
                {
                    x--,y++;
                    num[ma[x][y]]++;
                }
                while(y1-1>=0&&x1+1<n)
                {
                    y1--,x1++;
                    num[ma[x1][y1]]++;
                }
                if(x1<=i)
                    break;
                ans+=min(num[0],num[1]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
