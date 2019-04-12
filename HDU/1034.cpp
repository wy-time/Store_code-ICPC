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
const int INF = 1e9;
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
    int n = 1;
    while (cin >> n && n)
    {
        int maxnum = 0;
        int minnum = INF;
        int i;
        wfor(i, 0, n)
        {
            cin >> num[i];
        }
        int cnt = 0;
        while (maxnum != minnum)
        {
            maxnum = 0;
            minnum = INF;
            cnt++;
            int last = num[n - 1] / 2;
            wfor(i, 0, n)
            {
                int t = num[i];
                num[i] /= 2;
                num[i] += last;
                if (num[i] % 2 != 0)
                    num[i]++;
                last = t / 2;
                maxnum = max(num[i], maxnum);
                minnum = min(num[i], minnum);
            }
        }
        cout << cnt << " " << num[0] << endl;
    }
    return 0;
}
