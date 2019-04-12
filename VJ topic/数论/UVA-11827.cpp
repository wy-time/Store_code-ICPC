#include <iostream>
#include <string>
#include <sstream>
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
const int maxn = 200;
int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x % y);
}
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
    int n;
    stringstream ssin;
    cin >> n;
    string s;
    getline(cin, s);
    while (n--)
    {
        ssin.clear();
        int i;
        int m = 0;
        getline(cin, s);
        ssin << s;
        while (ssin >> num[m++]);
        m--;
        int j;
        int ans = 0;
        wfor(i, 0, m)
        {
            wfor(j, i + 1, m)
            {
                ans = max(ans, gcd(num[i], num[j]));
            }
        }
        cout << ans << endl;
    }
    return 0;
}
