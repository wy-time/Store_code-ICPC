#include <iostream>
#include <vector> 
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
const int maxn=5e4+5;
vector<char>ma[maxn];
int black_row[maxn];
vector<int>black_row_pos[maxn];
int black_cow[maxn];
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
        int n,m;
        cin>>n>>m;
        int i,j;
        wfor(i,0,n)
        {
            int cnt=0;
            black_row[i]=0;
            black_row_pos[i].clear();
            ma[i].clear();
            wfor(j,0,m)
            {
                char temp;
                cin>>temp;
                ma[i].push_back(temp);
                if(ma[i][j]=='*')
                    cnt++;
                else
                    black_row_pos[i].push_back(j);
            }
            black_row[i]=m-cnt;
        }
        wfor(j,0,m)
        {
            black_cow[j]=0;
            int cnt=0;
            wfor(i,0,n)
            {
                if(ma[i][j]=='*')
                    cnt++;
            }
            black_cow[j]=n-cnt;
        }
        int ans=1e9;
        wfor(i,0,n)
        {
            int len=black_row[i];
            int now=0;
            wfor(j,0,m)
            {
                int temp=black_cow[j]+black_row[i];
                if(now<len&&j==black_row_pos[i][now])
                {
                    temp--;
                    now++;
                }
                ans=min(ans,temp);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
