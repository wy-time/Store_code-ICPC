#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
void read(int &x) {
	char ch = getchar(); x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
const int maxn = 5e5 + 10;
struct node
{
	int lch;
	int rch;
	int cnt;
};
node tree[maxn * 40];
int root[maxn];
int num[maxn];
int num2[maxn];
int cnt;
void build_new(int l, int r, int old, int &now, int pos)
{
	tree[++cnt] = tree[old];
	now = cnt;
	tree[cnt].cnt++;
	if (l == r)
		return ;
	int mid = (l + r) >> 1;
	if (mid >= pos)
		build_new(l, mid, tree[old].lch, tree[now].lch, pos);
	else
		build_new(mid + 1, r, tree[old].rch, tree[now].rch, pos);
}
int query(int l, int r, int root1, int root2, int k)
{
	if (l == r)
		return l;
	int temp = tree[tree[root1].lch].cnt - tree[tree[root2].lch].cnt;
	int mid = (l + r) >> 1;
	if (temp > k)
		return query(l, mid, tree[root1].lch, tree[root2].lch, k);
	else if (tree[tree[root1].rch].cnt - tree[tree[root2].rch].cnt > k)
		return query(mid + 1, r, tree[root1].rch, tree[root2].rch, k);
	else
		return 0;
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
	int n, m;
	// cin >> n >> m;
	read(n), read(m);
	int i;
	wfor(i, 0, n)
	{
		// cin >> num[i];
		read(num[i]);
		num2[i] = num[i];
	}
	sort(num, num + n);
	int pos = unique(num, num + n) - num;
	wfor(i, 1, n + 1)
	{
		build_new(1, pos, root[i - 1], root[i], lower_bound(num, num + pos, num2[i - 1]) - num + 1);
	}
	wfor(i, 0, m)
	{
		int l, r;
		// cin >> l >> r;
		read(l), read(r);
		int ans = query(1, pos, root[r], root[l - 1], (r - l + 1) / 2);
		if (ans == 0)
			// cout << 0 << endl;
			printf("0\n");
		else
			// cout << num[ans - 1] << endl;
			printf("%d\n", num[ans - 1]);
	}
	return 0;
}
