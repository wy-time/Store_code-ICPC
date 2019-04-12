#include <iostream>
#ifdef test
#include <cstdio>
#endif
#include <algorithm>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int num[500005];
int vis[1000005];
int lowbit(int x)
{
	return x & -x;
}
void up_data(int x, int y);
int get_sum(int x);
int n;
struct st
{
	int l;
	int r;
	int id;
	int ans;
};
struct rule
{
	bool operator()(const st&a, const st&b)
	{
		return a.r < b.r;
	}
};
struct rule2
{
	bool operator()(const st&a, const st &b)
	{
		return a.id < b.id;
	}
};
st query[200005];
int number[500005];
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	cin >> n;
	int i;
	wfor(i, 1, n + 1)
	{
		cin >> number[i];
	}
	int m;
	cin >> m;
	wfor(i, 1, m + 1)
	{
		cin >> query[i].l >> query[i].r;
		query[i].id = i;
	}
	sort(query + 1, query + 1 + m, rule());
	int cnt = 1;
	wfor(i, 1, m + 1)
	{
		while (cnt <= query[i].r)
		{
			up_data(cnt, 1);
			if (vis[number[cnt]] == 0)
			{
				vis[number[cnt]] = cnt;
			}
			else
			{
				up_data(vis[number[cnt]], -1);
				vis[number[cnt]] = cnt;
			}
			cnt++;
		}
		query[i].ans = get_sum(query[i].r) - get_sum(query[i].l - 1);
	}
	sort(query + 1, query + 1 + m, rule2());
	wfor(i, 1, m + 1)
	{
		cout << query[i].ans << endl;
	}
	return 0;
}
void up_data(int x, int y)
{
	int i;
	for (i = x; i <= n; i += lowbit(i))
	{
		num[i] += y;
	}
}
int get_sum(int x)
{
	int i;
	int ans = 0;
	for (i = x; i; i -= lowbit(i))
		ans += num[i];
	return ans;
}