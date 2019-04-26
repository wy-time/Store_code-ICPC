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
const int maxn = 1e5 + 5;
int ans[maxn];
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
    wfor(i, 1, k + 1)
    {
        ans[i] = i;
        n -= i;
    }
    int te = n / k;
    if (te > 0)
    {
        wfor(i, 1, k + 1)
        {
            ans[i] += te;
        }
    }
    if (n > 0)
    {
        n %= k;
        mfor(i, k , 1)
        {
            int j;
            wfor(j, i, k + 1)
            {
                if (i != 1)
                {
                    if (n >= ans[i - 1] * 2 - ans[i])
                    {
                        n -= ans[i - 1] * 2 - ans[i];
                        ans[i] = ans[i - 1] * 2;
                    } else
                    {
                        ans[i] += n;
                        n = 0;
                    }
                } else
                {
                    if (n >= ans[i + 1] - 1 - ans[i])
                    {
                        n -= ans[i + 1] - 1 - ans[i];
                        ans[i] = ans[i + 1] - 1;
                    } else
                    {
                        ans[i] += n;
                        n = 0;
                    }
                }
            }
            if (n == 0)
            {
                break;
            }
        }
    }
    if (n == 0)
    {
        cout << "YES" << endl;
        wfor(i, 1, k + 1)
        {
            cout << ans[i] << " ";
        }
    } else
    {
        cout << "NO" << endl;
    }
    return 0;
}
