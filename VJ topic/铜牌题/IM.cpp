#include <iostream>
#include <string>
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
    while (n--)
    {
        string s;
        cin >> s;
        int len = s.size();
        int i;
        ll ans = 0;
        wfor(i, 0, len)
        {
            if (s[i] == 'H')
                ans += 1;
            else if (s[i] == 'C')
                ans += 12;
            else
                ans += 16;
        }
        cout << ans << endl;
    }
    return 0;
}
