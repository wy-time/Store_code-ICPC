#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//     char ch = getchar(); x = 0;
//     for (; ch < '0' || ch > '9'; ch = getchar());
//     for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
struct CAR
{
    int l;
    int s;
    int v;
    int id;
    double head_time;
    double tile_time;
    bool operator <(const CAR & other)const
    {
        return s < other.s;
    }
};
const int maxn = 1e5 + 5;
CAR car[maxn];
const double eps = 1e-9;
int euqal(double a, double b)
{
    if (fabs(a - b) < eps)
        return 1;
    else
        return 0;
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
    while (cin >> n)
    {
        int i;
        wfor(i, 0, n + 1)
        {
            cin >> car[i].l;
            car[i].id = i;
        }
        wfor(i, 0, n + 1)
        cin >> car[i].s;
        wfor(i, 0, n + 1)
        cin >> car[i].v;
        CAR tom = car[0];
        sort(car, car + 1 + n);
        ll sum = 0;
        wfor(i, 0, n + 1)
        {
            if (car[i].id != 0)
                sum += car[i].l;
            else
                break;
        }
        double need_time = 1.0 * tom.s / tom.v;
        wfor(i, 0, n + 1)
        {
            if (sum == 0)
                break;
            if (1.0 * (sum + car[i].s) / car[i].v < need_time || euqal(1.0 * (sum + car[i].s) / car[i].v, need_time))
            {
                sum -= car[i].l;
            } else
            {
                need_time = 1.0 * (sum + car[i].s) / car[i].v;
                sum -= car[i].l;
            }
        }
        cout << fixed << setprecision(10) << need_time << endl;
    }
    return 0;
}