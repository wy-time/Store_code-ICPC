#include <iostream>
#include <bitset> 
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
struct EDGE
{
    int w;
    int end;
    int _next;
};
struct node
{
    int _next[2];
    void init()
    {
        _next[0]=_next[1]=0;
    }
};
node tree[55];
EDGE edge[maxn];
int head[maxn];
int cnt;
void add(int beg,int end,int w)
{
    edge[++cnt]._next=head[beg];
    edge[cnt].end=end;
    edge[cnt].w=w;
    head[beg]=cnt;
}
int num[maxn];
void dfs(int now,int res)
{
    int i;
    for(i=head[now];i;i=edge[i]._next)
    {
        int v=edge[i].end;
        res^=edge[i].w;
        num[v]=res;
        dfs(v,res);
        res^=edge[i].w;
    }
}
int tot=0;
void char_insert(string c)
{
    int i;
    wfor(i,0,c.length())
    {
        int now=0;
        if(tree[now]._next[c[i]-'0']==0)
        {
            tree[++tot].init();
            tree[now]._next[c[i]-'0']=tot;
        }
        now=tot;
    }
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
    cin>>n;
    int i;
    wfor(i,0,n)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
    }
    num[1]=0;
    dfs(1,0);
    wfor(i,1,n+1)
    {
        bitset<32>bit (num[i]);
        string s=bit.to_string();
        char_insert(s);
    }
    unsigned long long ans=0;
    wfor(i,1,n+1)
    {
        bitset<32>bit (num[i]);
        string s=bit.to_string();   
        int j;
        wfor(j,31,0)
        {
            int now=0;
            if(tree[now]._next[(s[j]-'0')^1]!=0)
            {
                bit[j]=1;
                now=tree[now]._next[(s[j]-'0')^1];
            }else
            {
                now=tree[now]._next[(s[j]-'0')];
                bit[j]=0;
            }
        }
        ans=max(ans,bit.to_ullong());
    }
    cout<<ans<<endl;
    return 0;
}
