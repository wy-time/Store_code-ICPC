#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//     char ch = getchar(); x = 0;
//     for (; ch < '0' || ch > '9'; ch = getchar());
//     for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
int ans[105][105];
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
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int i, j;
        wfor(i, 0, n)
        {
            int beg = 0;
            if (i % 2 != 0)
                beg = 1;
            wfor(j, 0, m)
            {
                ans[i][j] = beg;
                beg ^= 1;
            }
        }
        if (n % 2 == 0 && m % 2 == 0)
            ans[n - 1][m - 2] = 0;
        else if (n % 2 == 0 && m % 2 != 0)
            ans[n - 1][m - 1] = 0;
        else if (n % 2 != 0 && m % 2 == 0)
            ans[n - 1][m - 1] = 0;
        wfor(i, 0, n)
        {
            wfor(j, 0, m)
            {
                if (ans[i][j] == 0)
                    cout << "B";
                else
                    cout << "W";
            }
            cout << endl;
        }
    }
    return 0;
}
