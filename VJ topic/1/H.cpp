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
struct st
{
	int a;
	int b;
	int cnt;
	int path[1005];
	st() {}
	st(int c, int d)
	{
		a = c;
		b = d;
		cnt = 0;
	}
};
int vis[105][105];
st bfs(int a, int b, int aim);
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int a, b, c;
	cin >> a >> b >> c;
	st res = bfs(a, b, c);
	if (res.a == -1 && res.b == -1)
	{
		cout << "impossible" << endl;
	} else
	{
		cout << res.cnt << endl;
		int i = 0;
		wfor(i, 0, res.cnt)
		{
			switch (res.path[i])
			{
			case 1:
				cout << "FILL(" << 1 << ")" << endl;
				break;
			case 2:
				cout << "FILL(" << 2 << ")" << endl;
				break;
			case 3:
				cout << "DROP(" << 1 << ")" << endl;
				break;
			case 4:
				cout << "DROP(" << 2 << ")" << endl;
				break;
			case 5:
				cout << "POUR(" << 1 << "," << 2 << ")" << endl;
				break;
			case 6:
				cout << "POUR(" << 2 << "," << 1 << ")" << endl;
				break;
			}
		}
	}
	return 0;
}
st bfs(int a, int b, int aim)
{
	queue<st>qu;
	qu.push(st(0, 0));
	vis[0][0] = 1;
	while (!qu.empty())
	{
		st temp = qu.front();
		qu.pop();
		if (temp.a == aim || temp.b == aim)
			return temp;
		if (temp.a != a)
		{
			st now;
			now.a = a;
			now.b = temp.b;
			memmove(now.path, temp.path, sizeof(temp.path));
			now.path[temp.cnt] = 1;
			now.cnt = temp.cnt + 1;
			if (!vis[now.a][now.b])
			{
				qu.push(now);
				vis[now.a][now.b] = 1;
			}
		}
		if (temp.b != b)
		{
			st now;
			now.a = temp.a;
			now.b = b;
			memmove(now.path, temp.path, sizeof(temp.path));
			now.path[temp.cnt] = 2;
			now.cnt = temp.cnt + 1;
			if (!vis[now.a][now.b])
			{
				qu.push(now);
				vis[now.a][now.b] = 1;
			}
		}
		if (temp.a != 0)
		{
			st now;
			now.a = 0;
			now.b = temp.b;
			memmove(now.path, temp.path, sizeof(temp.path));
			now.path[temp.cnt] = 3;
			now.cnt = temp.cnt + 1;
			if (!vis[now.a][now.b])
			{
				qu.push(now);
				vis[now.a][now.b] = 1;
			}
		}
		if (temp.b != 0)
		{
			st now;
			now.a = temp.a;
			now.b = 0;
			memmove(now.path, temp.path, sizeof(temp.path));
			now.path[temp.cnt] = 4;
			now.cnt = temp.cnt + 1;
			if (!vis[now.a][now.b])
			{
				qu.push(now);
				vis[now.a][now.b] = 1;
			}
		}
		if (temp.b != b && temp.a != 0)
		{
			st now;
			if (b - temp.b > temp.a)
			{
				now.b = temp.a + temp.b;
				now.a = 0;
			} else
			{
				now.b = b;
				now.a = temp.a - b + temp.b;
			}
			memmove(now.path, temp.path, sizeof(temp.path));
			now.path[temp.cnt] = 5;
			now.cnt = temp.cnt + 1;
			if (!vis[now.a][now.b])
			{
				qu.push(now);
				vis[now.a][now.b] = 1;
			}
		}
		if (temp.a != a && temp.b != 0)
		{
			st now;
			if (a - temp.a > temp.b)
			{
				now.a = temp.a + temp.b;
				now.b = 0;

			} else
			{
				now.a = a;
				now.b = temp.b - a + temp.a;
			}
			memmove(now.path, temp.path, sizeof(temp.path));
			now.path[temp.cnt] = 6;
			now.cnt = temp.cnt + 1;
			if (!vis[now.a][now.b])
			{
				qu.push(now);
				vis[now.a][now.b] = 1;
			}
		}
	}
	return st(-1, -1);
}