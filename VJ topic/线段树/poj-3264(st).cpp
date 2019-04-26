#include <iostream>
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
int bit[32];
void init()
{
    int i;
    wfor(i, 0, 31)
    {
        bit[i] = 1 << i;
    }
}
const int maxn = 5e4 + 5;
int num[maxn];
int maxnum[maxn][30];
int minnum[maxn][30];
int main()
{
    int n, q;
    // cin >> n >> q;
    scanf("%d%d", &n, &q);
    int i;
    init();
    wfor(i, 1, n + 1)
    {
        // cin >> num[i];
        scanf("%d", &num[i]);
    }
    int j;
    int en = log2(n);
    wfor(i, 1, n + 1)
    {
        maxnum[i][0] = num[i];
        minnum[i][0] = num[i];
    }
    wfor(j, 1, en + 2)
    {
        wfor(i, 1, n + 1)
        {
            if (i + bit[j - 1] <= n)
            {
                maxnum[i][j] = max(maxnum[i][j - 1], maxnum[i + bit[j - 1]][j - 1]);
                minnum[i][j] = min(minnum[i][j - 1], minnum[i + bit[j - 1]][j - 1]);
            }
        }
    }
    wfor(i, 0, q)
    {
        int l, r;
        // cin >> l >> r;
        scanf("%d%d", &l, &r);
        int len = r - l + 1;
        int t = log2(len);
        int x = max(maxnum[l][t], maxnum[r - bit[t] + 1][t]);
        int y = min(minnum[l][t], minnum[r - bit[t] + 1][t]);
        // cout << x - y << endl;
        printf("%d\n", x - y);
    }
    return 0;
}
