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
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    int flag = 0;
    if (a3 >= 1)
    {
        if (a1 == a4 && a1 >= 1)
            flag = 1;
    } else
    {
        if (a1 == a4)
            flag = 1;
    }
    if (flag == 1)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}
