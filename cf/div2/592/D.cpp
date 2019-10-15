#include <iostream>
#include <cstring> 
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
const int maxn=1e5+5;
ll cost[maxn][3];
vector<int>G[maxn];
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
    cin>>n;
    int i;
    wfor(i,0,3)
    {
        int j;
        wfor(j,1,n+1)
            cin>>cost[j][i];
    }
    wfor(i,0,n-1)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int head=0;
    int flag=1;
    wfor(i,1,n+1)
    {
        if(G[i].size()==1&&head==0)
        {
            head=i;
        }else if(G[i].size()>2)
        {
            flag=0;
            break;
        }
    }
    if(head==0||flag==0)
    {
        cout<<-1<<endl;
    }else
    {
        int last=0;
        int _next=G[head][0];
        ll ans=1e18;
        int out[maxn];
        int temp[maxn]={0};
        wfor(i,0,3)
        {
            int j;
            wfor(j,0,3)
            {
                ll res=0;
                if(i==j)continue;
                res+=cost[head][i];
                res+=cost[_next][j];
                last=head;
                int now=_next;
                temp[head]=i;
                temp[_next]=j;
                for(int k=2;k<n;k++)
                {
                    for(auto k:G[now])
                    {
                        if(k==last)continue;
                        int t3=3-temp[now]-temp[last];
                        temp[k]=t3;
                        res+=cost[k][t3];
                        last=now;
                        now=k;
                        break;
                    }
                }
                if(res<ans)
                {
                    memcpy(out,temp,sizeof(temp));
                    ans=res;
                }
            }
        }
        cout<<ans<<endl;
        wfor(i,1,n+1)
            cout<<out[i]+1<<" ";
    }
    return 0;
}
