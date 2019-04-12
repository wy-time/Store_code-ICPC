#include <iostream>
#include <cstring>
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
const int maxn = 5005;
struct st
{
    int l;
    int r;
    int len;
};
st man[maxn];
int sum1[maxn];
int sum2[maxn];
const int INF = 0x7f7f7f7f;
int sub[maxn];
int num[maxn];
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
    int n, q;
    cin >> n >> q;
    int i;
    wfor(i, 0, q)
    {
        cin >> man[i].l >> man[i].r;
        sub[man[i].l]++;
        sub[man[i].r + 1]--;
    }
    int ans = 0;
    int j;
    wfor(i, 1, n + 1)
    {
        num[i] += num[i - 1];
        if (num[i] == 1)
            sum1[i] = sum[i - 1] + 1;
        else if (num[i] == 2)
            sum2[i] = sum2[i] + 1;
        if (num[i] != 0)
            ans++;
    }

    return 0;
}