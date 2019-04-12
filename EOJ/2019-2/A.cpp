#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
//  char ch = getchar(); x = 0;
//  for (; ch < '0' || ch > '9'; ch = getchar());
//  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
void solve(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll &x, ll &y) {
    ll a, b, c, d, e, f;
    a = 2 * (x2 - x1);
    b = 2 * (y2 - y1);
    c = x2 * x2 + y2 * y2 - x1 * x1 - y1 * y1;
    d = 2 * (x3 - x2);
    e = 2 * (y3 - y2);
    f = x3 * x3 + y3 * y3 - x2 * x2 - y2 * y2;
    x = (b * f - e * c) / (b * d - e * a);
    y = (d * c - a * f) / (b * d - e * a);
}
int main()
{
    ll x = 1;
    ll sta = 1;;
    ll l = 0, r = 2e9 + 1;
    while (l <= r)
    {
        ll mid = (l + r) >> 1;
        cout << 0 << " " << mid << " " << 0 << " " << 0 << endl;
        cin >> sta;
        if (sta == 1)
            l = mid + 1;
        else
            r = mid - 1;
    }
    x = r;
    ll x2 = -1;
    l = 0, r = -2e9 + 1;
    sta = 1;
    while (l >= r)
    {
        ll mid = (l + r) >> 1;
        cout << 0 << " " << mid << " " << 0 << " " << 0 << endl;
        cin >> sta;
        if (sta == 1)
            l = mid - 1;
        else
            r = mid + 1;
    }
    x2 = r;
    ll y = 1;
    sta = 1;
    l = 0, r = 2e9 + 1;
    while (l <= r)
    {
        ll mid = (l + r) >> 1;
        cout << 0 << " " << 0 << " " << mid << " " << 0 << endl;
        cin >> sta;
        if (sta == 1)
            l = mid + 1;
        else
            r = mid - 1;
    }
    y = r;
    ll y2 = -1;
    sta = 1;
    l = 0, r = -2e9 + 1;
    while (l >= r)
    {
        ll mid = (l + r) >> 1;
        cout << 0 << " " << 0 << " " << mid << " " << 0 << endl;
        cin >> sta;
        if (sta == 1)
            l = mid - 1;
        else
            r = mid + 1;
    }
    y2 = r;
    x = (x + x2) / 2;
    y = (y + y2) / 2;
    // solve(x, 0, x2, 0, 0, y, x, y);
    ll z1 = 1;
    sta = 1;
    l = 0, r = 2e9 + 1;
    while (l <= r)
    {
        ll mid = (l + r) >> 1;
        cout << 0 << " " << x << " " << y << " " << mid << endl;
        cin >> sta;
        if (sta == 1)
            l = mid + 1;
        else
            r = mid - 1;
    }
    z1 = r;
    ll z2 = -1;
    sta = 1;
    l = 0, r = -2e9 + 1;
    while (l >= r)
    {
        ll mid = (l + r) >> 1;
        cout << 0 << " " << x << " " << y << " " << mid << endl;
        cin >> sta;
        if (sta == 1)
            l = mid - 1;
        else
            r = mid + 1;
    }
    z2 = r;
    cout << 1 << " " << x << " " << y << " " << (z1 + z2) / 2 << endl;
    return 0;
}
