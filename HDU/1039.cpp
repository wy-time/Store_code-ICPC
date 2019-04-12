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
char ma[200];
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
    string s;
    ma['a'] = 1;
    ma['e'] = 1;
    ma['i'] = 1;
    ma['o'] = 1;
    ma['u'] = 1;
    while (cin >> s)
    {
        if (s == "end")
            break;
        int len = s.size();
        int rule1 = 0, rule2 = 1, rule3 = 1, rule4 = 1;
        int cnt1 = 0, cnt2 = 0;
        int i;
        char last = '-';
        wfor(i, 0, len)
        {
            if (last == s[i])
            {
                if (last != 'e' && last != 'o')
                {
                    rule4 = 0;
                    break;
                }
            }
            if (ma[s[i]] == 1)
            {
                cnt2 = 0;
                rule1 = 1;
                cnt1++;
                if (cnt1 >= 3)
                {
                    rule2 = 0;
                    break;
                }
            } else
            {
                cnt1 = 0;
                cnt2++;
                if (cnt2 >= 3)
                {
                    rule3 = 0;
                    break;
                }
            }
            last = s[i];
        }
        if (rule1 && rule2 && rule3 && rule4)
        {
            cout << "<" << s << ">" << " is acceptable." << endl;
        } else
            cout << "<" << s << ">" << " is not acceptable." << endl;
    }
    return 0;
}
