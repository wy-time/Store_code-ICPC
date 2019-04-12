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
    string s;
    cin >> s;
    int len = s.size();
    int ans = 4;
    int i;
    int pos1 = -1;
    int pos2 = -1;
    int left = 0;
    int right = 0;
    wfor(i, 0, len)
    {
        if (!left)
        {
            if (s[i] == '[')
                left = 1;
        } else if (s[i] == ':')
        {
            pos1 = i;
            break;
        }
    }
    mfor(i, len - 1, 0)
    {
        if (!right)
        {
            if (s[i] == ']')
                right = 1;
        } else if (s[i] == ':')
        {
            pos2 = i;
            break;
        }
    }
    if (pos1 == -1 || pos2 == -1 || pos1 >= pos2)
    {
        ans = -1;
    } else
    {
        wfor(i, pos1 + 1, pos2)
        {
            if (s[i] == '|')
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
