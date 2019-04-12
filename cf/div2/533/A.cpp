#include <iostream>
#include <cmath>
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
const int maxn = 1005;
int num[maxn];
const int INF = 1e9;
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
    }
    int ans = INF;
    int aim = 1;
    wfor(i, 1, 101)
    {
        int j;
        int temp = 0;
        wfor(j, 0, n)
        {
            temp += min(abs(i - 1 - num[j]), min(abs(i - num[j]), abs(i + 1 - num[j])));
        }
        if (ans > temp)
        {
            ans = temp;
            aim = i;
        }
    }
    cout << aim << " " << ans << endl;
    return 0;
}
