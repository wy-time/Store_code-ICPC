#include <iostream>
#include <queue>
#include <deque>
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
struct st
{
    int len;
    int value;
};
st info[maxn];
struct rule
{
    bool operator()(const st &a, const st &b)
    {
        if (a.value == b.value)
            return a.len > b.len;
        else
            return a.value > b.value;
    }
};
struct rule2
{
    bool operator()(const st &a, const st &b)
    {
        return a.len > b.len;
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
    int n, k;
    cin >> n >> k;
    int i;
    wfor(i, 0, n)
    {
        cin >> info[i].len >> info[i].value;
    }
    sort(info, info + n, rule());
    priority_queue<st, vector<st>, rule2>qu;
    ll sum = 0;
    ll ans = 0;
    wfor(i, 0, n)
    {
        qu.push(info[i]);
        sum += info[i].len;
        ll temp = 1ll * info[i].value * sum;
        ans = max(temp, ans);
        if (qu.size() == k)
        {
            sum -= qu.top().len;
            qu.pop();
        }
    }
    cout << ans << endl;
    return 0;
}
