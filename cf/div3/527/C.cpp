#include <iostream>
#include <cstdio>
#include <string>
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
struct st
{
	string s;
	int id;
};
st str[500];
struct rule1
{
	bool operator()(const st &a, const st &b)
	{
		if (a.s.size() != b.s.size())
		{
			return a.s.size() < b.s.size();
		} else
		{
			return a.s < b.s;
		}
	}
};
char ans[500];
int t;
int cntl, cntr;
int dfs(string p, string s, int deep, int last)
{
	if (deep == t - 1)
	{
		if (last == 1)
		{
			if ((s.compare("") == 0 || str[deep].s.rfind(s) == str[deep].s.size() - s.size()))
			{
				ans[str[deep].id] = 'S';
				return 1;
			} else
				return 0;
		} else
		{
			if ((p.compare("") == 0 || str[deep].s.find(p) == 0))
			{
				ans[str[deep].id] = 'P';
				return 1;
			} else
				return 0;
		}
	} else
	{
		if (deep % 2 == 0)
		{
			if ((p.compare("") == 0 || str[deep].s.find(p) == 0))
			{
				if (dfs(str[deep].s, s, deep + 1, 1))
				{
					ans[str[deep].id] = 'P';
					return 1;
				}
			}
			if ((s.compare("") == 0 || str[deep].s.rfind(s) == str[deep].s.size() - s.size()))
			{
				if (dfs(p, str[deep].s, deep + 1, 2))
				{
					ans[str[deep].id] = 'S';
					return 1;
				}
			}
		} else
		{
			if (last == 1)
			{
				if ((s.compare("") == 0 || str[deep].s.rfind(s) == str[deep].s.size() - s.size()))
				{
					if (dfs(p, str[deep].s, deep + 1, -1))
					{
						ans[str[deep].id] = 'S';
						return 1;
					}
				} else
					return 0;
			} else
			{
				if ((p.compare("") == 0 || str[deep].s.find(p) == 0))
				{
					if (dfs(str[deep].s, s, deep + 1, -1))
					{
						ans[str[deep].id] = 'P';
						return 1;
					}
				} else
					return 0;
			}
		}
	}
	return 0;
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
	t = 2 * n - 2;
	int i;
	wfor(i, 0, t)
	{
		cin >> str[i].s;
		str[i].id = i;
	}
	sort(str, str + t, rule1());
	dfs("", "", 0, -1);
	wfor(i, 0, t)
	{
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
