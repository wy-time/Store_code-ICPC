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
int ma[16][16];
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
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int i,j;
        wfor(i,0,n)
        {
            wfor(j,0,m)
            {
                ma[i][j]=1;
            }
        }
        int cnt=0;
        wfor(i,0,n)
        {
            wfor(j,0,m)
            {
                if(i==0&&j%2!=0&&cnt<k)
                {
                    if(j!=0&&j!=m-1)
                        ma[i][j]=3;
                    else
                        ma[i][j]=2;
                    cnt++;
                }else if(i!=0&&i!=n-1&&cnt<k)
                {
                    if(ma[i-1][j]==1)
                    {
                        cnt++;
                        if(j!=0&&j!=m-1)
                            ma[i][j]=4;
                        else
                            ma[i][j]=3;
                    }
                }else if(i==n-1&&cnt<k)
                {
                    if(ma[i-1][j]==1)
                    {
                        cnt++;
                        if(j!=0&&j!=m-1)
                            ma[i][j]=3;
                        else
                            ma[i][j]=2;
                    }
                }
                if(cnt>=k)
                    break;
            }
        }
        wfor(i,0,n)
        {
            wfor(j,0,m-1)
            {
                cout<<ma[i][j]<<" ";
            }
            cout<<ma[i][j]<<endl;
        }
    }
    return 0;
}
