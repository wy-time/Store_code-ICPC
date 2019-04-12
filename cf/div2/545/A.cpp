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
const int maxn = 1e5 + 5;
int num[maxn];
int ans[maxn];
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
    wfor(i, 0, n)
    {
        cin >> num[i];
    }
    int one = 0;
    int two = 0;
    int flag1 = 0;
    int flag2 = 0;
    int ans = 0;
    wfor(i, 0, n)
    {
        if (num[i] == 1)
        {
            flag2 = 1;
            if (flag1 == 1)
            {
                one = 0;
                flag1 = 0;
            }
            one++;
        } else
        {
            flag1 = 1;
            if (flag2 == 1)
            {
                two = 0;
                flag2 = 0;
            }
            two++;
        }
        int tans = min(two, one) * 2;
        ans = max(ans, tans);
    }
    cout << ans << endl;
    return 0;
}
