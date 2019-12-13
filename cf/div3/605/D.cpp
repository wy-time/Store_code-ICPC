#include <iostream>
#include <vector>
#include <cstdio>
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
vector <pair<int, int> >v;
int num[maxn];
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
	}
	int l = 0, r = 0;
	wfor(i, 0, n)
	{
		if (num[i] < num[r + 1])
		{
			r++;
		} else
		{
			v.push_back(make_pair(l, r));
			l = i + 1;
			r = i + 1;
		}
	}
	int cnt = v.size();
	pair<int, int>now;
	now = v[0];
	int ans = 0;
	ans = max(ans, now.second - now.first + 1);
	wfor(i, 1, cnt)
	{
		ans = max(ans, v[i].second - v[i].first + 1);
		if (v[i - 1].second + 1 == v[i].first)
		{
			if (num[v[i - 1].second - 1] < num[v[i].first] || num[v[i - 1].second] < num[v[i].first + 1])
			{
				ans = max(v[i].second - v[i - 1].first, ans);
			}
		} else if (v[i - 1].second + 2 == v[i].first)
		{
			if (num[v[i - 1].second] < num[v[i].first])
				ans = max(v[i].second - v[i - 1].first, ans);
		}
	}
	cout << ans << endl;
	return 0;
}
