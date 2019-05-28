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
int num[maxn];
int _beg[maxn];
int _end[maxn];
int L[maxn];
int R[maxn];
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
    fill(_beg, _beg + x + 2, 10000000);
    fill(R, R + x + 2, 10000000);
    wfor(i, 0, n)
    {
        cin >> num[i];
        _beg[num[i]] = min(_beg[num[i]], i);
        _end[num[i]] = i;
    }
    wfor(i, 1, x + 1)
    {
        L[i] = max(L[i - 1], _end[i]);
    }
    mfor(i, x, 1)
    {
        R[i] = min(R[i + 1], _beg[i]);
    }
    int l = 0, r = 0;
    r = x;
    ll ans = 0;
    while (R[r + 1] >= _end[r] && r > 1)r--;
    wfor(l, 1, x + 1)
    {
        if (l != 1 && _beg[l - 1] < L[l - 2])break;
        while (r < l || L[l - 1] > R[r + 1])
            r++;
        ans += x - r + 1;
    }
    cout << ans << endl;
    return 0;
}
