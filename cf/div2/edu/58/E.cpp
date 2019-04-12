#include <iostream>
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
    int i;
    int l = 0, r = 0;
    wfor(i, 0, n)
    {
        char ch;
        int a, b;
        cin >> ch >> a >> b;
        if (a > b)
            swap(a, b);
        if (ch == '+')
        {
            l = max(a, l);
            r = max(b, r);
        } else
        {
            if (a >= l && b >= r)
                cout << "YES" << endl;
            else
                cout << "No" << endl;
        }

    }
    return 0;
}
