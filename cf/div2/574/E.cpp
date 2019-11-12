#include <iostream>
#include <deque> 
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
const int maxn=3005;
int ma[maxn][maxn];
int ma2[maxn][maxn];
struct st
{
    int num;
    int x,y;
    st(){};
    st(int a,int b,int c)
    {
        num=a,x=b,y=c;
    }
};
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
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    ll g,x,y,z;
    cin>>g>>x>>y>>z;
    int i,j;
    wfor(i,0,n)
    {
        wfor(j,0,m)
        {
            ma[i][j]=g;
            g=(g%z*x%z+y%z)%z;
        }
    }
    ll ans=0;
    wfor(i,0,n)
    {
        deque<st>sta;
        wfor(j,0,b)
        {
            if(sta.empty())
                sta.push_back(st(ma[i][j],i,j));
            else
            {
                if(ma[i][j]>sta.back().num)
                    sta.push_back(st(ma[i][j],i,j));
                else
                {
                    while(!sta.empty()&&ma[i][j]<=sta.back().num)
                        sta.pop_back();
                    sta.push_back(st(ma[i][j],i,j));
                }
            }
        }
        wfor(j,b,m)
        {
            ma2[i][j-b]=sta.front().num;
            if(!sta.empty()&&sta.front().y<=j-b)
                sta.pop_front();
            if(sta.empty())
                sta.push_back(st(ma[i][j],i,j));
            else
            {
                if(ma[i][j]>sta.back().num)
                    sta.push_back(st(ma[i][j],i,j));
                else
                {
                    while(!sta.empty()&&ma[i][j]<=sta.back().num)
                        sta.pop_back();
                    sta.push_back(st(ma[i][j],i,j));
                }
            }
        }
        ma2[i][j-b]=sta.front().num;
    }
    wfor(j,0,m-b+1)
    {
        deque<st>sta;
        wfor(i,0,a)
        {
            if(sta.empty())
                sta.push_back(st(ma2[i][j],i,j));
            else
            {
                if(sta.back().num<ma2[i][j])
                    sta.push_back(st(ma2[i][j],i,j));
                else
                {
                    while(!sta.empty()&&sta.back().num>=ma2[i][j])
                        sta.pop_back();
                    sta.push_back(st(ma2[i][j],i,j));
                }
            }
        }
        wfor(i,a,n)
        {
            ans+=sta.front().num;
            if(!sta.empty()&&sta.front().x<=i-a)
                sta.pop_front();
            if(sta.empty())
                sta.push_back(st(ma2[i][j],i,j));
            else
            {
                if(sta.back().num<ma2[i][j])
                    sta.push_back(st(ma2[i][j],i,j));
                else
                {
                    while(!sta.empty()&&sta.back().num>=ma2[i][j])
                        sta.pop_back();
                    sta.push_back(st(ma2[i][j],i,j));
                }
            }
        }
        ans+=sta.front().num;
    }
    cout<<ans<<endl;
    return 0;
}
