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
const int maxn = 20005;
int vis[maxn];
int prime[maxn];
void get_prime()
{
    int i;
    wfor(i, 2, maxn)
    {
        if (!prime[i])
        {
            vis[i] = 1;
            prime[++prime[0]] = i;
        }
        int j;
        for (j = 1; j <= prime[0] && prime[j]*i < maxn; j++)
        {
            prime[i * prime[j]] = 1;
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
    int n;
    get_prime();
    int casecnt = 0;
    vis[2] = 0;
    while (cin >> n && n > 0)
    {
        casecnt++;
        if (vis[n])
            cout << casecnt << ": yes" << endl;
        else
            cout << casecnt << ": no" << endl;
    }
    return 0;
}
