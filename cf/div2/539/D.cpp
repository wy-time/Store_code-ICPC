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
int ishuiwen(string s)
{
    int len = s.size();
    int i;
    int flag = 1;
    wfor(i, 0, len / 2)
    {
        if (s[i] != s[len - 1 - i])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
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
    cin >> s;
    int len = s.size();
    int flag = 1;
    int ans = 0;
    if (len % 2 == 1)
    {
        string temp = s.substr(0, len / 2);
        int cnt = count(temp.begin(), temp.end(), temp[0]);
        if (cnt == temp.size())
        {
            flag = 0;
        } else
            ans = 2;
    } else
    {
        int cnt = count(s.begin(), s.end(), s[0]);
        if (cnt == len)
            flag = 0;
        else
        {
            ans = 2;
            int i;
            wfor(i, 1, len)
            {
                string temp = s.substr(0, i);
                temp = s.substr(i) + temp;
                if (ishuiwen(temp))
                {
                    if (temp == s);
                    else
                        ans = 1;
                }
            }
        }
    }
    if (flag)
        cout << ans << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}
