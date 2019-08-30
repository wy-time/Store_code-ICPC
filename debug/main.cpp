#include <iostream>
#include <cstring> 
#include <string> 
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
const int maxn=100005;
struct st
{
    int len;
    int link;
    int _next[26];
    int mx;
    int ans;
};
st sam[maxn*2];
int tot,last;
void init()
{
    sam[tot].len=0;
    sam[tot].link=-1;
    sam[tot].mx=0;
    sam[tot].ans=-1;
    memset(sam[tot]._next,0,sizeof(sam[tot]._next));
    tot++;
    last=0;
}
void add(char c)
{
    int cur=tot++;
    sam[cur].len=sam[last].len+1;
    sam[cur].ans=sam[cur].len;
    sam[cur].mx=0;
    int p;
    for(p=last;p!=-1&&!sam[p]._next[c-'a'];p=sam[p].link)
        sam[p]._next[c-'a']=cur;
    if(p==-1)
        sam[cur].link=0;
    else
    {
        int q=sam[p]._next[c-'a'];
        if(sam[p].len+1==sam[q].len)
            sam[cur].link=q;
        else
        {
            int clone=tot++;
            sam[clone]=sam[q];
            sam[clone].len=sam[p].len+1;
            for(;p!=-1&&sam[p]._next[c-'a']==q;p=sam[p].link)
                sam[p]._next[c-'a']=clone;
            sam[q].link=clone;
            sam[cur].link=clone;
        }
    }
    last=cur;
}
int toop[2*maxn];
int sum[maxn];
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
    init();
    string s;
    cin>>s;
    int i;
    wfor(i,0,s.length())
        add(s[i]);
    wfor(i,0,tot) sum[sam[i].len]++;
    wfor(i,1,s.length()+1) sum[i]+=sum[i-1];
    wfor(i,0,tot) toop[--sum[sam[i].len]]=i;
    while(cin>>s)
    {
        int p=0,l=0;
        wfor(i,0,s.length())
        {
            while(p&&!sam[p]._next[s[i]-'a'])
            {
                p=sam[p].link;
                l=sam[p].len;
            }
            if(sam[p]._next[s[i]-'a']!=0)
            {
                p=sam[p]._next[s[i]-'a'];
                l++;
                sam[p].mx=max(sam[p].mx,l);
            }
        }
        mfor(i,tot-1,0)
        {
            int v=toop[i];
            if(sam[v].link!=-1)
                sam[sam[v].link].mx=max(sam[sam[v].link].mx,min(sam[v].mx,sam[sam[v].link].len));
            sam[v].ans=min(sam[v].ans,sam[v].mx);
            sam[v].mx=0;
        }
    }
    int res=0;
    wfor(i,0,tot)
    {
        res=max(res,sam[i].ans);
    }
    cout<<res<<endl;
    return 0;
}
