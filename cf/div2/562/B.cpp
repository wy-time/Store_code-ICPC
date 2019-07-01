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
const int maxn=3e5+5;
pair<int,int> num[maxn];
int m;
int dfs(int now1,int now2,int step)
{
    if(step==m)
    {
        return 1;
    }
    if(num[step].first==now1||num[step].second==now1||num[step].first==now2||num[step].second==now2)
    {
        if(dfs(now1,now2,step+1))
            return 1;
        else
            return 0;
    }else
    {
        if(now1==-1)
        {
            now1=num[step].first;
            if(dfs(now1,now2,step+1))
                return 1;
            else
            {
                now1=num[step].second;
                if(dfs(now1,now2,step+1))
                    return 1;
                else
                    return 0;
            }
        }else if(now2==-1)
        {
            now2=num[step].first;
            if(dfs(now1,now2,step+1))
                return 1;
            else
            {
                now2=num[step].second;
                if(dfs(now1,now2,step+1))
                    return 1;
                else
                    return 0;
            }
        }
    }
    return 0;
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
    int n;
    cin>>n>>m;
    int i;
    wfor(i,0,m)
    {
        cin>>num[i].first>>num[i].second;
    }
    int flag=dfs(-1,-1,0);
    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
