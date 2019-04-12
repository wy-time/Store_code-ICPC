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
const int maxn = 2e5 + 5;
int num[maxn];
int sumodd[maxn];
int sumeven[maxn];
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
    sumodd[0] = num[0];
    sumeven[0] = num[1];
    wfor(i, 2, n)
    {
        if (i % 2 == 0)
            sumodd[i / 2] = sumodd[i / 2 - 1] + num[i];
        else
            sumeven[i / 2] = sumeven[i / 2 - 1] + num[i];
    }
    int ans = 0;
    wfor(i, 0, n)
    {
        int t1 = 0;
        int t2 = 0;
        if (i % 2 == 0)
        {
            if (i / 2 - 1 >= 0)
            {
                t1 += sumodd[i / 2 - 1];
                t2 += sumeven[i / 2 - 1];
                t1 += sumeven[n / 2 - 1] - sumeven[i / 2 - 1];
                t2 += sumodd[n / 2 - 1 + n % 2] - sumodd[i / 2 - 1] - num[i];
            } else
            {
                t1 += sumeven[n / 2 - 1];
                t2 += sumodd[n / 2] - num[i];
            }
        } else
        {
            t1 += sumodd[i / 2];
            if (i / 2 - 1 >= 0)
            {
                t2 += sumeven[i / 2 - 1];
                t1 += sumeven[n / 2 - 1] - sumeven[i / 2 - 1] - num[i];
            } else
                t1 += sumeven[n / 2 - 1] - num[i];
            t2 += sumodd[n / 2 - 1 + n % 2] - sumodd[i / 2];
        }
        if (t1 == t2)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
