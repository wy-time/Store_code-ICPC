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
int ma[55][55];
int ma2[55][55];
vector <pair<int,int>>ans;
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
    wfor(i,0,n-1)
    {
        wfor(j,0,m-1)
        {
            if(ma[i][j]!=0&&ma[i+1][j]!=0&&ma[i][j+1]!=0&&ma[i+1][j+1]!=0)
            {
                ans.push_back(make_pair(i+1,j+1));
                ma2[i][j]=ma2[i+1][j]=ma2[i+1][j+1]=ma2[i][j+1]=1;
            }
        }
    }
    int flag=1;
    wfor(i,0,n)
    {
        wfor(j,0,m)
        {
            if(ma[i][j]!=ma2[i][j])
            {
                flag=0;
            }
        }
    }
    if(flag)
    {
        cout<<ans.size()<<endl;;
        for(auto k:ans)
            cout<<k.first<<" "<<k.second<<endl;
    }else
        cout<<-1<<endl;
    return 0;
}
