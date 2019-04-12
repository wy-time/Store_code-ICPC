#include <iostream>
#include <cstring>
#include <algorithm>
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
const int maxn = 3e5 + 5;
const int INF = 1e9;
struct st
{
    int l;
    int r;
    int id;
    st()
    {
        l = INF;
        r = 0;
    }
};
st num[maxn];
st num2[maxn];
struct rule1
{
    bool operator()(const st &a, const st &b)
    {
        return a.l < b.l;
    }
};
struct rule2
{
    bool operator()(const st &a, const st &b)
    {
        return a.r > b.r;
    }
};
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
    cin >> n;
    int i;
    wfor(i, 0, n)
    {
        int t;
        cin >> t;
        if (num[t].l > i)
            num[t].l = i;
        if (num[t].r < i)
            num[t].r = i;
        num[t].id = t;
    }
    memcpy(num2, num, sizeof(num));
    sort(num, num + n + 1, rule1());
    sort(num2, num2 + n + 1, rule2());
    int ans = 0;
    wfor(i, 0, n)
    {
        if (num[i].id != num2[0].id)
            ans = max(ans, num2[0].r - num[i].l);
        else
            ans = max(ans, num2[1].r - num[i].l);
    }
    cout << ans << endl;
    return 0;
}
