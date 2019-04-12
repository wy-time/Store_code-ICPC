#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//     char ch = getchar(); x = 0;
//     for (; ch < '0' || ch > '9'; ch = getchar());
//     for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn = 33000;
struct NODE
{
    int cnt;
    int _next[256];
    int _fail;
};
NODE node[maxn];
void node_init(int cnt)
{
    node[cnt].cnt = 0;
    node[cnt]._fail = -1;
    memset(node[cnt]._next, -1, sizeof(node[cnt]._next));
}
void char_insert(int s[], int n);
void cal_fail();
int query(int s[], int n);
int unencode(char *s, int mode);
int num;
int vis[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
// #ifdef test
//     freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
    int n;
    char s[5000];
    while (cin >> n)
    {
        num = 0;
        int i;
        node_init(0);
        wfor(i, 0, n)
        {
            cin >> s;
            unencode(s, 1);
        }
        cal_fail();
        int m;
        cin >> m;
        while (m--)
        {
            cin >> s;
            memset(vis, 0, sizeof(vis));
            int res = unencode(s, 0);
            cout << res << endl;
        }
        cout << endl;
    }
    return 0;
}
void char_insert(int s[], int n)
{
    int p = 0;
    int len = n;
    int i;
    wfor(i, 0, len)
    {
        int t = s[i];
        if (node[p]._next[t] == -1)
        {
            node_init(++num);
            node[p]._next[t] = num;
        }
        p = node[p]._next[t];
    }
    node[p].cnt++;
}
void cal_fail()
{
    queue<NODE>qu;
    int i;
    wfor(i, 0, 256)
    {
        int t = node[0]._next[i];
        if (t != -1)
        {
            node[t]._fail = 0;
            qu.push(node[t]);
        }
    }
    while (!qu.empty())
    {
        NODE temp = qu.front();
        qu.pop();
        wfor(i, 0, 256)
        {
            if (temp._next[i] != -1)
            {
                int p = temp._fail;
                while (p != -1)
                {
                    if (node[p]._next[i] != -1)
                    {
                        break;
                    }
                    p = node[p]._fail;
                }
                if (p != -1)
                    node[temp._next[i]]._fail = node[p]._next[i];
                else
                    node[temp._next[i]]._fail = 0;
                qu.push(node[temp._next[i]]);
            }
        }
    }
}
int query(int s[], int n)
{
    int len = n;
    int i;
    int p = 0;
    int ans = 0;
    wfor(i, 0, len)
    {
        int t = s[i];
        while (p != 0 && node[p]._next[t] == -1)
            p = node[p]._fail;
        p = node[p]._next[t];
        int temp;
        if (p != -1)
            temp = p;
        else
            temp = p = 0;
        while (temp != 0 && !vis[temp])
        {
            ans += node[temp].cnt;
            vis[temp] = 1;
            temp = node[temp]._fail;
        }
    }
    return ans;
}
int unencode(char *s, int mode)
{
    int len = strlen(s);
    int ss[3000];
    int i;
    int tlen = 0;
    int now = 0;
    int pos = 0;
    wfor(i, 0, len)
    {
        int t = -1;
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            t = s[i] - 'A';
        } else if (s[i] >= 'a' && s[i] <= 'z')
        {
            t = s[i] - 'a' + 26;
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            t = s[i] - '0' + 52;
        } else if (s[i] == '+')
            t = 62;
        else if (s[i] == '/')
            t = 63;
        else
            break;
        now = (now << 6) | t;
        tlen += 6;
        while (tlen >= 8)
        {
            tlen -= 8;
            ss[pos++] = (now >> tlen) & 0xff;
        }
    }
    if (mode == 1)
        char_insert(ss, pos);
    else
        return query(ss, pos);
    return 0;
}