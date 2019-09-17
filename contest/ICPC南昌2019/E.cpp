#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
queue<int>qu;
const int maxn = 4e7 + 5;
int ans[maxn];
int res[maxn];
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
	int t;
	cin >> t;
	
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int i;
		while (!qu.empty())
			qu.pop();
		wfor(i, 1, n + 1)
		{
			qu.push(i);
			ans[i] = 0;
		}
		int q;
		cin >> q;
		int now = 0;
		while (now < n)
		{
			ans[++now] = qu.front();
			qu.pop();
			wfor(i, 0, m)
			{
				int temp = qu.front();
				qu.pop();
				qu.push(temp);
			}
		}
		wfor(i, 1, n + 1)
		{
			res[ans[i]] = i;
		}
		while (q--)
		{
			int need;
			cin >> need;
			// int i;
			// while (now < need)
			// {
			// 	ans[++now] = qu.front();
			// 	qu.pop();
			// 	wfor(i, 0, m)
			// 	{
			// 		int temp = qu.front();
			// 		qu.pop();
			// 		qu.push(temp);
			// 	}
			// }
			// while (ans[need] > now)
			// {
			// 	ans[++now] = qu.front();
			// 	qu.pop();
			// 	wfor(i, 0, m)
			// 	{
			// 		int temp = qu.front();
			// 		qu.pop();
			// 		qu.push(temp);
			// 	}
			// }
			cout << res[need] << endl;
		}
	}
	return 0;
}