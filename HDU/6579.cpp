#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define rep2(i,a,b) for(ll i=a;i>=b;i--)
using namespace std;
typedef long long ll;
const ll maxn = 500010;
ll p[maxn][32], pos[maxn][32];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ll N, Q, L, R, x;
        scanf("%lld%lld", &N, &Q);
        rep(i, 1, N) {
            rep(j, 0, 31) p[i][j] = p[i - 1][j], pos[i][j] = pos[i - 1][j];
            scanf("%lld", &x); ll ti = i;
            rep2(j, 31, 0) {
                if (x & (1ll << j)) {
                    if (!p[i][j]) { p[i][j] = x; pos[i][j] = ti; break; }
                    if (pos[i][j] < ti) swap(p[i][j], x), swap(pos[i][j], ti);
                    x ^= p[i][j];
                }
            }
        }
        ll last = 0;
        rep(q, 1, Q) {
            ll res = 0;
            int op;
            scanf("%d", &op);
            if (op == 0)
            {
                scanf("%lld%lld", &L, &R);
                L = (L ^ last) % N + 1;
                R = (R ^ last) % N + 1;
                if (L > R)
                    swap(L, R);
                rep2(j, 31, 0) if (pos[R][j] >= L && (res ^ p[R][j]) > res) res ^= p[R][j];
                printf("%lld\n", res);
                last = res;
            } else
            {
                int i = N + 1;
                rep(j, 0, 31) p[i][j] = p[i - 1][j], pos[i][j] = pos[i - 1][j];
                scanf("%lld", &x); ll ti = i;
                x ^= last;
                rep2(j, 31, 0) {
                    if (x & (1ll << j)) {
                        if (!p[i][j]) { p[i][j] = x; pos[i][j] = ti; break; }
                        if (pos[i][j] < ti) swap(p[i][j], x), swap(pos[i][j], ti);
                        x ^= p[i][j];
                    }
                }
                N++;
            }
        }
    }
    return 0;
}