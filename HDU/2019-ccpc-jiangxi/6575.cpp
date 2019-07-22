#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
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
const int maxn = 1005;
double num[maxn];
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
    while (cin >> n)
    {
        int i;
        ll ans = 0;
        wfor(i, 0, n)
        {
            string s;
            cin >> s;
            int pos = s.find('.');
            if (s[pos + 3] - '0' >= 5)
                ans += 10 - (s[pos + 3] - '0');
            else
                ans -= s[pos + 3] - '0';
        }
        int num[20] = {0};
        int cnt = 0;
        int flag = 0;
        if (ans < 0)
        {
            flag = 1;
            ans *= -1;
        }
        while (ans)
        {
            num[cnt++] = ans % 10;
            ans /= 10;
        }
        if (cnt < 4)
            cnt = 4;
        reverse(num, num + cnt);
        if (flag)
            cout << '-';
        wfor(i, 0, cnt)
        {
            if (cnt - i == 3)
                cout << '.';
            cout << num[i];
        }
        cout << endl;
    }
    return 0;
}
