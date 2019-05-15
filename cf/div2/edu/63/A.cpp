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
    string s;
    cin >> s;
    int i;
    char last = s[0];
    int lastpos = 0;
    int flag = 0;
    wfor(i, 1, n)
    {
        if (s[i] > last)
        {
            last = s[i];
            lastpos = i;
        } else if (s[i] < last)
        {
            cout << "YES" << endl;
            cout << lastpos + 1 << " " << i + 1 << endl;
            flag = 1;
            break;
        }
    }
    if (flag != 1)
        cout << "NO" << endl;
    return 0;
}
