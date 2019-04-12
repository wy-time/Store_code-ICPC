#include <iostream>
#include <queue>
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
const ll maxn = 1e5 + 5;
struct st
{
    ll id;
    ll cost;
    bool operator <(const st &b)const
    {
        return this->cost == b.cost ? this->id > b.id : this->cost > b.cost;
    }
    st() {}
    st(ll a, ll b)
    {
        id = a;
        cost = b;
    }
};
ll rem[maxn];
ll cost[maxn];
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
    ll all = 0;
    wfor(i, 0, n)
    {
        cin >> rem[i];
        all += rem[i];
    }
    priority_queue<st>qu;
    wfor(i, 0, n)
    {
        ll a;
        cin >> a;
        cost[i] = a;
        qu.push(st(i, a));
    }
    int flag = 0;
    wfor(i, 0, m)
    {
        ll id, num;
        cin >> id >> num;
        id--;
        ll ans = 0;
        if (flag == 0 && all >= num)
        {
            if (rem[id] >= num)
            {
                rem[id] -= num;
                ans += num * cost[id];
            } else
            {
                ans += rem[id] * cost[id];
                ll need = num - rem[id];
                rem[id] = 0;
                while (!qu.empty())
                {
                    if (need == 0)
                        break;
                    st temp = qu.top();
                    if (need <= rem[temp.id])
                    {
                        ans += need * temp.cost;
                        rem[temp.id] -= need;
                        need = 0;
                    } else
                    {
                        need -= rem[temp.id];
                        ans += rem[temp.id] * temp.cost;
                        rem[temp.id] = 0;
                    }
                    if (rem[temp.id] <= 0)
                    {
                        qu.pop();
                    }
                }
            }
            all -= num;
        } else
            flag = 1;
        cout << ans << endl;
    }
    return 0;
}
