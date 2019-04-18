#include <iostream>
#include <algorithm>
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
    int num[4] = {0};
    int i;
    wfor(i, 0, 4)
    {
        cin >> num[i];
    }
    sort(num, num + 4, greater<int>());
    int maxnum = num[0];
    int a = 0, b = 0, c = 0;
    a = maxnum - num[1];
    b = maxnum - num[2];
    c = maxnum - num[3];
    cout << a << " " << b << " " << c << " " << endl;
    return 0;
}
