#include <iostream>
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
ll ma[2][10005];
const ll mod = 100000007;
ll slove (string s, ll temp)
{
    ll i;
    ll len = s.size();
    ll num;
    wfor(i, 1, len)
    {
        num = s[i] - '0';
        ll have = ma[0][i] + ma[0][i - 1] + ma[1][i] + ma[1][i - 1];
        ll need = num - have;
        if (need < 0 || 2 < need || (i == len - 1 && need != 0))
        {
            temp = 0;
            break;
        }
        if (need == 1)
        {
            ma[0][i + 1] = 1;
            temp *= 2ll;
            temp %= mod;
        } else if (need == 2)
        {
            ma[0][i + 1] = 1;
            ma[1][i + 1] = 1;
        }
    }
    memset(ma, 0, sizeof(ma));
    return temp % mod;
}
int main()
{
    std::ios::sync_with_stdio(false);
// #ifdef test
//     freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
// #ifdef ubuntu
//     freopen("/home/time/debug/debug/in", "r", stdin);
//     freopen("/home/time/debug/debug/out", "w", stdout);
// #endif
    ll t;
    cin >> t;
    while (t--)
    {
        memset(ma, 0, sizeof(ma));
        string s;
        cin >> s;
        int len = s.size();
        ll ans = 0;
        if (s[0] - '0' <= 2)
        {
            ll num = s[0] - '0';
            ll temp = 1;
            if (num == 1)
            {
                ma[0][1] = 1;
                temp = 2;
            } else if (num == 2)
            {
                temp = 1;
                ma[0][1] = 1;
                ma[1][1] = 1;
            }
            if (len == 1 && num != 0)
            {
                temp = 0;
            }
            ans += slove(s, temp);
        }
        if (s[0] - '0' <= 3 && s[0] - '0' >= 1)
        {
            ll num = s[0] - '0';
            ll temp = 1;
            if (num == 3)
            {
                ma[0][1] = 1;
                ma[1][1] = 1;
                ma[0][0] = 1;
                temp = 2;
            } else if (num == 2)
            {
                ma[0][0] = 1;
                ma[0][1] = 1;
                temp = 4;
            } else if (num == 1)
            {
                ma[0][0] = 1;
                temp = 2;
            }
            if (num >= 2 && len == 1)
            {
                temp = 0;
            }
            ans += slove(s, temp);
            ans %= mod;
        }
        if (s[0] - '0' <= 4 && s[0] - '0' >= 2)
        {
            ll num = s[0] - '0';
            ll temp = 1;
            ma[0][0] = 1;
            ma[1][0] = 1;
            if (num == 2)
            {
                temp = 1;
            } else if (num == 3)
            {
                ma[0][1] = 1;
                temp = 2;
            } else if (num == 4)
            {
                ma[0][1] = ma[1][1] = 1;
                temp = 1;
            }
            if (num >= 3 && len == 1)
            {
                temp = 0;
            }
            ans += slove(s, temp);
            ans %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}
