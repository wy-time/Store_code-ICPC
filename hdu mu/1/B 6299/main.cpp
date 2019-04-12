#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
#define for(i,j,k) for(i=j;i<k;++i)
#define ffor(i,j,k) for(i=j;i>=k;--i)
typedef struct
{
	ll l;
	ll r;
} strinfo;
strinfo info [100005];
struct rule
{
	bool operator() (const strinfo &a, const strinfo &b)
	{
		if (a.l <= a.r && b.l <= b.r)
		{
			return a.l < b.l;
		} else if (a.l <= a.r && b.l >= b.r)
		{
			return true;
		} else if (a.l >= a.r && b.l <= b.r)
		{
			return false;
		}
		return a.r > b.r;
	}
};
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		memset(info, 0, sizeof(info));
		string s;
		stack<char> sta;
		int n;
		cin >> n;
		int i, j;
		ll ans = 0;
		for (i, 0, n)
		{
			cin >> s;
			int len = s.size();
			for (j, 0, len)
			{
				if (sta.empty())
					sta.push(s[j]);
				else
				{
					if (sta.top() == '(' && s[j] == ')')
					{
						sta.pop();
						ans += 2;
					} else
						sta.push(s[j]);
				}
			}
			while (!sta.empty())
			{
				if (sta.top() == ')')
					info[i].l++;
				else
					info[i].r++;
				sta.pop();
			}
		}
		sort(info, info + n, rule());
		ll r;
		r = info[0].r;
		for (i, 1, n)
		{
			ll temp1 = min(r, info[i].l);
			ans += temp1 * 2;
			r -= temp1;
			r += info[i].r;
		}
		cout << ans << endl;
	}
	return 0;
}
