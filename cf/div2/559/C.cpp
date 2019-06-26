#include <iostream>
#include <algorithm> 
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
ll boy[maxn];
ll girl[maxn];
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
    int i;
    wfor(i,0,n)
    {
        cin>>boy[i];
    }
    wfor(i,0,m)
    {
        cin>>girl[i];
    }
    sort(boy,boy+n,greater<int>());
    sort(girl,girl+m,greater<int>());
    int flag=1;
    ll ans=0;
    int now=0;
    wfor(i,0,n)
    {
        int j;
        ans+=now*boy[i];
        int isok=0;
        if(now!=0)
            isok=1;
        wfor(j,now,m)
        {
            if(girl[j]<boy[i])
            {
                flag=0;
                break;
            }else if(j!=m-1)
            {
                ans+=girl[j];
            }else
            {
                if(girl[j]==boy[i]||isok)
                {
                    ans+=girl[j];
                    now=m;
                }
                else
                {
                    ans+=boy[i];
                    now=m-1;
                }
            }
        }
        if(!flag)
            break;
    }
    if(!flag)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
    return 0;
}
