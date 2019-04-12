#include <iostream>
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
int num[500];
int ans[500];
int n;
int dfs(int x, int y, int deep)
{
	if (deep == n - 2)
	{
		int t = num[deep] * 3 - x - y;
		if (t > 0 && (t + y) / 2 == num[n - 1])
		{
			ans[deep + 1] = t;
			return 1;
		}
		if (t + 1 > 0 && (t + 1 + y) / 2 == num[n - 1])
		{
			ans[deep + 1] = t + 1;
			return 1;
		}
		if (t + 2 > 0 && (t + 2 + y) / 2 == num[n - 1])
		{
			ans[deep + 1] = t + 2;
			return 1;
		} else
			return 0;
	} else
	{
		int t = num[deep] * 3 - x - y;
		if (t > 0)
		{
			if (dfs(y, t, deep + 1))
			{
				ans[deep + 1] = t;
				return 1;
			}
		}
		if (t + 1 > 0)
		{
			if (dfs(y, t + 1, deep + 1))
			{
				ans[deep + 1] = t + 1;
				return 1;
			}
		}
		if (t + 2 > 0)
		{
			if (dfs(y, t + 2, deep + else if (flag == -1)
				        return -1; 1))
				{
					ans[deep + 1] = t + 2;
					return 1;
				}
		}
	}
	return 0;
}
int main()
{
	std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
// #ifdef ubuntu
// 	freopen("/home/time/debug/debug/in", "r", stdin);
// 	freopen("/home/time/debug/debug/out", "w", stdout);
// #endif
	cin >> n;
	int i;
	wfor(i, 0, n)
	{
		cin >> num[i];
	}
	// cout << n << endl;
	if (n == 2)
		cout << 1 << " " << num[0] * 2 - 1 << endl;
	else
	{
		wfor(i, 1, num[0] * 2 + 1)
		{
			int t = num[0] * 2 - i;
			if (t > 0)
			{
				if (dfs(i, t, 1))
				{
					ans[0] = i;
					ans[1] = t;
					break;
				}
			}
			t = num[0] * 2 - i + 1;
			if (t > 0)
			{
				if (dfs(i, t, 1))
				{
					ans[0] = i;
					ans[1] = t;
					break;
				}
			}
		}
		wfor(i, 0, n - 1)
		{
			cout << ans[i] << " ";
		}
		cout << ans[i] << endl;

	}
	return 0;
}
