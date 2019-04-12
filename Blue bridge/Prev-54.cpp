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
const int maxn = 1005;
int pre[maxn * maxn];
int findx(int x)
{
    int i = x;
    while (pre[i] != i)
    {
        i = pre[i];
    }
    int j;
    while (pre[x] != i)
    {
        j = pre[x];
        pre[x] = i;
        x = j;
    }
    return i;
}
void add(int a, int b)
{
    int a1 = findx(a);
    int b1 = findx(b);
    pre[b1] = a1;
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
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    int i;
    wfor(i, 0, n * m + 1)
    {
        pre[i] = i;
    }
    wfor(i, 0, k)
    {
        int a, b;
        cin >> a >> b;
        if (findx(a) != findx(b))
        {
            add(a, b);
        }
    }
    int ans = 0;
    wfor(i, 1, n * m + 1)
    {
        if (findx(i) == i)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
