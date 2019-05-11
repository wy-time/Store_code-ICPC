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
// void read(int &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn = 100; /*精度位数,自行调整*/
//1.如果需要控制输出位数的话，在str()里面把len调成需要的位数
//2.很大的位数是会re的，所以如果是幂运算的话，如 计算x^p的位数n, n=p*log(10)x+1;(注意要加一）
//3.还可以加上qmul，取模的过程也就是str()，c_str()再搞一次
class bign
{
    //io*2 bign*5*2 bool*6
    friend istream& operator>>(istream&, bign&);
    friend ostream& operator<<(ostream&, const bign&);
    friend bign operator+(const bign&, const bign&);
    friend bign operator+(const bign&, int&);
    friend bign operator*(const bign&, const bign&);
    friend bign operator*(const bign&, int&);
    friend bign operator-(const bign&, const bign&);
    friend bign operator-(const bign&, int&);
    friend bign operator/(const bign&, const bign&);
    friend bign operator/(const bign&, int&);
    friend bign operator%(const bign&, const bign&);
    friend bign operator%(const bign&, int&);
    friend bool operator<(const bign&, const bign&);
    friend bool operator>(const bign&, const bign&);
    friend bool operator<=(const bign&, const bign&);
    friend bool operator>=(const bign&, const bign&);
    friend bool operator==(const bign&, const bign&);
    friend bool operator!=(const bign&, const bign&);

private://如果想访问len,改成public
    int len, s[maxn];
public:
    bign()
    {
        memset(s, 0, sizeof(s));
        len = 1;
    }
    bign operator=(const char* num)
    {
        int i = 0, ol;
        ol = len = strlen(num);
        while (num[i++] == '0' && len > 1)
            len--;
        memset(s, 0, sizeof(s));
        for (i = 0; i < len; i++)
            s[i] = num[ol - i - 1] - '0';
        return *this;
    }
    bign operator=(int num)
    {
        char s[maxn];
        sprintf(s, "%d", num);
        *this = s;
        return *this;
    }
    bign(int num)
    {
        *this = num;
    }
    bign(const char* num)
    {
        *this = num;
    }
    string str() const
    {
        string res = "";
        for (int i = 0; i < len; i++)
            res = char(s[i] + '0') + res;
        if (res == "")
            res = "0";
        return res;
    }
};
bool operator<(const bign& a, const bign& b)
{
    int i;
    if (a.len != b.len)
        return a.len < b.len;
    for (i = a.len - 1; i >= 0; i--)
        if (a.s[i] != b.s[i])
            return a.s[i] < b.s[i];
    return false;
}
bool operator>(const bign& a, const bign& b)
{
    return b < a;
}
bool operator<=(const bign& a, const bign& b)
{
    return !(a > b);
}
bool operator>=(const bign& a, const bign& b)
{
    return !(a < b);
}
bool operator!=(const bign& a, const bign& b)
{
    return a < b || a > b;
}
bool operator==(const bign& a, const bign& b)
{
    return !(a < b || a > b);
}
bign operator+(const bign& a, const bign& b)
{
    int up = max(a.len, b.len);
    bign sum;
    sum.len = 0;
    for (int i = 0, t = 0; t || i < up; i++)
    {
        if (i < a.len)
            t += a.s[i];
        if (i < b.len)
            t += b.s[i];
        sum.s[sum.len++] = t % 10;
        t /= 10;
    }
    return sum;
}
bign operator+(const bign& a, int& b)
{
    bign c = b;
    return a + c;
}
bign operator*(const bign& a, const bign& b)
{
    bign res;
    for (int i = 0; i < a.len; i++)
    {
        for (int j = 0; j < b.len; j++)
        {
            res.s[i + j] += (a.s[i] * b.s[j]);
            res.s[i + j + 1] += res.s[i + j] / 10;
            res.s[i + j] %= 10;
        }
    }
    res.len = a.len + b.len;
    while (res.s[res.len - 1] == 0 && res.len > 1)
        res.len--;
    if (res.s[res.len])
        res.len++;
    return res;
}
bign operator*(const bign& a, int& b)
{
    bign c = b;
    return a * c;
}
//只支持大数减小数
bign operator-(const bign& a, const bign& b)
{
    bign res;
    int len = a.len;
    for (int i = 0; i < len; i++)
    {
        res.s[i] += a.s[i] - b.s[i];
        if (res.s[i] < 0)
        {
            res.s[i] += 10;
            res.s[i + 1]--;
        }
    }
    while (res.s[len - 1] == 0 && len > 1)
        len--;
    res.len = len;
    return res;
}
bign operator-(const bign& a, int& b)
{
    bign c = b;
    return a - c;
}
bign operator/(const bign& a, const bign& b)
{
    int i, len = a.len;
    bign res, f;
    for (i = len - 1; i >= 0; i--)
    {
        f = f * 10;
        f.s[0] = a.s[i];
        while (f >= b)
        {
            f = f - b;
            res.s[i]++;
        }
    }
    while (res.s[len - 1] == 0 && len > 1)
        len--;
    res.len = len;
    return res;
}
bign operator/(const bign& a, int& b)
{
    bign c = b;
    return a / c;
}
bign operator%(const bign& a, const bign& b)
{
    int len = a.len;
    bign f;
    for (int i = len - 1; i >= 0; i--)
    {
        f = f * 10;
        f.s[0] = a.s[i];
        while (f >= b)
            f = f - b;
    }
    return f;
}
bign operator%(const bign& a, int& b)
{
    bign c = b;
    return a % c;
}
bign& operator+=(bign& a, const bign& b)
{
    a = a + b;
    return a;
}
bign& operator-=(bign& a, const bign& b)
{
    a = a - b;
    return a;
}
bign& operator*=(bign& a, const bign& b)
{
    a = a * b;
    return a;
}
bign& operator/=(bign& a, const bign& b)
{
    a = a / b;
    return a;
}
bign& operator++(bign& a)
{
    a = a + 1;
    return a;
}
bign& operator++(bign& a, int)
{
    bign t = a;
    a = a + 1;
    return t;
}
bign& operator--(bign& a)
{
    a = a - 1;
    return a;
}
bign& operator--(bign& a, int)
{
    bign t = a;
    a = a - 1;
    return t;
}
istream& operator>>(istream &in, bign& x)
{
    string s;
    in >> s;
    x = s.c_str();
    return in;
}
ostream& operator<<(ostream &out, const bign& x)
{
    out << x.str();
    return out;
}
int cnt = 0;
struct st
{
    int next[55];
    int fail;
    int is_jail;
    void init()
    {
        memset(next, 0, sizeof(next));
        fail = -1;
        is_jail = 0;
    }
};
st trie[105];
map<char, int>ma;
int num;
void build(string s)
{
    int len = s.size();
    int i;
    int now = 0;
    wfor(i, 0, len)
    {
        int pos = ma[s[i]];
        if (trie[now].next[pos] == 0)
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
    queue<int>qu;
    int now = 0;
    int i;
    wfor(i, 0, cnt)
    {
        if (trie[now].next[i] != 0)
        {
            int pos = trie[now].next[i];
            trie[pos].fail = 0;
            qu.push(pos);
        }
    }
    while (!qu.empty())
    {
        int father = qu.front();
        qu.pop();
        wfor(i, 0, cnt)
        {
            int now = trie[father].fail;
            int child = trie[father].next[i];
            if (child != 0)
            {
                while (now && trie[now].next[i] == 0)
                    now = trie[now].fail;
                trie[child].fail = trie[now].next[i];
                trie[child].is_jail |= trie[trie[child].fail].is_jail;
                qu.push(child);
            } else
                trie[father].next[i] = trie[trie[father].fail].next[i];
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
    int n, m, p;
    cin >> n >> m >> p;
    trie[0].init();
    string s;
    cin >> s;
    int len = s.size();
    int i;
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
    bign dp[105][55];
    dp[0][0] = 1;
    int j;
    wfor(j, 0, m + 1)
    {
        wfor(i, 0, num + 1)
        {
            if (trie[i].is_jail != 0)continue;
            int k;
            wfor(k, 0, cnt)
            {
                if (trie[trie[i].next[k]].is_jail == 0)
                {
                    dp[trie[i].next[k]][j + 1] += dp[i][j];
                }
            }
        }
    }
    bign out = 0;
    wfor(i, 0, num + 1)
    {
        out += dp[i][m];
    }
    cout << out << endl;
    return 0;
}