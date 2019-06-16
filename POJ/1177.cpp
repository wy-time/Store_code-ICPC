#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
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
const int maxn = 20005;
struct node
{
    int l, r;
    int s;
    int len;
};
struct Line
{
    int l, r;
    int high;
    int flag;
    bool operator <(const Line & other)const
    {
        return high < other.high;
    }
};
vector <int>num;
struct Rect
{
    int x1;
    int y1;
    int x2;
    int y2;
};
Rect rec[maxn];
Line line1[maxn];
Line line2[maxn];
node tree[maxn << 2];
void build (int l, int r, int id)
{
    tree[id].l = l;
    tree[id].r = r;
    tree[id].len = 0;
    tree[id].s = 0;
    if (l + 1 == r)
        return ;
    int mid = (l + r) >> 1;
    build(l, mid, id << 1);
    build(mid, r, id << 1 | 1);
}
void push_up(int id)
{
    if (tree[id].s)
        tree[id].len = num[tree[id].r - 1] - num[tree[id].l - 1];
    else
        tree[id].len = tree[id << 1].len + tree[id << 1 | 1].len;
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
        cin >> rec[i].x1 >> rec[i].y1 >> rec[i].x2 >> rec[i].y2;
        num.push_back(rec[i].x1);
        num.push_back(rec[i].x2);
        num.push_back(rec[i].y1);
        num.push_back(rec[i].y2);
    }
    sort(num.begin(), num.end());
    vector<int>::iterator it = unique(num.begin(), num.end());
    int len = it - num.begin();
    int cnt = 0;
    wfor(i, 0, n)
    {
        rec[i].x1 = lower_bound(num.begin(), it, rec[i].x1) - num.begin() + 1;
        rec[i].x2 = lower_bound(num.begin(), it, rec[i].x2) - num.begin() + 1;
        rec[i].y1 = lower_bound(num.begin(), it, rec[i].y1) - num.begin() + 1;
        rec[i].y2 = lower_bound(num.begin(), it, rec[i].y2) - num.begin() + 1;
    }
    wfor(i, 0, n)
    {
        line1[cnt].l = rec[i].x1;
        line1[cnt].r = rec[i].x2;
        line1[cnt].high = rec[i].y1;
        line1[cnt].flag = 1;
        line2[cnt].l = rec[i].y1;
        line2[cnt].r = rec[i].y2;
        line2[cnt].high = rec[i].x1;
        line2[cnt++].flag = 1;
        line1[cnt].l = rec[i].x1;
        line1[cnt].r = rec[i].x2;
        line1[cnt].high = rec[i].y2;
        line1[cnt].flag = -1;
        line2[cnt].l = rec[i].y1;
        line2[cnt].r = rec[i].y2;
        line2[cnt].high = rec[i].x2;
        line2[cnt++].flag = -1;
    }
    sort(line1, line1 + cnt);
    sort(line2, line2 + cnt);
    ll ans = 0;
    build(1, len, 1);
    update(1, line1[0].l, line1[0].r, line1[0].flag);
    ans += num[line1[0].r - 1] - num[line1[0].l - 1];
    int last = ans;
    wfor(i, 1, cnt)
    {
        update(1, line1[i].l, line1[i].r, line1[i].flag);
        ans += abs(tree[1].len - last);
        last = tree[1].len;
    }
    build(1, len, 1);
    update(1, line2[0].l, line2[0].r, line2[0].flag);
    ans += num[line2[0].r - 1] - num[line2[0].l - 1];
    last = num[line2[0].r - 1] - num[line2[0].l - 1];
    wfor(i, 1, cnt)
    {
        update(1, line2[i].l, line2[i].r, line2[i].flag);
        ans += abs(tree[1].len - last);
        last = tree[1].len;
    }
    cout << ans << endl;
    return 0;
}
