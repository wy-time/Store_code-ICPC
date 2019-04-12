#include <iostream>
#include <queue>
#include <string>
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
int cnt[27];
int num[maxn];
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
        cin >> num[i];
    }
    string s;
    ll ans = 0;
    cin >> s;
    int last = 26;
    priority_queue<int, vector<int>, greater<int>>qu;
    wfor(i, 0, n)
    {
        int t = s[i] - 'a';
        if (last == t)
        {
            if (cnt[t] >= k)
            {
                if (num[i] > qu.top())
                {
                    ans += num[i];
                    ans -= qu.top();
                    qu.pop();
                    qu.push(num[i]);
                }
            } else
            {
                cnt[t]++;
                ans += num[i];
                qu.push(num[i]);
            }
        } else
        {
            cnt[t] = 1;
            qu = priority_queue<int, vector<int>, greater<int>>();
            last = t;
            qu.push(num[i]);
            ans += num[i];
        }
    }
    cout << ans << endl;
    return 0;
}
