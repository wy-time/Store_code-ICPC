#include <iostream>
#include <cmath>
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
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        int len = s.size();
        int i;
        string rest = "";
        string ans = "";
        ans += s[0];
        wfor(i, 1, len)
        {
            if (s[i] - * (ans.end() - 1) != 1)
                ans += s[i];
            else if (s[i] - * (ans.begin()) != 1)
                ans = s[i] + ans;
            else
                rest += s[i];
        }
        len = rest.size();
        wfor(i, 0, len)
        {
            if (abs(rest[i] - * (ans.end() - 1)) != 1)
                ans += rest[i];
            else if (abs(rest[i] - * (ans.begin())) != 1)
                ans = rest[i] + ans;
            else
            {
                break;
            }
        }
        if (ans.size() != s.size())
            cout << "No answer" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
