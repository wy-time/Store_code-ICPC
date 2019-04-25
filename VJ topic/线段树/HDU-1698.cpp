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
const int maxn = 100005;
int tree[maxn << 2];
int target[maxn << 2];
void push_up(int id)
{
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
}
void bulid(int l, int r, int id)
{
    if (l == r)
    {
        tree[id] = 1;
        return ;
    }
    int mid = (l + r) >> 1;
    bulid(l, mid, id << 1);
    bulid(mid + 1, r, id << 1 | 1);
    push_up(id);
}
void push_down(int ln, int rn, int id)
{
    if (target[id])
    {
        tree[id << 1] = ln * target[id];
        tree[id << 1 | 1] = rn * target[id];
        target[id << 1] = target[id << 1 | 1] = target[id];
        target[id] = 0;
    }
}
void updata(int l, int r, int L, int R, int id, int number)
{
    if (l >= L && r <= R)
    {
        tree[id] = (r - l + 1) * number;
        target[id] = number;
        return ;
    }
    int mid = (l + r) >> 1;
    push_down(mid - l + 1, r - mid, id);
    if (mid >= L)
        updata(l, mid, L, R, id << 1, number);
    if (mid < R)
        updata(mid + 1, r, L, R, id << 1 | 1, number);
    push_up(id);
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
    int t;
    cin >> t;
    int casecnt = 0;
    while (t--)
    {
        casecnt++;
        int n;
        cin >> n;
        memset(target, 0, sizeof(target));
        bulid(1, n, 1);
        int q;
        cin >> q;
        int i;
        wfor(i, 0, q)
        {
            int l, r, z;
            cin >> l >> r >> z;
            updata(1, n, l, r, 1, z);
        }
        int ans = tree[1];
        cout << "Case " << casecnt << ": The total value of the hook is ";
        cout << ans << "." << endl;
    }
    return 0;
}
