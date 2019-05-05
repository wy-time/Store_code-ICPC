#include <iostream>
#include <queue> 
#include <string> 
#include <cstring> 
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
struct st
{
    char s;
    int next[26];
    int fail;
    int is_last;
    void init()
    {
        memset(next,-1,sizeof(next));
        fail=-1;
        is_last=0;
    }
};
const int maxn=500005;
st trie[maxn];
int cnt=0;
void build(string s)
{
    int len=s.size();
    int now=0;
    int i;
    wfor(i,0,len)
    {
        int id=s[i]-'a';
        if(trie[now].next[id]==-1)
        {
            trie[++cnt].init();
            trie[cnt].s=s[i];
            trie[now].next[id]=cnt;
        }
        now=trie[now].next[id];
    }
    trie[now].is_last++;
}
void cla_fail()
{
    int i;
    queue<int>qu;
    wfor(i,0,26)
    {
        if(trie[0].next[i]!=-1)
        {
            int p=trie[0].next[i];
            trie[p].fail=0;
            qu.push(p);
        }
    }
    while(!qu.empty())
    {
        int father=qu.front();
        qu.pop();
        wfor(i,0,26)
        {
            if(trie[father].next[i]!=-1)
            {
                int child=trie[father].next[i];
                int p=trie[father].fail;
                while(p!=-1&&trie[p].next[i]==-1)
                    p=trie[p].fail;
                if(p==-1)
                    trie[child].fail=0;
                else
                    trie[child].fail=trie[p].next[i];
                qu.push(child);
            }
        }
    }
}
int query(string s)
{
    int len=s.size();
    int i;
    int now=0;
    int ans=0;
    wfor(i,0,len)
    {
        int id=s[i]-'a';
        while(now!=0&&trie[now].next[id]==-1)
            now=trie[now].fail;
        int temp;
        now=trie[now].next[id];
        if(now!=-1)
            temp=now;
        else
            temp=now=0;
        while(temp!=0&&trie[temp].is_last!=-1)
        {
            ans+=trie[temp].is_last;
            trie[temp].is_last=-1;
            temp=trie[temp].fail;
        }
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
    int t;
    cin>>t;
    while(t--)
    {
        trie[0].init();
        int n;
        cin>>n;
        int i;
        string s;
        wfor(i,0,n)
        {
            cin>>s;
            build(s);
        }
        cla_fail();
        cin>>s;
        int ans=query(s);
        cout<<ans<<endl;
    }
    return 0;
}
