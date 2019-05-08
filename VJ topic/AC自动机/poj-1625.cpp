#include <iostream>
#include <queue>
#include <map>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
ll cnt = 0;
struct st
{
    ll next[55];
    ll fail;
    ll is_jail;
    void init()
    {
        memset(next, -1, sizeof(next));
        fail = -1;
        is_jail = 0;
    }
};
st trie[105];
map<char, ll>ma;
ll num;
void build(string s)
{
    ll len = s.size();
    ll i;
    ll now = 0;
    wfor(i, 0, len)
    {
        ll pos = ma[s[i]];
        if (trie[now].next[pos] == -1)
        {
            trie[++num].init();
            trie[now].next[pos] = num;
        }
        now = trie[now].next[pos];
    }
    trie[now].is_jail = 1;
}
void cal_fail()
{
    queue<ll>qu;
    ll now = 0;
    ll i;
    wfor(i, 0, cnt)
    {
        if (trie[now].next[i] != -1)
        {
            ll pos = trie[now].next[i];
            trie[pos].fail = 0;
            qu.push(pos);
        }
    }
    while (!qu.empty())
    {
        ll father = qu.front();
        qu.pop();
        wfor(i, 0, cnt)
        {
            ll now = trie[father].fail;
            ll child = trie[father].next[i];
            if (child != -1)
            {
                while (now != -1 && trie[now].next[i] == -1)
                    now = trie[now].fail;
                if (now == -1)
                {
                    trie[child].fail = 0;
                } else
                {
                    trie[child].fail = trie[now].next[i];
                    if (trie[trie[now].next[i]].is_jail != 0)
                        trie[child].is_jail = 1;
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
void get_matix(Matix &ans)
{
    ll i, j;
    wfor(i, 0, num)
    {
        if (trie[i].is_jail == 0)
        {
            wfor(j, 0, cnt)
            {
                if (trie[i].next[j] == -1)
                {
                    ll now = i;
                    while (now != -1 && trie[now].next[j] == -1)
                        now = trie[now].fail;
                    if (now != -1)
                    {
                        if (trie[trie[now].next[j]].is_jail == 0)
                            ans.m[i][trie[now].next[j]]++;
                    } else
                        ans.m[i][0]++;
                } else
                {
                    ll pos = trie[i].next[j];
                    if (trie[pos].is_jail == 0)
                        ans.m[i][pos]++;
                }
            }
        }
    }
}
Matix mul(Matix a, Matix b)
{
    Matix c;
    memset(c.m, 0, sizeof(c));
    ll i, j, k;
    wfor(i, 0, num)
    {
        wfor(j, 0, num)
        {
            wfor(k, 0, num)
            {
                c.m[i][j] += a.m[i][k] * b.m[k][j];
            }
        }
    }
    return c;
}
Matix ksm(Matix a, ll b)
{
    Matix ans;
    memset(ans.m, 0, sizeof(ans.m));
    ll i;
    wfor(i, 0, num)
    {
        ans.m[i][i] = 1;
    }
    while (b)
    {
        if (b & 1)
            ans = mul(a, ans);
        b >>= 1;
        a = mul(a, a);
    }
    return ans;
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
    ll n, m, p;
    cin >> n >> m >> p;
    trie[0].init();
    string s;
    cin >> s;
    ll len = s.size();
    ll i;
    wfor(i, 0, len)
    {
        if (ma.count(s[i]) == 0)
            ma.insert(make_pair(s[i], cnt++));
    }
    wfor(i, 0, p)
    {
        cin >> s;
        build(s);
    }
    cal_fail();
    Matix ans;
    memset(ans.m, 0, sizeof(ans));
    get_matix(ans);
    ans = ksm(ans, m);
    ll out = 0;
    wfor(i, 0, num)
    {
        out += ans.m[0][i];
    }
    cout << out << endl;
    return 0;
}
