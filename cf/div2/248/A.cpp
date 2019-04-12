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
const int maxn = 100;
struct st
{
    int l;
    int r;
};
st num[maxn];
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
    int n, x;
    cin >> n >> x;
    int i;
    wfor(i, 0, n)
    {
        cin >> num[i].l >> num[i].r;
    }
    int ans = 0;
    int now = 1;
    wfor(i, 0, n)
    {
        while (num[i].l >= now + x)
            now += x;
        ans += num[i].r - now + 1;
        now = num[i].r + 1;
    }
    cout << ans << endl;
    return 0;
}
