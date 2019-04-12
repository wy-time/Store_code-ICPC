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
const int maxn = 105;
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
    int e = 0, s = 0;;
    wfor(i, 1, n + 1)
    {
        cin >> num[i];
        if (num[i] == 1)
        {
            e++;
        } else
            s++;
    }
    int ans = 0;
    wfor(i, 1, n + 1)
    {
        int j;
        int t1 = 0, t2 = 0;
        wfor(j, -50, 50)
        {
            int pos = i + j * k;
            if (pos >= 1 && pos <= n)
            {
                if (num[pos] == 1)
                    t1++;
                else
                    t2++;
            } else if (pos > n)
                break;
        }
        ans = max(abs(e - t1 - s + t2), ans);
    }
    cout << ans << endl;
    return 0;
}
