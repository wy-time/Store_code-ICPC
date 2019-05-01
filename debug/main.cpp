#include <iostream>
#include <cstring>
#include <string>
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
struct node
{
    int len;
    int llen;
    int rlen;
    int l;
    int r;
    int left;
    int right;
    int isall;
    int chan;
};
node tree1[maxn << 2];
node tree2[maxn << 2];
void push_up(int id, node *tree)
{
    tree[id].len = max(tree[id << 1].len, max(tree[id << 1 | 1].len, tree[id << 1].rlen + tree[id << 1 | 1].llen));
    if (tree[id].len == tree[id << 1].len)
    {
        tree[id].l = tree[id << 1].l;
        tree[id].r = tree[id << 1].r;
    } else if (tree[id].len == tree[id << 1 | 1].len)
    {
        tree[id].l = tree[id << 1 | 1].l;
        tree[id].r = tree[id << 1 | 1].r;
    } else
    {
        tree[id].l = tree[id << 1].right;
        tree[id].r = tree[id << 1 | 1].left;
    }
    if (tree[id << 1].isall == 0)
    {
        tree[id].llen = tree[id << 1].llen;
        tree[id].left = tree[id << 1].left;
    } else
    {
        tree[id].llen = tree[id << 1].llen + tree[id << 1 | 1].llen;
        if (tree[id << 1 | 1].llen != 0)
            tree[id].left = tree[id << 1 | 1].left;
        else
            tree[id].left = tree[id << 1].left;
    }

    if (tree[id << 1 | 1].isall == 0)
    {
        tree[id].rlen = tree[id << 1 | 1].rlen;
        tree[id].right = tree[id << 1 | 1].right;
    } else
    {
        tree[id].rlen = tree[id << 1 | 1].rlen + tree[id << 1].rlen;
        if (tree[id << 1].rlen != 0)
            tree[id].right = tree[id << 1].right;
        else
            tree[id].right = tree[id << 1 | 1].right;
    }
    if (tree[id].llen == tree[id].len)
        tree[id].isall = 1;
    else
        tree[id].isall = 0;
}
void init(int id, node *tree, int l)
{
    tree[id].isall = 1;
    tree[id].chan = 0;
    tree[id].l = tree[id].r = l;
    tree[id].right = tree[id].left = l;
    tree[id].llen = tree[id].rlen = tree[id].len = 1;
}
void build(int l, int r, int id)
{
    if (l == r)
    {
        init(id, tree1, l);
        init(id, tree2, l);
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, id << 1);
    build(mid + 1, r, id << 1 | 1);
    push_up(id, tree1);
    push_up(id, tree2);
}
void down_proc(int id, node*tree)
{
    tree[id].len = tree[id].llen = tree[id].rlen = 0;
    tree[id].l = tree[id].r = tree[id].left = tree[id].right = 0;
    tree[id].isall = 0;
    tree[id].chan = 1;
}
void time_proc(int l, int r, int id, node*tree)
{
    int len = r - l + 1;
    tree[id].len = tree[id].llen = tree[id].rlen = len;
    tree[id].r = tree[id].left = r;
    tree[id].l = tree[id].right = l;
    tree[id].isall = 1;
    tree[id].chan = 2;
}
void push_down(int l, int r, int id, node*tree)
{
    if (tree[id].chan == 1)
    {
        down_proc(id << 1, tree);
        down_proc(id << 1 | 1, tree);
        tree[id].chan = 0;
    }
    if (tree[id].chan == 2)
    {
        int mid = (l + r) >> 1;
        time_proc(l, mid, id << 1, tree);
        time_proc(mid + 1, r, id << 1 | 1, tree);
        tree[id].chan = 0;
    }
}
void updata(int l, int r, int L, int R, int id, node*tree)
{
    if (l >= L && r <= R)
    {
        down_proc(id, tree);
        return;
    }
    int mid = (l + r) >> 1;
    push_down(l, r, id, tree);
    if (mid >= L)
        updata(l, mid, L, R, id << 1, tree);
    if (mid < R)
        updata(mid + 1, r, L, R, id << 1 | 1, tree);
    push_up(id, tree);
}
void study(int l, int r, int L, int R, int id, node*tree)
{
    if (l >= L && r <= R)
    {
        time_proc(l, r, id, tree);
        return ;
    }
    int mid = (l + r) >> 1;
    push_down(l, r, id, tree);
    if (mid >= L)
        study(l, mid, L, R, id << 1, tree);
    if (mid < R)
        study(mid + 1, r, L, R, id << 1 | 1, tree);
    push_up(id, tree);
}
void find_time(int l, int r, int id, int len, int &x, node *tree)
{
    if (tree[id].len < len)
    {
        return ;
    } else
    {
        x = min(x, tree[id].l);
    }
    if (l == r)
        return ;
    int mid = (l + r) >> 1;
    push_down(l, r, id, tree);
    find_time(l, mid, id << 1, len, x, tree);
    find_time(mid + 1, r, id << 1 | 1, len, x, tree);
}
int main()
{
    std::ios::sync_with_stdio(false);
    // #ifdef test
    // freopen("F:\\Desktop\\question\\in.txt","r",stdin);
    // #endif
    // #ifdef ubuntu
    // freopen("/home/time/debug/debug/in","r",stdin);
    // freopen("/home/time/debug/debug/out","w",stdout);
    // #endif
    int t;
    int casecnt = 0;
    cin >> t;
    while (t--)
    {
        casecnt++;
        int n, m;
        cin >> n >> m;
        memset(tree1, 0, sizeof(tree1));
        memset(tree2, 0, sizeof(tree2));
        build(1, n, 1);
        int i;
        cout << "Case " << casecnt << ":" << endl;
        wfor(i, 0, m)
        {
            string s;
            int tim;
            cin >> s >> tim;
            if (s[0] == 'D')
            {
                int x = 1e9;
                find_time(1, n, 1, tim, x, tree1);
                if (x == 1e9)
                {
                    cout << "fly with yourself" << endl;
                } else
                {
                    cout << x << ",let's fly" << endl;
                    updata(1, n, x, x + tim - 1, 1, tree1);
                }
            } else if (s[0] == 'N')
            {
                int x = 1e9;
                find_time(1, n, 1, tim, x, tree1);
                if (x == 1e9)
                {
                    find_time(1, n, 1, tim, x, tree2);
                    if (x == 1e9)
                    {
                        cout << "wait for me" << endl;
                    } else
                    {
                        cout << x << ",don't put my gezi" << endl;
                        updata(1, n, x, x + tim - 1, 1, tree1);
                        updata(1, n, x, x + tim - 1, 1, tree2);
                    }
                } else
                {
                    cout << x << ",don't put my gezi" << endl;
                    updata(1, n, x, x + tim - 1, 1, tree1);
                    updata(1, n, x, x + tim - 1, 1, tree2);
                }
            } else
            {
                int l, r;
                l = tim;
                cin >> r;
                study(1, n, l, r, 1, tree1);
                study(1, n, l, r, 1, tree2);
                cout << "I am the hope of chinese chengxuyuan!!" << endl;
            }
        }
    }
    return 0;
}
