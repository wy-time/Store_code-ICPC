#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn = 150005;
int ma[200];
vector<int>v[200];
vector<pair<int, int>>ans;
int fix[maxn];
int vis1[maxn];
int vis2[maxn];
int fix2[maxn];
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
	string s1, s2;
	cin >> s1;
	cin >> s2;
	int i;
	wfor(i, 0, n)
	{
		ma[s1[i]]++;
		v[s1[i]].push_back(i + 1);
	}
	int res = 0;
	int tcnt = 0;
	wfor(i, 0, n)
	{
		if (s2[i] != '?')
		{
			if (ma[s2[i]] > 0)
			{
				res++;
				ma[s2[i]]--;
				ans.push_back(make_pair(v[s2[i]][ma[s2[i]]], i + 1));
				vis1[v[s2[i]][ma[s2[i]]] - 1] = 1;
				vis2[i] = 1;
			}
		} else
		{
			fix[tcnt++] = i + 1;
		}
	}
	if (res < n && ma['?'] > 0)
	{
		wfor(i, 0, n)
		{
			if (!vis2[i] && s2[i] != '?')
			{
				vis2[i] = 1;
				res++;
				ma['?']--;
				ans.push_back(make_pair(v['?'][ma['?']], i + 1));
				vis1[v['?'][ma['?']] - 1] = 1;
			}
			if (ma['?'] == 0)
				break;
		}
		if (ma['?'] > 0)
		{
			wfor(i, 0, n)
			{
				if (!vis2[i])
				{
					vis2[i] = 1;
					res++;
					ma['?']--;
					ans.push_back(make_pair(v['?'][ma['?']], i + 1));
					vis1[v['?'][ma['?']] - 1] = 1;
				}
				if (ma['?'] == 0)
					break;
			}
		}
	}
	if (res < n && tcnt > 0)
	{
		int ttcnt = 0;
		wfor(i, 0, tcnt)
		{
			if (!vis2[fix[i] - 1])
			{
				res++;
				vis2[fix[i] - 1] = 1;
				fix2[ttcnt++] = fix[i];
			}
		}
		if (ttcnt > 0)
		{
			wfor(i, 0, n)
			{
				if (!vis1[i] && ttcnt > 0)
				{
					vis1[i] = 1;
					ttcnt--;
					ans.push_back(make_pair(i + 1, fix2[ttcnt]));
					vis2[fix2[ttcnt] - 1] = 1;
				}
				if (ttcnt <= 0)
					break;
			}
		}
	}
	cout << res << endl;
	for (auto it : ans)
	{
		cout << it.first << " " << it.second << endl;
	}
	return 0;
}
