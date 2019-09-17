#include <iostream>
#include <map>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn = 100005;
int tot, last;
struct st
{
    int len;
    int link;
    int num;
    map<char, int>_next;
    void init()
    {
        len = 0;
        link = -1;
        _next.clear();
        tot = 1;
        last = 0;
        num = 0;
    }
};
st sam[2 * maxn];
void add(char c)
{
    int cur = tot++;
    sam[cur].len = sam[last].len + 1;
    sam[cur].num = 0;
    int p = last;
    for (; p != -1 && !sam[p]._next.count(c); p = sam[p].link)
        sam[p]._next[c] = cur;
    if (p == -1)
        sam[cur].link = 0;
    else
    {
        int q = sam[p]._next[c];
        if (sam[p].len + 1 == sam[q].len)
            sam[cur].link = q;
        else
        {
            int clone = tot++;
            sam[clone] = sam[q];
            sam[clone].len = sam[p].len + 1;
            for (; p != -1 && sam[p]._next[c] == q; p = sam[p].link)
                sam[p]._next[c] = clone;
            sam[q].link = sam[cur].link = clone;
        }
    }
    last = cur;
}
int sum[maxn];
int toop[maxn * 2];
string ans = "";
void slove(int now, int aim)
{
    if (aim <= 0)
        return;
    for (auto k : sam[now]._next)
    {
        if (aim <= 0)
            return;
        if (sam[k.second].num < aim)
        {
            aim -= sam[k.second].num;
            continue;
        } else
        {
            ans += k.first;
            aim--;
            slove(k.second, aim);
            break;
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
#ifdef test
    freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
#ifdef ubuntu
    freopen("/home/time/debug/debug/in", "r", stdin);
    freopen("/home/time/debug/debug/out", "w", stdout);
#endif
    string s;
    cin >> s;
    sam[0].init();
    int i;
    wfor(i, 0, s.length())
    add(s[i]);
    wfor(i, 0, tot)sum[sam[i].len]++;
    wfor(i, 1, s.length() + 1)sum[i] += sum[i - 1];
    wfor(i, 0, tot)toop[--sum[sam[i].len]] = i;
    mfor(i, tot - 1, 0)
    {
        int v = toop[i];
        for (auto k : sam[v]._next)
            sam[v].num += sam[k.second].num;
        sam[v].num++;
    }
    // sam[0].num--;
    int q;
    cin >> q;
    while (q--)
    {
        int num;
        cin >> num;
        ans = "";
        slove(0, num);
        cout << ans << endl;
    }
    return 0;
}
