#include <iostream>
#include <queue>
#include <set>
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
const int maxn = 105;
int num[maxn];
int id[maxn];
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
    }
    priority_queue<int>qu[maxn];
    wfor(i, 0, n)
    {
        cin >> id[i];
        qu[id[i]].push(num[i]);
    }
    int ans = 0;
    wfor(i, 0, k)
    {
        int temp;
        cin >> temp;
        int pos = temp - 1;
        if (qu[id[pos]].top() != num[pos])
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
