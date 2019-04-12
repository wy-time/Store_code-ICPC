#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
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
#ifdef test
    freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
#ifdef ubuntu
    freopen("/home/time/debug/debug/in", "r", stdin);
    freopen("/home/time/debug/debug/out", "w", stdout);
#endif
    int n;
    cin >> n;
    double d;
    cin >> d;
    int id;
    stringstream ss;
    while (cin >> id)
    {
        int h = 0, m = 0, s = 0;
        int i;
        int flag = 1;
        string str;
        char ch;
        wfor(i, 0, n)
        {
            ss.clear();
            cin >> str;
            if (str[0] == '-')
                flag = 0;
            else
            {
                int t;
                ss << str;
                ss >> t >> ch;
                h += t;
                ss >> t >> ch;
                m += t;
                ss >> t;
                s += t;
            }
        }
        s = h * 60 * 60 + m * 60 + s;
        double ans = s / d;
        int ansf = floor(ans / 60);
        ans -= ansf * 60;
        ans = round(ans);
        if (ans == 60)
        {
            ansf++;
            ans = 0;
        }
        if (flag == 1)
            printf("%3d: %d:%02d min/km\n", id, ansf, (int)ans);
        else
            printf("%3d: -\n", id);
    }
    return 0;
}
