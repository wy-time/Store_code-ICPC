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
#ifdef test
    freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
#ifdef ubuntu
    freopen("/home/time/debug/debug/in", "r", stdin);
    freopen("/home/time/debug/debug/out", "w", stdout);
#endif
    int h1, m1, h2, m2;
    char c;
    cin >> h1 >> c >> m1;
    cin >> h2 >> c >> m2;
    if (h1 > h2)
    {
        swap(h1, h2);
        swap(m1, m2);
    } else if (h1 == h2)
    {
        if (m1 > m2)
        {
            swap(h1, h2);
            swap(m1, m2);
        }
    }
    int min1 = h1 * 60 + m1;
    int min2 = h2 * 60 + m2;
    int ans = min1 + (min2 - min1) / 2;
    int h3 = ans / 60;
    int m3 = ans % 60;
    printf("%02d:%02d\n", h3, m3);
    return 0;
}
