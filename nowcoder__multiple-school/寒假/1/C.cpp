#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
// int num[5000];
// int ans = 0;
// struct st
// {
// 	int p;
// 	int hp;
// 	st() {}
// 	st(int a, int b)
// 	{
// 		p = a;
// 		hp = b;
// 	}
// };
// int lowbit(int a, int b)
// {
// 	int lasta = 0, lastb = 0;
// 	while (a)
// 	{
// 		lasta = a & -a;
// 		a -= a & -a;
// 	}
// 	while (b)
// 	{
// 		lastb = b & -b;
// 		b -= b & -b;
// 	}
// 	if (lasta <= lastb)
// 	{
// 		return 1;
// 	} else
// 	{
// 		return 0;
// 	}
// }
// void bfs(int beg, int n)
// {
// 	queue<st>qu;
// 	qu.push(st(beg, beg));
// 	while (!qu.empty())
// 	{
// 		st t = qu.front();
// 		qu.pop();
// 		int i;
// 		wfor(i, 0, n)
// 		{
// 			if (num[i] < t.p)
// 			{
// 				int temp = t.hp ^ num[i];
// 				if ((temp > ans || lowbit(ans, temp)) && num[i] > num[n - 1])
// 				{
// 					if (num[i] != num[n - 1])
// 					{
// 						qu.push(st(num[i], temp));
// 					}
// 					ans = max(ans, temp);
// 				}
// 			}
// 		}
// 	}
// }
const int MAX_BASE = 59;
int num[5000];
int a[5000];
int b[59 + 3];
void cal(int n) {
	for (int i = 0; i < n; ++i)
		for (int j = MAX_BASE; j >= 0; --j)
			if (a[i] >> j & 1) {
				if (b[j]) a[i] ^= b[j];
				else {
					b[j] = a[i];
					for (int k = j - 1; k >= 0; --k) if (b[k] && (b[j] >> k & 1)) b[j] ^= b[k];
					for (int k = j + 1; k <= MAX_BASE; ++k) if (b[k] >> j & 1) b[k] ^= b[j];
					break;
				}
			}
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
	int i;
	wfor(i, 0, n)
	{
		cin >> num[i];
	}
	if (num[n - 1] >= num[0])
	{
		cout << -1 << endl;
	} else
	{
		a[0] = num[0] ^ num[n - 1];
		int cnt = 1;
		wfor(i, 1, n - 1)
		{
			if (num[i] > num[n - 1] && num[i] < num[0])
			{
				a[cnt++] = num[i];
			}
		}
		cal(n);
		int ans = 0;
		mfor(i, 59, 0)
		{
			ans ^= b[i];
		}
		// ans = num[0] ^ num[n - 1];
		// bfs(num[0], n);
		cout << ans << endl;
	}
	return 0;
}
