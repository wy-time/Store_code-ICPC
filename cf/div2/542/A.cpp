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
    int post = 0;
    int neg = 0;
    wfor(i, 0, n)
    {
        int t;
        cin >> t;
        if (t > 0)
        {
            post++;
        } else if (t < 0)
        {
            neg++;
        }
    }
    int need = n % 2 == 0 ? n / 2 : n / 2 + 1;
    if (post >= need)
        cout << 1 << endl;
    else if (neg >= need)
        cout << -1 << endl;
    else
        cout << 0 << endl;
    return 0;
}
