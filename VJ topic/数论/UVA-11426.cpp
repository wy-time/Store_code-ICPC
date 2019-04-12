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
const int maxn = 4e6 + 2;
int eul[maxn];
void get_eul()
{
    eul[1] = 0;
    int i;
    wfor(i, 2, maxn)
    eul[i] = i;
    wfor(i, 2, maxn)
    {
        if (eul[i] == i)
        {
            int j;
            for (j = i; j < maxn; j += i)
                eul[j] = eul[j] / i * (i - 1);
        }
    }
}
ll ans[maxn];
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
    int n;
    ll i, j;
    get_eul();
    wfor(i, 1, maxn)
    {
        for (j = 2 * i; j < maxn; j += i)
        {
            ans[j] += eul[j / i] * i;
        }
    }
    wfor(i, 2, maxn)
    {
        sum[i] = sum[i - 1] + ans[i];
    }
    while (cin >> n && n)
    {
        cout << sum[n] << endl;
    }
    return 0;
}
