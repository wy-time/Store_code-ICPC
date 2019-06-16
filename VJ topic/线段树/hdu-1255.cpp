#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
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
const int maxn = 2005;
struct Point
{
    double x1;
    double x2;
    double y1;
    double y2;
};
Point point[maxn];
struct Line
{
    int l;
    int r;
    double high;
    int flag;
    bool operator <(const Line &other)const
    {
        return high < other.high;
    }
};
struct node
{
    int s;
    double len[3];
    int l, r;
};
node tree[maxn * 8];
Line line[maxn << 1];
vector<double>num;
void build(int l, int r, int id)
{
    tree[id].l = l;
    tree[id].r = r;
    tree[id].s = 0;
    tree[id].len[1] = tree[id].len[2] = 0;
    tree[id].len[0] = num[r - 1] - num[l - 1];
    if (l + 1 == r)
        return;
    int mid = (l + r) >> 1;
    build(l, mid, id << 1);
    build(mid, r, id << 1 | 1);
}
void push_up(int id)
{
    int i;
    wfor(i, 1, 3)
    {
        if (tree[id].s < i)
            tree[id].len[i] = tree[id << 1].len[i - tree[id].s] + tree[id << 1 | 1].len[i - tree[id].s];
        else
            tree[id].len[i] = tree[id].len[0];
    }
}
void update(int id, int L, int R, int number)
{
    if (tree[id].l >= L && tree[id].r <= R)
    {
        tree[id].s += number;
        push_up(id);
        return ;
    }
    int mid = (tree[id].l + tree[id].r) >> 1;
    if (mid > L)
        update(id << 1, L, R, number);
    if (mid < R)
        update(id << 1 | 1, L, R, number);
    push_up(id);
}
int main()
{
    // std::ios::sync_with_stdio(false);
#ifdef test
    freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
#ifdef ubuntu
    freopen("/home/time/debug/debug/in", "r", stdin);
    freopen("/home/time/debug/debug/out", "w", stdout);
#endif
    int t;
    // cin >> t;
    scanf("%d", &t);
    while (t--)
    {
        num.clear();
        int n;
        // cin >> n;
        scanf("%d", &n);
        int i;
        wfor(i, 0, n)
        {
            // cin >> point[i].x1 >> point[i].y1 >> point[i].x2 >> point[i].y2;
            scanf("%lf %lf %lf %lf", &point[i].x1, &point[i].y1, &point[i].x2, &point[i].y2);
            num.push_back(point[i].x1);
            num.push_back(point[i].x2);
        }
        sort(num.begin(), num.end());
        auto it = unique(num.begin(), num.end());
        int len = it - num.begin();
        int cnt = 0;
        wfor(i, 0, n)
        {
            int x1 = lower_bound(num.begin(), it, point[i].x1) - num.begin() + 1;
            int x2 = lower_bound(num.begin(), it, point[i].x2) - num.begin() + 1;
            line[cnt].l = x1;
            line[cnt].r = x2;
            line[cnt].high = point[i].y1;
            line[cnt++].flag = 1;
            line[cnt].l = x1;
            line[cnt].r = x2;
            line[cnt].high = point[i].y2;
            line[cnt++].flag = -1;
        }
        sort(line, line + cnt);
        build(1, len, 1);
        double ans = 0;
        double last = line[0].high;
        update(1, line[0].l, line[0].r, line[0].flag);
        wfor(i, 1, cnt)
        {
            ans += tree[1].len[2] * (line[i].high - last);
            update(1, line[i].l, line[i].r, line[i].flag);
            last = line[i].high;
        }
        // cout << fixed << setprecision(3) << ans << endl;
        printf("%.2f\n", ans);
    }
    return 0;
}
