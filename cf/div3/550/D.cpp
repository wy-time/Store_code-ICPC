#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn = 2e5 + 5;
int num[maxn];
struct st
{
	int num;
	int vis;
	int pos;
};
struct rule
{
	bool operator()(const st&x, const st&y)
	{
		return x.vis > y.vis;
	}
};
struct st2
{
	int op;
	int l;
	int r;
};
st2 ans[maxn];
st vis[maxn];
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
		cin >> num[i];
		vis[num[i]].vis++;
		vis[num[i]].num = num[i];
		vis[num[i]].pos = i;
	}
	sort(vis, vis + maxn, rule());
	int need = vis[0].num;
	int pos = vis[0].pos;
	int cnt = 0;
	wfor(i, pos + 1, n)
	{
		if (num[i] != need)
		{
			ans[cnt].r = i - 1;
			ans[cnt].l = i;
			ans[cnt++].op = num[i - 1] > num[i] ? 1 : 2;
			num[i] = need;
			// pos = i;
		}
	}
	pos = vis[0].pos;
	mfor(i, pos - 1, 0)
	{
		if (num[i] != need)
		{
			ans[cnt].l = i;
			ans[cnt].r = i + 1;
			ans[cnt++].op = num[i + 1] > num[i] ? 1 : 2;
			num[i] = need;
			// pos = i;
		}
	}
	cout << cnt << endl;
	wfor(i, 0, cnt)
	{
		cout << ans[i].op << " " << ans[i].l + 1 << " " << ans[i].r + 1 << endl;
	}
	return 0;
}
