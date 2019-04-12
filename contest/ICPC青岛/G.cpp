#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
//     char ch = getchar(); x = 0;
//     for (; ch < '0' || ch > '9'; ch = getchar());
//     for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
#define lowbit(i) i&-i
int maxn = 100005;
int tree1[maxn];
// int tree2[maxn];
void add(int n, int a, int b)
{
    int i;
    for (i = a; i <= n; i += lowbit(i))
        tree1[i] += b;
}
int query(int n, int a)
{
    int i;
    int ans = 0;
    for (i = a; i > 0; i -= lowbit(i))
        ans += tree1[i];
    return ans;
}
// void add2(int n, int a, int b)
// {
//     int i;
//     for (i = a; i <= n; i += lowbit(i))
//         tree2[i] += b;
// }
// int query2(int n, int a)
// {
//     int i;
//     int ans = 0;
//     for (i = a; i > 0; i -= lowbit(i))
//         ans += tree2[i];
//     return ans;
// }
int p[maxn];
int ans[maxn];
int num[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
#ifdef test
    freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int i;
        int ni = 0;
        wfor(i, 1, n + 1)
        {
            cin >> num[i];
            add(num[i], 1);
            ni += i - query(t);
            // add2(i, i - query(t));
        }
        wfor(i, 0, n)
        {
            cin >> p[i];
        }
        wfor(i, 0, n)
        {
            // int temp=query2(n)-query2(i+2);
            ans[i] = ni;
            num[temp ^ p[i]];
        }
    }
    return 0;
}


