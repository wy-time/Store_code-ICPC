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
const int maxn=250005;
struct st
{
    int len;
    int link;
    int _next[26];
};
int sz,last;
st sam[maxn*2];
void init()
{
    sam[sz].len=0;
    sam[sz].link=-1;
    memset(sam[sz]._next,0,sizeof(sam[sz]._next));
    sz++;
    last=0;
}
void add(char c)
{
    int cur=sz++;
    sam[cur].len=sam[last].len+1;
    int p=last;
    for(;p!=-1&&!sam[p]._next[c-'a'];p=sam[p].link)
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
            int cop=sz++;
            sam[cop]=sam[q];
            sam[cop].len=sam[p].len+1;
            for(;p!=-1&&sam[p]._next[c-'a']==q;p=sam[p].link)
                sam[p]._next[c-'a']=cop;
            sam[q].link=cop;
            sam[cur].link=cop;
        }
    }
    last=cur;
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
    string s,t;
    cin>>s>>t;
    init();
    int len=s.size();
    int i;
    wfor(i,0,len)
    {
        add(s[i]);
    }
    int v=0,l=0;
    int ans=0;
    wfor(i,0,t.length())
    {
        while(v&&!sam[v]._next[t[i]-'a'])
        {
            v=sam[v].link;
            l=sam[v].len;
        }
        if(sam[v]._next[t[i]-'a']!=0)
        {
            v=sam[v]._next[t[i]-'a'];
            l++;
        }
        ans=max(ans,l);
    }
    cout<<ans<<endl;
    return 0;
}
