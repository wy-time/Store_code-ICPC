#include <iostream>
#include <algorithm>
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
int ma[200];
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
    string s;
    cin >> s;
    char last = s[0];
    int cnt = 1;
    int ans = 0;
    wfor(i, 1, n)
    {
        if (last == s[i])
        {
            cnt++;
        } else
        {
            ma[last] += cnt / k;
            cnt = 1;
        }
        last = s[i];
    }
    ma[last] += cnt / k;
    wfor(i, 'a', 'z' + 1)
    {
        ans = max(ans, ma[i]);
    }
    cout << ans << endl;
    return 0;
}

