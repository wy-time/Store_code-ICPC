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
const int maxn = 50006;
const ll mod = 192600817;
ll fib[maxn];
ll sum[maxn];
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
    int i;
    fib[1] = 1;
    fib[2] = 1;
    sum[1] = 1;
    sum[2] = 2;
    wfor(i, 3, maxn)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
        fib[i] %= mod;
        sum[i] = (sum[i - 1] + fib[i] * fib[i] % mod) % mod;
    }
    int q;
    while (cin >> q)
    {
        while (q--)
        {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            int beg = a * 4 + b;
            int end = c * 4 + d;
            if (beg > end)
                swap(beg, end);
            cout << (sum[end + 1] - sum[beg] + mod) % mod << endl;
        }
    }
    return 0;
}
