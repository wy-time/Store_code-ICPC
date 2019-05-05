#include <iostream>
#include <queue> 
#include <cstring> 
#include <string> 
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const ll maxn=2e6+5;
const ll mod=100000;
ll ma[200];
struct st
{
    ll next[4];
    ll fail;
    ll is_string;
    void init()
    {
        memset(next,-1,sizeof(next));
        fail=-1;
        is_string=0;
    }
};
st trie[maxn];
void init()
{
    ma['A']=0;
    ma['C']=1;
    ma['G']=2;
    ma['T']=3;
}
ll cnt=0;
void build(string s)
{
    ll len=s.size();
    ll i;
    ll now=0;
    wfor(i,0,len)
    {
        ll id=ma[s[i]];
        if(trie[now].next[id]==-1)
        {
            trie[++cnt].init();
            trie[now].next[id]=cnt;
        }
        now=trie[now].next[id];
    }
    trie[now].is_string=1;
}
void cal_fail()
{
    ll i;
    ll now=0;
    queue<ll>qu;
    wfor(i,0,4)
    {
        if(trie[now].next[i]!=-1)
        {
            trie[trie[now].next[i]].fail=0;
            qu.push(trie[now].next[i]);
        }
    }
    while(!qu.empty())
    {
        ll father=qu.front();
        qu.pop();
        wfor(i,0,4)
        {
            ll child=trie[father].next[i];
            if(child!=-1)
            {
                now=trie[father].fail;
                while(now!=-1&&trie[now].next[i]==-1)
                {
                    now=trie[now].fail;
                }
                if(now==-1)
                    trie[child].fail=0;
                else
                {
                    trie[child].fail=trie[now].next[i];
                    if(trie[trie[now].next[i]].is_string!=0)
                        trie[child].is_string=1;
                }
                qu.push(child);
            }
        }
    }
}
struct Matix
{
    ll m[105][105];
};
Matix mul(Matix a,Matix b)
{
    Matix c;
    memset(c.m,0,sizeof(c.m));
    ll i,j,k;
    wfor(i,0,cnt)
    {
        wfor(j,0,cnt)
        {
            wfor(k,0,cnt)
            {
                c.m[i][j]+=a.m[i][k]*b.m[k][j]%mod;
                c.m[i][j]%=mod;
            }
        }
    }
    return c;
}
Matix ksm(Matix a,ll b)
{
    Matix ans;
    memset(ans.m,0,sizeof(ans.m));
    ll i;
    wfor(i,0,cnt)
    {
        ans.m[i][i]=1;
    }
    while(b)
    {
        if(b&1)
        {
            ans=mul(ans,a);
        }
        b>>=1;
        a=mul(a,a);
    }
    return ans;
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
    ll n,m;
    cin>>n>>m;
    init();
    ll i;
    trie[0].init();
    wfor(i,0,n)
    {
        string s;
        cin>>s;
        build(s);
    }
    cal_fail();
    cnt++;
    Matix x;
    memset(x.m,0,sizeof(x.m));
    wfor(i,0,cnt)
    {
        ll j;
        if(trie[i].is_string==0)
        {
            wfor(j,0,4)
            {
                ll now=i;
                if(trie[now].next[j]==-1)
                {
                    while(now!=-1&&trie[now].next[j]==-1)
                        now=trie[now].fail;
                    if(now!=-1)
                    {
                        if(trie[now].next[j]!=-1&&trie[trie[now].next[j]].is_string==0)
                        {
                            x.m[i][trie[now].next[j]]++;
                        }
                    }else
                        x.m[i][0]++;
                }else
                {
                    if(trie[trie[now].next[j]].is_string==0)
                        x.m[i][trie[now].next[j]]++;
                }
            }
        }
    }
    wfor(i,0,cnt)
    {
        ll j;
        wfor(j,0,cnt)
        {
            cout<<x.m[i][j];
        }
        cout<<endl;
    }
    x=ksm(x,m);
    ll ans=0;
    wfor(i,0,cnt)
    {
        ans+=x.m[0][i];
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}
