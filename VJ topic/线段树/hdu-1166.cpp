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
const int maxn = 50005;
int tree[maxn << 2];
int num[maxn];
void push_up(int now)
{
    tree[now] = tree[now << 1] + tree[now << 1 | 1];
}
void build(int l, int r, int now)
{
    if (l == r)
    {
        tree[now] = num[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, now << 1);
    build(mid + 1, r, now << 1 | 1);
    push_up(now);
}
void update(int l, int r, int now, int number, int pos)
{
    if (l == r)
    {
        tree[now] += number;
        return ;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        update(l, mid, now << 1, number, pos);
    else
        update(mid + 1, r, now << 1 | 1, number, pos);
    push_up(now);
}
int query(int l, int r, int now, int L, int R)
{
    if (l >= L && r <= R)
    {
        return tree[now];
    }
    int ans = 0;
    int mid = (l + r) >> 1;
    if (mid >= L)
        ans += query(l, mid, now << 1, L, R);
    if (mid < R)
        ans += query(mid + 1, r, now << 1 | 1, L, R);
    return ans;
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
        cout << "Case " << casecnt << ":" << endl;
        int n;
        cin >> n;
        int i;
        wfor(i, 1, n + 1)
        {
            cin >> num[i];
        }
        build(1, n, 1);
        char op[10];
        while (cin >> op)
        {
            if (op[0] == 'A')
            {
                int number, pos;
                cin >> pos >> number;
                update(1, n, 1, number, pos);
            } else if (op[0] == 'S')
            {
                int number, pos;
                cin >> pos >> number;
                update(1, n, 1, -number, pos);
            } else if (op[0] == 'Q')
            {
                int l, r;
                cin >> l >> r;
                int ans = query(1, n, 1, l, r);
                cout << ans << endl;
            } else
            {
                break;
            }
        }
    }
    return 0;
}
