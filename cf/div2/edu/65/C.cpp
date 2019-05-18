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
const int maxn = 1e6 + 5;
int pre[maxn];
int findx(int x)
{
    int t = x;
    while (pre[t] != t)
    {
        t = pre[t];
    }
    int temp;
    while (pre[x] != t)
    {
        temp = pre[x];
        pre[x] = t;
        x = temp;
    }
    return t;
}
void add(int a, int b)
{
    int a1 = findx(a);
    int b1 = findx(b);
    pre[b1] = a1;
}
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
    int n, m;
    cin >> n >> m;
    int i;
    wfor(i, 0, maxn)
    {
        pre[i] = i;
    }
    wfor(i, 1, m + 1)
    {
        int cnt;
        cin >> cnt;
        int j;
        wfor(j, 0, cnt)
        {
            int temp;
            cin >> temp;
            if (findx(i) != findx(temp + m + 1))
            {
                if (pre[temp + m + 1] == temp + m + 1)
                    ans[i]++;
                else
                    ans[i] += ans[findx(temp + m + 1)];
                add(i, temp + m + 1);
            }
        }
    }
    wfor(i, 1, n + 1)
    {
        int root = findx(i + m + 1);
        if (ans[root] != 0)
            cout << ans[root] << " ";
        else
            cout << 1 << " ";
    }
    return 0;
}
