#include <iostream>
#include <algorithm>
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
const ll INF = 0x7f7f7f7f;
struct st
{
    ll id;
    ll num;
};
struct rule
{
    bool operator ()(const st &x, const st &y)
    {
        return x.num > y.num;
    }
};
st station[5005];
ll minnum[5005];
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
    ll i;
    fill(minnum, minnum + n + 1, INF);
    wfor(i, 0, m)
    {
        ll a, cad;
        cin >> a >> cad;
        station[a].num++;
        station[a].id = a;
        minnum[a] = min(minnum[a], cad - a >= 0 ? cad - a : n + cad - a);
    }
    sort(station, station + n + 1, rule());
    ll j;
    wfor(i, 1, n + 1)
    {
        ll ans = 0;
        ll num = station[0].num;
        ll lastst = station[0].id;
        ll lastcha = 0;
        ll maxnum = station[0].num;
        wfor(j, 0, n)
        {
            if (station[j].num == maxnum || (station[j].num == maxnum - 1 && station[j].num > 0))
            {
                ll cha = station[j].id - i >= 0 ? station[j].id - i : n + station[j].id - i;
                cha += minnum[station[j].id];
                if (station[j].num == station[0].num)
                    cha += n;
                if (cha > lastcha)
                {
                    lastcha = cha;
                    lastst = station[j].id;
                    num = station[j].num;
                }
            } else
                break;
        }
        lastcha = lastst - i >= 0 ? lastst - i : n + lastst - i;
        ll fix = minnum[lastst];
        ans = (num - 1) * n + fix + lastcha;
        cout << ans << " ";
    }
    return 0;
}

