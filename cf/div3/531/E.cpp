#include <iostream>
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
const int maxn = 2e5 + 5;
const int mod = 998244353;
int num[maxn];
int temp[maxn];
struct st
{
    int l;
    int r;
    int flag;
    st()
    {
        l = 1e9;
        flag = 0;
        r = -1;
    }
};
st ans[maxn];
struct rule
{
    bool operator()(const st &a, const st &b)
    {
        return a.l == b.l ? a.r > b.r : a.l < b.l;
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
        cin >> num[i];
        temp[i] = num[i];
    }
    sort(temp, temp + n);
    unique(temp, temp + n);
    ll res = 1;
    int cnt = 0;
    wfor(i, 0, n)
    {
        num[i] = lower_bound(temp, temp + n, num[i]) - temp;
        if (ans[num[i]].flag == 0)
        {
            ans[num[i]].l = i + 1;
            ans[num[i]].flag = 1;
            cnt++;
        }
        ans[num[i]].r = i + 1;
    }
    sort(ans, ans + n, rule());
    int last_l = ans[0].l;
    int last_r = ans[0].r;
    wfor(i, 1, cnt)
    {
        int l = max(last_l, ans[i].l);
        int r = min(last_r, ans[i].r);
        if (l <= r)
        {
            last_l = min(last_l, ans[i].l);
            last_r = max(ans[i].r, last_r);
        } else
        {
            res = res * 2 % mod;
            last_l = ans[i].l;
            last_r = ans[i].r;
        }
    }
    cout << res << endl;
    return 0;
}
