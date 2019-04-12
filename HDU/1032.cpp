#include <iostream>
#include <algorithm>
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
const int maxn = 1e6 + 5;
int num[maxn];
ll temp[maxn];
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
    int i;
    num[1] = 1;
    wfor(i, 2, maxn)
    {
        if (num[i] == 0)
        {
            ll n = i;
            int cnt = 0;
            while (n != 1)
            {
                temp[cnt] = n;
                if (n < maxn && num[n] != 0)
                {
                    break;
                }
                if (n % 2 == 0)
                    n /= 2;
                else
                    n = n * 3 + 1;
                cnt++;
            }
            int j;
            wfor(j, 0, cnt)
            {
                if (temp[j] < maxn)
                    num[temp[j]] = cnt - j + num[n];
            }
        }
    }
    int l, r;
    while (cin >> l >> r)
    {
        int flag = 0;
        if (l > r)
        {
            swap(l, r);
            flag = 1;
        }
        int ans = *max_element(num + l, num + r + 1);
        if (flag == 1)
            swap(l, r);
        cout << l << " " << r << " " << ans << endl;
    }
    return 0;
}
