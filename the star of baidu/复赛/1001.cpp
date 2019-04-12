#include <iostream>
#ifdef test
#include <cstdio>
#endif
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
struct st
{
	int root;
	ll val;
};
st pre[100005];
struct rule
{
	bool operator()(const st &a, const st &b)
	{
		return a.val > b.val;
	}
};
int vis[100005];
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
		memset(vis, 0, sizeof(vis));
		int n;
		cin >> n;
		int i;
		pre[0].root = 0;
		wfor(i, 1, n)
		{
			cin >> pre[i].root;
		}
		wfor(i, 0, n)
		{
			cin >> pre[i].val;
		}
		sort(pre, pre + n, rule());
		ll max_n = 0;
		ll min_n = 0;
		int first = 1;
		wfor(i, 0, n)
		{
			if (pre[i].val < 0)
				break;
			if (!vis[pre[i].root] || first)
			{
				max_n += pre[i].val;
				if (vis[pre[i].root] && first)
					first = 0;
				vis[pre[i].root] = 1;
			}
		}
		first = 1;
		memset(vis, 0, sizeof(vis));
		mfor(i, n - 1, 0)
		{
			if (pre[i].val > 0)
				break;
			if (!vis[pre[i].root] || first)
			{
				min_n += pre[i].val;
				if (vis[pre[i].root] && first)
					first = 0;
				vis[pre[i].root] = 1;
			}
		}
		cout << max_n << " " << min_n << endl;
	}
	return 0;
}
