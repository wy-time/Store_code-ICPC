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
    int flag1 = 0, flag2 = 0;
    int len = s.size();
    int i;
    wfor(i, 0, len)
    {
        if (s[i] == '0')
        {
            if (flag1 == 0)
            {
                flag1 = 1;
                cout << 3 << " " << 1 << endl;
            } else
            {
                cout << 1 << " " << 1 << endl;
                flag1 = 0;
            }
        } else
        {
            if (flag2 == 0)
            {
                flag2 = 1;
                cout << 1 << " " << 3 << endl;
            } else
            {
                flag2 = 0;
                cout << 1 << " " << 1 << endl;
            }
        }
    }
    return 0;
}
