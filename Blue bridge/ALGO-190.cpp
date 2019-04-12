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
const int maxn = 1e6 + 5;
int prime[maxn];
void get_prime()
{
    int i;
    wfor(i, 2, maxn)
    {
        if (prime[i] == 0)
            prime[++prime[0]] = i;
        int j;
        for (j = 1; j <= prime[0] && i * prime[j] < maxn; j++)
        {
            prime[prime[j]*i] = 1;
            if (i % prime[j] == 0)
                break;
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
    ll n;
    cin >> n;
    get_prime();
    int i;
    ll ans = 1;
    wfor(i, 1, prime[0] + 1)
    {
        if (n < prime[i])break;
        if (n % prime[i] == 0)
        {
            ans *= prime[i];
            while (n % prime[i] == 0)
            {
                n /= prime[i];
            }
        }
    }
    if (n > 1)
    {
        ans *= n;
    }
    cout << ans << endl;
    return 0;
}
