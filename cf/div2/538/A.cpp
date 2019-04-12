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
    int x, y, z;
    int a, b, c;
    cin >> x >> y >> z;
    cin >> a >> b >> c;
    int flag = 1;
    if (a < x)
        flag = 0;
    a = a - x > 0 ? a - x : 0;
    if (a + b < y)
        flag = 0;
    int ab = a + b - y > 0 ? b + a - y : 0;
    if (c + ab < z)
        flag = 0;
    if (flag == 0)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}
