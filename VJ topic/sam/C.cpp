#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
void read(int &x) {
    char ch = getchar(); x = 0;
    for (; ch < '0' || ch > '9'; ch = getchar());
    for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
const int maxn = 250005;
struct st
{
    int len;
    int link;
    int _next[26];
    int cnt;
};
st sam[maxn * 2];
int tot, last;
void init()
{
    sam[tot].len = 0;
    sam[tot].link = -1;
    memset(sam[tot]._next, 0, sizeof(sam[tot]._next));
    sam[tot].cnt = 1;
    tot = 1;
    last = 0;
};
void add(char c)
{
    int cur = tot++;
    sam[cur].len = sam[last].len + 1;
    sam[cur].cnt = 1;
    int p;
    for (p = last; p != -1 && !sam[p]._next[c - 'a']; p = sam[p].link)
        sam[p]._next[c - 'a'] = cur;
    if (p == -1)
        sam[cur].link = 0;
    else
    {
        int q = sam[p]._next[c - 'a'];
        if (sam[p].len + 1 == sam[q].len)
            sam[cur].link = q;
        else
        {
            int clone = tot++;
            sam[clone] = sam[q];
            sam[clone].len = sam[p].len + 1;
            sam[clone].cnt = 0;
            for (; p != -1 && sam[p]._next[c - 'a'] == q; p = sam[p].link)
                sam[p]._next[c - 'a'] = clone;
            sam[q].link = clone;
            sam[cur].link = clone;
        }
    }
    last = cur;
}
int toop[2 * maxn];
int sum[maxn];
int ans[maxn];
int main()
{
    //std::ios::sync_with_stdio(false);
#ifdef test
    freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
#ifdef ubuntu
    freopen("/home/time/debug/debug/in", "r", stdin);
    freopen("/home/time/debug/debug/out", "w", stdout);
#endif
    init();
    char s[maxn];
    scanf("%s", s);
    int len = strlen(s);
    int i;
    wfor(i, 0, len)
    add(s[i]);
    wfor(i, 0, tot)sum[sam[i].len]++;
    wfor(i, 1, len + 1)sum[i] += sum[i - 1];
    wfor(i, 0, tot)toop[--sum[sam[i].len]] = i;
    mfor(i, tot - 1, 0)
    {
        int v = toop[i];
        int fa = sam[v].link;
        if (fa != -1)
            sam[fa].cnt += sam[v].cnt;
    }
    wfor(i, 0, tot)
    {
        ans[sam[i].len] = max(ans[sam[i].len], sam[i].cnt);
    }
    wfor(i, 0, len)
    printf("%d\n", ans[i + 1]);
    //cout<<ans[i+1]<<endl;
    return 0;
}
