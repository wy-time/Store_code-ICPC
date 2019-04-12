#include <iostream>
#include <cmath>
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
ll _pow[30];
void init()
{
    _pow[0] = 1;
    int i;
    wfor(i, 1, 30)
    {
        _pow[i] = _pow[i - 1] * 2;
    }
}
ll ddiv[80] = {3, 7, 3, 31, 3, 127, 3, 7, 3, 23, 3, 8191, 3, 7, 3, 131071, 3, 524287, 3, 7, 3, 47, 3, 31, 3, 7, 3, 233, 3, 2147483647ll, 3, 7, 3, 31, 3, 223, 3, 7, 3, 13367, 3, 431, 3, 7, 3, 2351, 3, 127, 3, 7, 3, 6361, 3, 23, 3, 7, 3, 179951, 3, 2305843009213693951ll, 3, 7, 3, 31};
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
    int q;
    cin >> q;
    init();
    while (q--)
    {
        ll a;
        cin >> a;
        ll t = log2(a);
        if (a != _pow[t + 1] - 1)
        {
            cout << _pow[t + 1] - 1 << endl;
        } else
            cout << a / ddiv[t - 1] << endl;
    }
    return 0;
}
