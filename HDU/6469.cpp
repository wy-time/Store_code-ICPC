#include <iostream>
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
int slove(int n, int k)
{
    int now = 1;
    int num = 0;
    while (now * 10 <= n)
    {
        num += now;
        now *= 10;
    }
    if (now < 10 && n >= k)
        num++;
    else
    {
        if (n >= now * k && n < now * (k + 1))
            num += n - now * k + 1;
        else if (n >= now * (k + 1))
            num += now;
    }
    return num;
}
int need = 0;
int dfs(int n, int m, int k)
{
    need++;
    if (k == need)
    {
        return m;
    }
    if (m * 10 <= n)
    {
        int cnt = 0;
        while (m * 10 <= n)
        {
            int t = dfs(n, m * 10, k);
            if (t != 0)
                return t;
            cnt++;
            if (m < 10 || cnt >= 10)
                break;
            m++;
            need++;
            if (need == k)
                return m;
        }
    } else
    {
        int i;
        for (i = 1; i < 10 && m + i <= n; i++)
        {
            need++;
            if (need == k)
                return m + i;
        }
    }
    return 0;
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
    int t;
    cin >> t;
    while (t--)
    {
        need = 0;
        int n, k;
        cin >> n >> k;
        int i;
        wfor(i, 1, 10)
        {
            int cnt = slove(n, i);
            if (cnt >= k)
            {
                int ans = dfs(n, i, k);
                cout << ans << endl;
                break;
            } else
                k -= cnt;
        }
    }
    return 0;
}
