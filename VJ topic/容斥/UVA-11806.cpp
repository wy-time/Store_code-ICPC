#include <iostream>
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
const ll mod = 1000007;
const ll maxn = 600;
ll co[maxn][maxn];
void init()
{
    co[0][0] = 1;
    ll i, j;
    // co[1][1] = 1;
    // co[1][0] = 1;
    wfor(i, 1, maxn)
    {
        co[i][0] = co[i][i] = 1;
        wfor(j, 1, i)
        {
            co[i][j] = co[i - 1][j] + co[i - 1][j - 1];
            co[i][j] %= mod;
        }
    }
}
ll comb(ll m, ll n)
{
    if (m < n)
        return 0;
    return co[m][n];
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
    init();
    cin >> t;
    ll casecnt = 0;
    while (t--)
    {
        casecnt++;
        ll n, m, k;
        cin >> n >> m >> k;
        ll ans = comb(n * m, k);
        ll maxnum = 1 << 4;
        ll i;
        wfor(i, 1, maxnum)
        {
            ll h = 0, l = 0;
            if (i & 1)
                h++;
            if (i & (1 << 1))
                h++;
            if (i & 1 << 2)
                l++;
            if (i & (1 << 3))
                l++;
            ll are = (n - h) * (m - l);
            if ((h + l) % 2 == 0)
                ans = (ans + comb(are, k)) % mod;
            else
                ans = (ans - comb(are, k) + mod) % mod;
        }
        cout << "Case " << casecnt << ": " << (ans + mod) % mod << endl;
    }
    return 0;
}
// #include <iostream>
// using namespace std;
// #define mod 1000007

// const int maxn = 550;
// int C[maxn][maxn];

// int main()
// {
//     C[0][0] = 1;
//     for (int i = 1; i < maxn; i++)
//     {
//         C[i][0] = C[i][i] = 1;
//         for (int j = 1; j < i; j++)
//             C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
//     }
//     int T, kase = 0;
//     cin >> T;
//     while (T--)
//     {
//         int n, m, k, ans = 0;
//         cin >> n >> m >> k;
//         for (int S = 0; S < (1 << 4); S++)
//         {
//             int b = 0, r = n, c = m;
//             if (S & 1)
//             {
//                 b++;
//                 r--;
//             }
//             if (S & 2)
//             {
//                 b++;
//                 r--;
//             }
//             if (S & 4)
//             {
//                 b++;
//                 c--;
//             }
//             if (S & 8)
//             {
//                 b++;
//                 c--;
//             }
//             if (b & 1)
//                 ans = (ans + mod - C[r * c][k]) % mod;

//             else
//                 ans = (ans + C[r * c][k]) % mod;

//         }
//         cout << "Case " << ++kase << ": " << ans << endl;

//     }
//     return 0;
// }
