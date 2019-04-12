#include <iostream>
#include <unordered_map>
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
    unordered_map<int, int>ma;
    wfor(i, 0, n)
    {
        int t;
        cin >> t;
        t %= k;
        num[i] = t;
        if (ma.count(t) == 0)
            ma.insert(make_pair(t, 1));
        else
            ma[t]++;
    }
    int ans = 0;
    wfor(i, 0, n)
    {
        int temp = k - num[i];
        if (num[i] == 0)
            temp = 0;
        if ((temp != num[i] && ma[num[i]] > 0 && ma[temp] > 0) || (temp == num[i] && ma[temp] >= 2))
        {
            ma[num[i]]--;
            ma[temp]--;
            ans += 2;
        }
    }
    cout << ans << endl;
    return 0;
}
