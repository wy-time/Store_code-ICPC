#include <iostream>
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
    int i;
    int ans[105] = {0};
    ans[0] = 1;
    wfor(i, 1, 101)
    {
        ans[i] = ans[i - 1] * i;
        while (ans[i] % 10 == 0)
        {
            ans[i] /= 10;
        }
        ans[i] = ans[i] % 10000;
    }
    int n;
    cin >> n;
    cout << ans[n] % 10 << endl;
    return 0;
}
