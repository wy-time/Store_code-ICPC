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
    int n;
    ll k;
    cin >> n >> k;
    ll can = k * (k - 1);
    if (can < n)
    {
        cout << "no" << endl;
    } else
    {
        cout << "yes" << endl;
        int i, j;
        int cnt = 0;
        wfor(i, 1, k + 1)
        {
            wfor(j, i + 1, k + 1)
            {
                if (cnt == n)
                {
                    return 0;
                } else
                {
                    cout << i << " " << j << endl;
                    cnt++;
                }
                if (cnt == n)
                {
                    return 0;
                } else
                {
                    cout << j << " " << i << endl;
                    cnt++;
                }
            }
        }
    }
    return 0;
}
