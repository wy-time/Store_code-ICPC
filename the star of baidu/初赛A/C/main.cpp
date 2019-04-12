#include <iostream>
#ifdef test
#include <cstdio>
#endif
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
struct st
{
	int len;
	int pos;
	st() {}
	st(int a, int b)
	{
		len = a;
		pos = b;
	}
};
struct rule
{
	bool operator()(const st&a, const st&b)
	{
		return a.len > b.len;
	}
};
int vis[2][10005];
int main()
{
	std::ios::sync_with_stdio(false);
	vector <st> fuck[2];
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n, k;
	while (cin >> n >> k)
	{
		string s;
		cin >> s;
		int i;
		int pos = -1;
		wfor(i, 0, n)
		{
			if (s[i] == '1' && pos == -1)
			{
				pos = i;
			}
			if ((i == n - 1 || s[i] == '0') && pos != -1)
			{
				if (i == n - 1)
				{
					if (s[i] != '0')
						fuck[0].push_back(st(i - pos + 1, pos));
					else
						fuck[1].push_back(st(i - pos, pos));
				} else
				{
					if (pos - 1 >= 0 && s[pos - 1] == '0')
					{
						fuck[1].push_back(st(i - pos, pos));
					} else
					{
						fuck[0].push_back(st(i - pos, pos));
					}
				}
				pos = -1;
			}
		}
		sort(fuck[0].begin(), fuck[0].end(), rule());
		sort(fuck[1].begin(), fuck[1].end(), rule());
		if (fuck[0].size() == 1)
		{
			fuck[0][0].pos == 1;
		}
		ll res = 0;
		while (k > 1)
		{
			int tpos = fuck[1].pos;
			int tlen = fuck[1].len;

		}
	}
	return 0;
}
