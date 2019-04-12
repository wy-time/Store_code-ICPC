#include <iostream>
#include <algorithm>
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
int num[maxn];
//int sum[maxn];
//ll ji[maxn];
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
    ll n, m;
    cin >> n >> m;
    int i;
    wfor(i, 0, n)
    {
        cin >> num[i];
    }
    sort(num, num + n);
    ll sum = 0;
    ll ji = 0;
    wfor(i, 0, m)
    {
        sum += num[i];
        ji += num[i] * num[i];
    }
    ll ans = ji * m - sum * sum;
    wfor(i, m, n)
    {
        ji -= num[i - m] * num[i - m];
        ji += num[i] * num[i];
        sum += num[i];
        sum -= num[i - m];
        ans = min(ans, ji * m - sum * sum);
    }
    cout << ans << endl;
    return 0;
}
