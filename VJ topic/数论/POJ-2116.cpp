#include <iostream>
#include <algorithm>
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
ll fib[45];
string get_canorical(ll x)
{
    string ans = "";
    int pos = lower_bound(fib, fib + 45, x) - fib;
    if (fib[pos] == x)
    {
        ans += '1';
        int i;
        wfor(i, 0, pos)
        ans += '0';
        x -= fib[pos];
    } else
    {
        if (pos != 0)
        {
            ans += '1';
            int i;
            wfor(i, 0, pos - 1)
            ans += '0';
        } else
            ans = "0";
        x -= fib[pos - 1];
    }
    int len = ans.size();
    while (x > 0)
    {
        pos = lower_bound(fib, fib + 45, x) - fib;
        if (fib[pos] == x)
        {
            ans[len - 1 - pos] = '1';
            x -= fib[pos];
        } else
        {
            ans[len - pos] = '1';
            x -= fib[pos - 1];
        }
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
    string s1, s2;
    fib[0] = 1;
    fib[1] = 2;
    int i;
    wfor(i, 2, 45)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    while (cin >> s1 >> s2)
    {
        ll x = 0, y = 0;
        int len = s1.size();
        wfor(i, 0, len)
        {
            if (s1[i] != '0')
                x += fib[len - 1 - i];
        }
        len = s2.size();
        wfor(i, 0, len)
        {
            if (s2[i] != '0')
                y += fib[len - 1 - i];
        }
        ll ans = x + y;
        string X = get_canorical(x);
        string Y = get_canorical(y);
        string ANS = get_canorical(ans);
        int maxlen = max(X.size(), max(Y.size(), ANS.size()));
        wfor(i, 0, maxlen - X.size() + 2)
        {
            cout << " ";
        }
        cout << X << endl;
        cout << "+ ";
        wfor(i, 0, maxlen - Y.size())
        {
            cout << " ";
        }
        cout << Y << endl;
        cout << "  ";
        wfor(i, 0, maxlen)
        {
            cout << "-";
        }
        cout << endl;
        cout << "  " << ANS << endl;
        cout << endl;
    }
    return 0;
}
