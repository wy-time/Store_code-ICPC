#include <iostream>
#include <set>
#include <cmath>
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
const int mod = 1e9 + 7;
const int maxn = 2e9 + 1;
int main()
{
//     std::ios::sync_with_stdio(false);
// #ifdef test
//     freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
// #ifdef ubuntu
//     freopen("/home/time/debug/debug/in", "r", stdin);
//     freopen("/home/time/debug/debug/out", "w", stdout);
// #endif
    int t;
    // cin >> t;
    read(t);
    set<int>st;
    int i;
    for (i = 0; i * i < maxn; i++)
    {
        st.insert(i * i);
    }
    while (t--)
    {
        ll sum = 0;
        ll ans = 0;
        int  n;
        // cin >> n;
        read(n);
        if (st.count(n) == 1)
            // cout << "infty" << endl;
            // puts("infty");
            printf("infty\n");
        else if (n % 4 != 0)
        {
            // cout << 0 << " " << 0 << endl;
            printf("0 0\n");
        } else
        {
            int temp = n / 4;
            for (i = 1; i * i <= temp; ++i)
            {
                if (temp % i == 0)
                {
                    ll y = i;
                    ll z = temp / i;
                    ll x = y + z;
                    sum = sum + x % mod * y % mod * z % mod;
                    sum %= mod;
                    ans++;
                }
            }
            // cout << ans << " " << sum << endl;
            printf("%lld %lld\n", ans, sum);
        }
    }
    return 0;
}
