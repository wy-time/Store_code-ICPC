#include <iostream>
#include <cstring>
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
const ll maxn = 100005;
const ll mod = 10007;
ll tree[maxn << 2][3];
ll mul[maxn << 2];
ll add[maxn << 2];
ll chan[maxn << 2];
void push_up(ll id)
{
    tree[id][0] = tree[id << 1][0] + tree[id << 1 | 1][0];
    tree[id][1] = tree[id << 1][1] + tree[id << 1 | 1][1];
    tree[id][2] = tree[id << 1][2] + tree[id << 1 | 1][2];
    tree[id][0] %= mod;
    tree[id][1] %= mod;
    tree[id][2] %= mod;
}
void add_proc(ll id, ll number, ll t)
{
    tree[id][2] += t * number % mod * number % mod * number % mod;
    tree[id][2] %= mod;
    tree[id][2] += 3 * tree[id][1] % mod * number % mod;
    tree[id][2] %= mod;
    tree[id][2] += 3 * tree[id][0] % mod * number % mod * number % mod;
    tree[id][1] += t * number % mod * number % mod;
    tree[id][1] %= mod;
    tree[id][1] += 2 * number * tree[id][0] % mod;
    tree[id][0] += t * number % mod;
    tree[id][0] %= mod;
    tree[id][1] %= mod;
    tree[id][2] %= mod;
}
void chan_proc(ll id, ll number, ll t)
{
    tree[id][0] = number * t % mod;
    tree[id][1] = t * number % mod * number % mod;
    tree[id][2] = t * number % mod * number % mod * number % mod;
}
void push_down(ll ln, ll rn, ll id)
{

    if (mul[id])
    {
        tree[id << 1][0] = tree[id << 1][0] * mul[id] % mod;
        tree[id << 1 | 1][0] = tree[id << 1 | 1][0] * mul[id] % mod;
        tree[id << 1][1] = tree[id << 1][1] * mul[id] % mod * mul[id] % mod;
        tree[id << 1 | 1][1] = tree[id << 1 | 1][1] * mul[id] % mod * mul[id] % mod;
        tree[id << 1][2] = tree[id << 1][2] * mul[id] % mod * mul[id] % mod * mul[id] % mod;
        tree[id << 1 | 1][2] = tree[id << 1 | 1][2] * mul[id] % mod * mul[id] % mod * mul[id] % mod;
        mul[id << 1] = mul[id << 1 | 1] = mul[id];
        mul[id] = 0;
    }
    if (add[id])
    {
        add_proc(id << 1, add[id], ln);
        add_proc(id << 1 | 1, add[id], rn);
        add[id << 1] = add[id << 1 | 1] = add[id];
        add[id] = 0;
    }
    if (chan[id])
    {
        chan_proc(id << 1, chan[id], ln);
        chan_proc(id << 1 | 1, chan[id], rn);
        chan[id << 1] = chan[id << 1 | 1] = chan[id];
        chan[id] = 0;
    }
}
void updata(ll l, ll r, ll L, ll R, ll id, ll op, ll number)
{
    if (l >= L && r <= R)
    {
        if (op == 1)
        {
            add_proc(id, number, r - l + 1);
            add[id] = number;
        } else if (op == 2)
        {
            tree[id][0] *= number;
            tree[id][1] *= number * number % mod;
            tree[id][2] *= number * number % mod * number % mod;
            tree[id][0] %= mod;
            tree[id][1] %= mod;
            tree[id][2] %= mod;
            add[id] *= number;
            add[id] %= mod;
            mul[id] = number;
        } else if (op == 3)
        {
            chan_proc(id, number, r - l + 1);
            mul[id] = 0;
            add[id] = 0;
            chan[id] = number;
        }
        return ;
    }
    ll mid = (l + r) >> 1;
    push_down(mid - l + 1, r - mid, id);
    if (mid >= L)
        updata(l, mid, L, R, id << 1, op, number);
    if (mid < R)
        updata(mid + 1, r, L, R, id << 1 | 1, op, number);
    push_up(id);
}
ll query(ll l, ll r, ll L, ll R, ll id, ll p)
{
    if (l >= L && r <= R)
    {
        return tree[id][p];
    }
    ll mid = (l + r) >> 1;
    push_down(mid - l + 1, r - mid, id);
    ll ans = 0;
    if (mid >= L)
        ans = (ans + query(l, mid, L, R, id << 1, p)) % mod;
    if (mid < R)
        ans = (ans + query(mid + 1, r, L, R, id << 1 | 1, p)) % mod;
    return ans;
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
    ll n, m;
    while (cin >> n >> m)
    {
        if (m == 0 && n == 0)
            break;
        memset(tree, 0, sizeof(tree));
        memset(add, 0, sizeof(add));
        memset(mul, 0, sizeof(mul));
        memset(chan, 0, sizeof(chan));
        ll i;
        wfor(i, 0, m)
        {
            ll op, l, r, c;
            cin >> op >> l >> r >> c;
            if (op != 4)
            {
                updata(1, n, l, r, 1, op, c % mod);
            } else
            {
                ll ans = query(1, n, l, r, 1, c - 1);
                cout << ans % mod << endl;
            }
        }
    }
    return 0;
}
