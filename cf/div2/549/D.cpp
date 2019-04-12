#include <iostream>
#include <set>
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
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
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
    ll n, k;
    cin >> n >> k;
    n *= k;
    ll a, b;
    cin >> a >> b;
    set<ll>st;
    ll cnt = 0;
    if (a < b)
        swap(a, b);
    while (1)
    {
        ll temp = cnt * k + a - b;
        temp %= n;
        if (st.count(temp))
            break;
        st.insert(temp);
        temp = n - temp;
        st.insert(temp);
        if (a + b != a - b)
        {
            temp = cnt * k + a + b;
            temp %= n;
            if (st.count(temp))
                break;
            st.insert(temp);
            temp = n - temp;
            st.insert(temp);
        }
        cnt++;
    }
    ll mina = 1e18, maxa = 0;
    for (auto it : st)
    {
        if (it == 0)continue;
        //ll x,y;
        //exgcd(it,n,x,y);
        ll x = n / gcd(it, n);
        mina = min(mina, x);
        maxa = max(maxa, x);
    }
    cout << mina << " " << maxa << endl;
    return 0;
}
