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
const int maxn = 505;
char ma[maxn][maxn];
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
    int i, j;
    wfor(i, 0, n)
    {
        wfor(j, 0, n)
        {
            cin >> ma[i][j];
        }
    }
    int ans = 0;
    wfor(i, 0, n)
    {
        wfor(j, 0, n)
        {
            if (ma[i][j] == 'X')
            {
                if (i - 1 >= 0 && j - 1 >= 0 && i + 1 < n && j + 1 < n && ma[i - 1][j - 1] == 'X' && ma[i - 1][j + 1] == 'X' && ma[i + 1][j - 1] == 'X' && ma[i + 1][j + 1] == 'X')
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
