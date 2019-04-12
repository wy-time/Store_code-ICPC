#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
ll num[50005];
ll cnt[50005];
struct st
{
	ll l;
	ll r;
	ll ans;
	ll pos;
};
st query[50005];
ll kuai [50005];
struct rule
{
	bool operator() (const st& a, const st &b)
	{
		if (kuai[a.l] == kuai[b.l])
			return a.r < b.r;
		else
			return a.l < b.l;
	}
};
struct rule2
{
	bool operator() (const st& a, const st &b)
	{
		return a.pos < b.pos;
	}
};
int main()
{
	std::ios::sync_with_stdio(false);
	ll n, m, k;
	cin >> n >> m >> k;
	ll i;
	ll unit = sqrt(n);
	wfor(i, 1, n + 1)
	{
		cin >> num[i];
		kuai[i] = i / (unit + 1);
	}
	wfor(i, 1, m + 1)
	{
		cin >> query[i].l >> query[i].r;
		query[i].pos = i;
	}
	sort(query + 1, query + 1 + m, rule());
	ll l = query[1].l;
	ll r = query[1].r;
	wfor(i, l, r + 1)
	{
		cnt[num[i]]++;
	}
	wfor(i, 1, 50005)
	{
		query[1].ans += cnt[i] * cnt[i];
	}
	wfor(i, 2, m + 1)
	{
		query[i].ans = query[i - 1].ans;
		while (l > query[i].l)
		{
			l--;
			query[i].ans = query[i].ans - cnt[num[l]] * cnt[num[l]];
			cnt[num[l]]++;
			query[i].ans = query[i].ans + cnt[num[l]] * cnt[num[l]];
		}
		while (l < query[i].l)
		{
			query[i].ans = query[i].ans - cnt[num[l]] * cnt[num[l]];
			cnt[num[l]]--;
			query[i].ans = query[i].ans + cnt[num[l]] * cnt[num[l]];
			l++;
		}
		while (r < query[i].r)
		{
			r++;
			query[i].ans = query[i].ans - cnt[num[r]] * cnt[num[r]];
			cnt[num[r]]++;
			query[i].ans = query[i].ans + cnt[num[r]] * cnt[num[r]];
		}
		while (r > query[i].r)
		{
			query[i].ans = query[i].ans - cnt[num[r]] * cnt[num[r]];
			cnt[num[r]]--;
			query[i].ans = query[i].ans + cnt[num[r]] * cnt[num[r]];
			r--;
		}
	}
	sort(query + 1, query + 1 + m, rule2());
	wfor(i, 1, m + 1)
	{
		cout << query[i].ans << endl;
	}
	// printf("30%%7=%d", 30 % 7);
	return 0;
}
