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
int num[105];
int ans[105];
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
    sort(num, num + n);
    int t = 0;
    wfor(i, 0, n / 2)
    {
        ans[i] = num[t++];
        ans[n - 1 - i] = num[t++];
    }
    if (n % 2 != 0)
    {
        ans[i] = num[t];
    }
    wfor(i, 0, n - 1)
    {
        cout << ans[i] << " ";
    }
    cout << ans[i] << endl;
    return 0;
}
