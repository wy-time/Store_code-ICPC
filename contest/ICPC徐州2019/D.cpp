#include <iostream>
#include <cstring>
#include <string>
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
const int maxn = 2e5 + 5;
struct st
{
    int len;
    int link;
    int _next[26];
};
int sz, last;
st sam[maxn * 2];
st sam2[maxn * 2];
int sz2, last2;
void init2()
{
    sz2 = 0;
    sam2[sz2].len = 0;
    sam2[sz2].link = -1;
    memset(sam2[sz2]._next, 0, sizeof(sam2[sz2]._next));
    sz2++;
    last2 = 0;
}
void init_node(int id)
{
    sam2[id].len = 0;
    sam2[id].link = -1;
    memset(sam2[id]._next, 0, sizeof(sam2[id]._next));
}
void init()
{
    sam[sz].len = 0;
    sam[sz].link = -1;
    memset(sam[sz]._next, 0, sizeof(sam[sz]._next));
    sz++;
    last = 0;
}
void add(char c)
{
    int cur = sz++;
    sam[cur].len = sam[last].len + 1;
    int p = last;
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
            int cop = sz++;
            sam[cop] = sam[q];
            sam[cop].len = sam[p].len + 1;
            for (; p != -1 && sam[p]._next[c - 'a'] == q; p = sam[p].link)
                sam[p]._next[c - 'a'] = cop;
            sam[q].link = cop;
            sam[cur].link = cop;
        }
    }
    last = cur;
}
void add2(char c)
{
    int cur = sz2++;
    init_node(cur);
    sam2[cur].len = sam2[last2].len + 1;
    int p = last2;
    for (; p != -1 && !sam2[p]._next[c - 'a']; p = sam2[p].link)
        sam2[p]._next[c - 'a'] = cur;
    if (p == -1)
        sam2[cur].link = 0;
    else
    {
        int q = sam2[p]._next[c - 'a'];
        if (sam2[p].len + 1 == sam2[q].len)
            sam2[cur].link = q;
        else
        {
            int cop = sz2++;
            sam2[cop] = sam2[q];
            sam2[cop].len = sam2[p].len + 1;
            for (; p != -1 && sam2[p]._next[c - 'a'] == q; p = sam2[p].link)
                sam2[p]._next[c - 'a'] = cop;
            sam2[q].link = cop;
            sam2[cur].link = cop;
        }
    }
    last2 = cur;
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
    string s, t;
    cin >> s;
    init();
    int len = s.size();
    int i;
    wfor(i, 0, len)
    {
        add(s[i]);
    }
    init2();
    int n;
    cin >> n;
    while (n--)
    {
        cin >> t;
        if (t.size() < s.size())
        {
            int flag = 1;
            int v = 0;
            int last_t = 0;
            wfor(i, 0, t.length())
            {
                // while (v && !sam[v]._next[t[i] - 'a'])
                //     v = sam[v].link;
                if (sam[v]._next[t[i] - 'a'] != 0)
                {
                    v = sam[v]._next[t[i] - 'a'];
                }
                // if (v != last_t)
                //     last_t = v;
                else
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
                cout << "my child!" << endl;
            else
                cout << "oh, child!" << endl;
        } else if (t.size() > s.size())
        {
            init2();
            int len2 = t.size();
            int flag = 1;
            wfor(i, 0, len2)
            {
                add2(t[i]);
            }
            int v = 0;
            int last_t = 0;
            wfor(i, 0, s.length())
            {
                // while (v && !sam2[v]._next[s[i] - 'a'])
                //     v = sam2[v].link;
                if (sam2[v]._next[s[i] - 'a'] != 0)
                {
                    v = sam2[v]._next[s[i] - 'a'];
                }
                // if (v != last_t)
                //     last_t = v;
                else
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
                cout << "my teacher!" << endl;
            else
                cout << "senior!" << endl;
        } else
        {
            if (s.compare(t) == 0)
                cout << "jntm!" << endl;
            else
                cout << "friend!" << endl;
        }
    }
    return 0;
}