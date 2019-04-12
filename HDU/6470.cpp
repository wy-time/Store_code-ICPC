#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
void read(ll &x) {
    char ch = getchar(); x = 0;
    for (; ch < '0' || ch > '9'; ch = getchar());
    for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
const ll mod = 123456789;
struct Matrix
{
    ll ma[6][6];
    Matrix()
    {
        ll i, j;
        wfor(i, 0, 6)
        {
            wfor(j, 0, 6)
            {
                ma[i][j] = 0;
            }
        }
    }
};
Matrix A;
Matrix B;
Matrix mul(Matrix a, Matrix b)
{
    ll i, j, k;
    Matrix c;
    wfor(i, 0, 6)
    {
        wfor(j, 0, 6)
        {
            wfor(k, 0, 6)
            {
                c.ma[i][j] += (a.ma[i][k] * b.ma[k][j]) % mod;
                c.ma[i][j] %= mod;
            }
        }
    }
    return c;
}
Matrix ksm (ll n)
{
    ll i;
    Matrix ans;
    wfor(i, 0, 6)
    {
        ans.ma[i][i] = 1;
    }
    while (n)
    {
        if (n & 1)
        {
            ans = mul(ans, A);
        }
        A = mul(A, A);
        n >>= 1;
    }
    return ans;
}
void init()
{
    memset(A.ma, 0, sizeof(A.ma));
    memset(B.ma, 0, sizeof(B.ma));
    A.ma[0][1] = 2;
    A.ma[1][0] = 1;
    A.ma[1][1] = 1;
    A.ma[2][2] = 1;
    A.ma[2][3] = 2;
    A.ma[2][4] = 3;
    A.ma[3][3] = 1;
    A.ma[3][4] = 3;
    A.ma[4][1] = 1;
    A.ma[4][4] = 1;
    A.ma[5][2] = 1;
    A.ma[5][3] = 1;
    A.ma[5][4] = 1;
    A.ma[5][5] = 1;
    B.ma[0][0] = 1;
    B.ma[0][1] = 2;
    B.ma[0][2] = 3;
    B.ma[0][3] = 9;
    B.ma[0][4] = 27;
    B.ma[0][5] = 1;
}
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
    ll t;
    // cin >> t;
    read(t);
    ll i;
    ll res[105];
    res[1] = 1;
    res[2] = 2;
    wfor(i, 3, 101)
    {
        res[i] = (2 * res[i - 2] + res[i - 1] + i * i * i) % mod;
    }
    while (t--)
    {
        ll n;
        // cin >> n;
        read(n);
        if (n > 100)
        {
            init();
            A = ksm(n - 1);
            ll ans = 0;
            int i;
            wfor(i, 0, 6)
            {
                ans += A.ma[i][0] * B.ma[0][i];
                ans %= mod;
            }
            // cout << ans << endl;
            printf("%lld\n", ans);
        } else
            // cout << res[n] << endl;
            printf("%lld\n", res[n]);
    }
    return 0;
}
