#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
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
	int n, m, s, step;
	st() {}
	st(int a, int b, int c, int d)
	{
		s = a;
		n = b;
		m = c;
		step = d;
	}
};
struct st2
{
	int n, m, s;
	st2() {}
	st2(int a, int b, int c)
	{
		s = a;
		n = b;
		m = c;
	}
	bool operator <(st2 o)const
	{
		if (s == o.s)
		{
			if (n == o.n)
				return m > o.m;
			else
				return n > o.n;
		} else
			return s > o.s;
	}
};
int bfs();
void slove(int &a, int &b, int a1, int b1);
int s, n, m;
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	while (cin >> s >> n >> m)
	{
		if (s == 0 && n == 0 && m == 0)
			break;
		int res = bfs();
		if (res == -1)
			cout << "NO" << endl;
		else
			cout << res << endl;
	}
	return 0;
}
int bfs()
{
	queue<st>qu;
	qu.push(st(s, 0, 0, 0));
	set<st2>ma;
	ma.insert(st2(s, 0, 0));
	while (!qu.empty())
	{
		st temp = qu.front();
		qu.pop();
		if ((temp.n == temp.m && temp.n != 0 && temp.n * 2 == s) || (temp.s == temp.n && temp.n != 0 && temp.n * 2 == s) || (temp.s == temp.m && temp.m != 0 && temp.m * 2 == s))
			return temp.step;
		st now = temp;
		slove(now.s, now.n, s, n);
		if (ma.count(st2(now.s, now.n, now.m)) == 0)
		{
			now.step = temp.step + 1;
			qu.push(now);
			ma.insert(st2(now.s, now.n, now.m));
		}
		now = temp;
		slove(now.s, now.m, s, m);
		if (ma.count(st2(now.s, now.n, now.m)) == 0)
		{
			now.step = temp.step + 1;
			qu.push(now);
			ma.insert(st2(now.s, now.n, now.m));
		}
		now = temp;
		slove(now.n, now.m, n, m);
		if (ma.count(st2(now.s, now.n, now.m)) == 0)
		{
			now.step = temp.step + 1;
			qu.push(now);
			ma.insert(st2(now.s, now.n, now.m));
		}
		now = temp;
		slove(now.m, now.n, m, n);
		if (ma.count(st2(now.s, now.n, now.m)) == 0)
		{
			now.step = temp.step + 1;
			qu.push(now);
			ma.insert(st2(now.s, now.n, now.m));
		}
		now = temp;
		slove(now.m, now.s, m, s);
		if (ma.count(st2(now.s, now.n, now.m)) == 0)
		{
			now.step = temp.step + 1;
			qu.push(now);
			ma.insert(st2(now.s, now.n, now.m));
		}
		now = temp;
		slove(now.n, now.s, n, s);
		if (ma.count(st2(now.s, now.n, now.m)) == 0)
		{
			now.step = temp.step + 1;
			qu.push(now);
			ma.insert(st2(now.s, now.n, now.m));
		}
	}
	return -1;
}
void slove(int &a, int &b, int a1, int b1)
{
	if (a >= b1 - b)
	{
		a -= (b1 - b);
		b = b1;
	} else
	{
		b += a;
		a = 0;
	}
}
