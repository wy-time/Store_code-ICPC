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
ll ksm(int a, int b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % 2;
        a = a * a % 2;
        b >>= 1;
    }
    return ans;
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
    int b, k;
    cin >> b >> k;
    int i;
    int flag = 0;
    wfor(i, 0, k - 1)
    {
        int t;
        cin >> t;
        flag = (flag + t % 2 * b) % 2;
    }
    int t;
    cin >> t;
    flag += t;
    flag %= 2;
    if (flag == 0)
        cout << "even" << endl;
    else
        cout << "odd" << endl;
    return 0;
}
