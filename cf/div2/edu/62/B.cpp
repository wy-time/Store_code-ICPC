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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        if (s[0] == '>' || s[n - 1] == '<')
            ans = 0;
        else if (s[0] == '<' && s[n - 1] == '>')
        {
            int num = 1;
            int i;
            wfor(i, 1, n)
            {
                if (s[i] == '>')
                    break;
                num++;
            }
            int temp = 1;
            mfor(i, n - 2, 0)
            {
                if (s[i] == '<')
                    break;
                temp++;
            }
            ans = min(temp, num);
        }
        cout << ans << endl;
    }
    return 0;
}
