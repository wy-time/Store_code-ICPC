#include <iostream>
#include <unordered_map>
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
int num[maxn];
int org[maxn];
int pos[maxn];
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
    int n, m, k;
    cin >> n >> m >> k;
    int i;
    wfor(i, 0, n)
    {
        cin >> num[i];
        org[i] = num[i];
    }
    sort(num, num + n, greater<int>());
    unordered_map <int, int>ma;
    ll ans = 0;
    wfor(i, 0, m * k)
    {
        if (ma.count(num[i]) == 0)
            ma.insert(make_pair(num[i], 1));
        else
            ma[num[i]]++;
        ans += num[i];
    }
    int cnt = 0;
    int cnt2 = 0;
    wfor(i, 0, n)
    {
        if (ma.count(org[i]) != 0)
        {
            if (ma[org[i]] != 0)
            {
                cnt++;
                ma[org[i]]--;
            }
        }
        if (cnt == m)
        {
            pos[cnt2++] = i + 1;
            cnt = 0;
        }
        if (cnt2 == k - 1)
            break;
    }
    cout << ans << endl;
    wfor(i, 0, cnt2 - 1)
    {
        cout << pos[i] << " ";
    }
    cout << pos[i] << endl;
    return 0;
}
