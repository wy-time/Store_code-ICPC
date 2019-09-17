#include <iostream>
#include <cstring>
#include <vector>
#include <string>
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
vector<string>s;
vector<string>t;
const int maxn = 100005;
struct st
{
    int len;
    int link;
    int _next[26];
    int cnt;
};
int tot, last;
st sam[2 * maxn];
void init(int id)
{
    sam[id].len = sam[id].cnt = 0;
    sam[id].link = -1;
    memset(sam[id]._next, 0, sizeof(sam[id]._next));
}
void add(char c)
{
    int cur = tot++;
    init(cur);
    sam[cur].len = sam[last].len + 1;
    sam[cur].cnt = 1;
    int p = last;
    last = cur;
    for (; p != -1 && !sam[p]._next[c - 'a']; p = sam[p].link)
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
            init(clone);
            sam[clone] = sam[q];
            sam[clone].len = sam[p].len + 1;
            for (; p != -1 && sam[p]._next[c - 'a'] == q; p = sam[p].link)
                sam[p]._next[c - 'a'] = clone;
            sam[cur].link = sam[q].link = clone;
        }
    }
}
int toop[maxn * 2];
void slove(int id, int ti)
{
    int sum[maxn] = {0};
    init(0);
    int i;
    wfor(i, 0, s[id].length())
    add(s[id][i]);
    wfor(i, 0, tot)sum[sam[i].len]++;
    wfor(i, 1, s[id].length() + 1)sum[i] += sum[i - 1];
    wfor(i, 0, tot)toop[--sum[sam[i].len]] = i;
    mfor(i, tot - 1, 0)
    {
        int v = toop[i];
        if (sam[v].link != -1)
            sam[sam[v].link].cnt += sam[v].cnt;
    }
    int now = 0;
    wfor(i, 0, t[ti].length())
    {
        if (now == -1)
            break;
        if (sam[now]._next[t[ti][i] - 'a'] != 0)
        {
            now = sam[now]._next[t[ti][i] - 'a'];
            continue;
        } else
        {
            now = sam[now].link;
            i--;
        }
    }
    if (now == -1 || t[ti].length() == 0)
        // cout << 0 << endl;
        printf("0\n");
    else
        // cout << sam[now].cnt << endl;
        printf("%d\n", sam[now].cnt);
}
int main()
{
    // std::ios::sync_with_stdio(false);
#ifdef test
    freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
#ifdef ubuntu
    freopen("/home/time/debug/debug/in", "r", stdin);
    freopen("/home/time/debug/debug/out", "w", stdout);
#endif
    int q;
    // cin >> q;
    read(q);
    s.clear();
    t.clear();
    s.push_back("");
    t.push_back("");
    while (q--)
    {
        int op;
        // cin >> op;
        read(op);
        char c;
        int si, ti, op2;
        string temp;
        switch (op)
        {
        case 1:
            // cin >> si >> c;
            scanf("%d %c", &si, &c);
            si--;
            temp = s[si] + c;
            s.push_back(temp);
            break;
        case 2:
            // cin >> op2 >> ti >> c;
            scanf("%d %d %c", &op2, &ti, &c);
            ti--;
            if (op2 == 0)
                temp = c + t[ti];
            else
                temp = t[ti] + c;
            t.push_back(temp);
            break;
        case 3:
            int ti2;
            // cin >> ti >> ti2;
            read(ti); read(ti2);
            ti2--; ti--;
            t.push_back(t[ti] + t[ti2]);
            break;
        case 4:
            // cin >> ti >> si;
            read(ti); read(si);
            ti--, si--;
            tot = 1; last = 0;
            slove(si, ti);
            break;
        }
    }
    return 0;
}
