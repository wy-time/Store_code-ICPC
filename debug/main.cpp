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
const int maxn = 5e4 + 5;
struct node
{
    int sum;
    int maxnum;
    int minnum;
    int change;
};
node tree[maxn << 2];
int n;
void push_up(int id)
{
    tree[id].sum = tree[id << 1].sum + tree[id << 1 | 1].sum;
    tree[id].maxnum = max(tree[id << 1].maxnum, tree[id << 1 | 1].maxnum);
    tree[id].minnum = min(tree[id << 1].minnum, tree[id << 1 | 1].minnum);
}
void build(int l, int r, int id)
{
    if (l == r)
    {
        tree[id].sum = 1;
        tree[id].maxnum = l;
        tree[id].minnum = l;
        tree[id].change = 0;
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, id << 1);
    build(mid + 1, r, id << 1 | 1);
    push_up(id);
}
void push_down(int l, int r, int id)
{
    if (tree[id].change == 1)
    {
        int mid = (l + r) >> 1;
        tree[id << 1].sum = mid - l + 1;
        tree[id << 1 | 1].sum = r - mid;
        tree[id << 1].maxnum = max(mid, tree[id << 1].maxnum);
        tree[id << 1].minnum = min(l, tree[id << 1].minnum);
        tree[id << 1 | 1].maxnum = max(tree[id << 1 | 1].maxnum, r);
        tree[id << 1 | 1].minnum = min(tree[id << 1 | 1].minnum, mid + 1);
        tree[id << 1].change = tree[id << 1 | 1].change = 1;
        tree[id].change = 0;
    }
    if (tree[id].change == 2)
    {
        tree[id << 1].sum = 0;
        tree[id << 1 | 1].sum = 0;
        tree[id << 1].maxnum = -2;
        tree[id << 1].minnum = 1e9;
        tree[id << 1 | 1].maxnum = -2;
        tree[id << 1 | 1].minnum = 1e9;
        tree[id << 1].change = tree[id << 1 | 1].change = 2;
        tree[id].change = 0;
    }
}
void updata_clean(int l, int r, int L, int R, int id)
{
    if (l >= L && r <= R)
    {
        tree[id].sum = r - l + 1;
        tree[id].maxnum = max(r, tree[id].maxnum);
        tree[id].minnum = min(l, tree[id].minnum);
        tree[id].change = 1;
        return ;
    }
    int mid = (l + r) >> 1;
    push_down(l, r, id);
    if (mid >= L)
        updata_clean(l, mid, L, R, id << 1);
    if (mid < R)
        updata_clean(mid + 1, r, L, R, id << 1 | 1);
    push_up(id);
}
int query_disc(int l, int r, int L, int R, int id)
{
    if (l >= L && r <= R)
    {
        return tree[id].sum;
    }
    int mid = (l + r) >> 1;
    push_down(l, r, id);
    int ans = 0;
    if (mid >= L)
        ans += query_disc(l, mid, L, R, id << 1);
    if (mid < R)
        ans += query_disc(mid + 1, r, L, R, id << 1 | 1);
    return ans;
}
void updata_use(int l, int r, int L, int R, int id)
{
    if (l >= L && r <= R)
    {
        tree[id].sum = 0;
        tree[id].maxnum = -2;
        tree[id].minnum = 1e9;
        tree[id].change = 2;
        return;
    }
    int mid = (l + r) >> 1;
    push_down(l, r, id);
    if (mid >= L)
        updata_use(l, mid, L, R, id << 1);
    if (mid < R)
        updata_use(mid + 1, r, L, R, id << 1 | 1);
    push_up(id);
}
int x, y;
void query_in(int l, int r, int L, int R, int id, int &number)
{
    if (number == 0)
        return ;
    if (l >= L && r <= R)
    {
        int have = tree[id].sum;
        if (have <= 0)
            return ;
        if (have <= number)
        {
            x = min(x, tree[id].minnum);
            y = max(y, tree[id].maxnum);
            updata_use(1, n, x, y, 1);
            number -= have;
            return ;
        }
    }
    if (l == r)
    {
        if (tree[id].sum == 1)
        {
            number--;
            x = min(x, l);
            y = max(y, l);
            tree[id].sum = 0;
            tree[id].maxnum = -2;
            tree[id].minnum = 1e9;
            return ;
        }
    }
    int mid = (l + r) >> 1;
    push_down(l, r, id);
    if (mid >= L)
        query_in(l, mid, L, R, id << 1, number);
    if (mid < R)
        query_in(mid + 1, r, L, R, id << 1 | 1, number);
}
int main()
{
    std::ios::sync_with_stdio(false);
#ifdef test
    freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
    freopen("F:\\Desktop\\question\\out.txt", "w", stdout);
#endif
#ifdef ubuntu
    freopen("/home/time/debug/debug/in", "r", stdin);
    freopen("/home/time/debug/debug/out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> n >> m;
        build(1, n, 1);
        int i;
        wfor(i, 0, m)
        {
            int op;
            cin >> op;
            if (op == 1)
            {
                int pos, number;
                cin >> pos >> number;
                x = 1e9;
                y = -1;
                pos++;
                query_in(1, n, pos, n, 1, number);
                if (y == -1)
                {
                    cout << "Can not put any one." << endl;
                } else
                {
                    x--;
                    y--;
                    cout << x << " " << y << endl;
                }
            } else
            {
                int l, r;
                cin >> l >> r;
                l++;
                r++;
                int ans = query_disc(1, n, l, r, 1);
                cout << r - l + 1 - ans << endl;
                updata_clean(1, n, l, r, 1);
            }
        }
        cout << endl;
    }
    return 0;
}
