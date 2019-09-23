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
const int maxn=505;
char ma[maxn][maxn];
int n,m;
int dfs(int x,int y,int op)
{
    int cnt=1;
    int dx[4]={0,1,-1,0};
    int dy[4]={1,0,0,-1};
    int i=op;
    int x1=x+dx[i];
    int y1=y+dy[i];
    if(x1>=0&&x1<n&&y1>=0&&y1<m&&ma[x1][y1]=='*')
    {
        cnt+=dfs(x1,y1,op);
    }
    return cnt;
}
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
    cin>>n>>m;
    int i;
    int cnt=0;
    wfor(i,0,n)
    {
        int j;
        wfor(j,0,m)
        {
            cin>>ma[i][j];
            if(ma[i][j]=='*')
                cnt++;
        }
    }
    wfor(i,0,n)
    {
        int j;
        wfor(j,0,m)
        {
            if(ma[i][j]=='*')
            {
                if(i+1<n&&i-1>=0&&j+1<m&&j-1>=0&&ma[i][j+1]=='*'&&ma[i][j-1]=='*'&&ma[i+1][j]=='*'&&ma[i-1][j]=='*')
                {
                    int num=0;
                    num+=dfs(i,j,0);
                    num+=dfs(i,j,1);
                    num+=dfs(i,j,2);
                    num+=dfs(i,j,3);
                    num-=3;
                    if(num==cnt)
                        cout<<"YES"<<endl;
                    else
                        cout<<"NO"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
