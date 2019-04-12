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
int bfs (int n, int k);
struct st
{
	int now;
	int step;
	st() {}
	st(int a, int b)
	{
		now = a;
		step = b;
	}
};
int vis[10005];
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n, k;
	cin >> n >> k;
	if (n == k)
		cout << 0 << endl;
	else
	{
		int res = bfs(n, k);
		cout << res << endl;
	}
	return 0;
}
int bfs (int n, int k)
{
	queue<st>qu;
	qu.push(st(n, 0));
	vis[n] = 1;
	while (!qu.empty())
	{
		st temp = qu.front();
		qu.pop();
		int a = temp.now + 1;
		int b = temp.now - 1;
		int c = temp.now * 2;
		if (a < k && !vis[a])
		{
			qu.push(st(a, temp.step + 1));
			vis[a] = 1;
		}
		if (b >= 0 && !vis[b])
		{
			qu.push(st(b, temp.step + 1));
			vis[b] = 1;
		}
		if (c  < k * 2 && !vis[c])
		{
			qu.push(st(c, temp.step + 1));
			vis[c] = 1;
		}
		if (c == k || a == k || b == k)
		{
			return temp.step + 1;
		}
	}
	return 0;
}