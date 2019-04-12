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
    freopen("F:\\Desktop\\question\\out.txt", "w", stdout);
#endif
#ifdef ubuntu
    //freopen("/home/time/debug/debug/in","r",stdin);
    // freopen("/home/time/debug/debug/out","w",stdout);
#endif
    string s;
    while (cin >> s)
    {
        if (s == "mistake" || s == "end")
            break;
        ll l = 0, r = 1;
        char statu;
        while (1)
        {
            cout << "? " << l << " " << r << endl;
            cin >> statu;
            if (statu == 'x')
                break;
            else
            {
                l = r;
                r = l * 2;
            }
        }
        while (l < r)
        {
            ll mid = (l + r) >> 1;
            if (mid == l)
                break;
            cout << "? " << l << " " << mid << endl;
            cin >> statu;
            if (statu == 'y')
            {
                l = mid;
            } else
                r = mid;
        }
        // cout << "? " << l << " " << r << endl;
        // cin >> statu;
        cout << "! " << max(l, r) << endl;
        // if (statu == 'x')
        //     cout << "! " << r << endl;
        // else
        //     cout << "! " << l << endl;
    }
    return 0;
}
