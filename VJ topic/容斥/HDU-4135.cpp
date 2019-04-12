#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
vector<ll>v;
ll cnt;
ll slove(ll step, ll need, ll ans, ll last, ll l, ll r)
{
    if (ans > r)
        return -1;
    if (step == need)
    {
        cnt += r / ans - (l - 1) / ans;
        return ans / v[last - 1];
    }
    ll len = v.size();
    ll i;
    wfor(i, last, len)
    {
        ans = slove(step + 1, need, v[i] * ans, i + 1, l, r);
        if (ans == -1)
            return -1;
    }
    if (step != 0)
        return ans / v[last - 1];
    else
        return 1;
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
    ll casecnt = 0;
    while (t--)
    {
        casecnt++;
        v.clear();
        ll l, r, n;
        cin >> l >> r >> n;
        ll ans = 0;
        if (n == 1)
        {
            ans = 0;
        } else
        {
            ll i;
            for (i = 2; i * i <= n; i++)
            {
                if (n % i == 0)
                {
                    v.push_back(i);
                    while (n % i == 0)
                    {
                        n /= i;
                    }
                }
            }
            if (n > 1)
                v.push_back(n);
            ll len = v.size();
            wfor(i, 1, len + 1)
            {
                cnt = 0;
                slove(0, i, 1, 0, l, r);
                if (i % 2 == 0)
                {
                    ans -= cnt;
                } else
                    ans += cnt;
            }
        }
        cout << "Case #" << casecnt << ": " << r - l + 1 - ans << endl;
    }
    return 0;
}
