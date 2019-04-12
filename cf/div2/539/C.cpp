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
const int maxn = 3e5 + 5;
int num[maxn];
int sum[maxn];
int jishu[2100000];
int oshu[2100000];
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
    cin >> n;
    int i;
    wfor(i, 0, n)
    {
        cin >> num[i];
    }
    sum[0] = num[0];
    ll ans = 0;
    oshu[num[0]] = 1;
    wfor(i, 1, n)
    {
        sum[i] = sum[i - 1] ^ num[i];
        if (i % 2 == 0)
        {
            ans += oshu[sum[i]];
            oshu[sum[i]]++;
        }
        else
        {
            ans += jishu[sum[i]];
            jishu[sum[i]]++;
        }
        if (sum[i] == 0 && i % 2 == 1)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
