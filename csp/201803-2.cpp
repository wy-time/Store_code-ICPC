#include <iostream>
#include <cstdio>
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
	int id;
	int pos;
	int add;
};
struct rule
{
	bool operator()(const st a, const st b)
	{
		return a.pos < b.pos;
	}
};
struct rule22
{
	bool operator()(const st a, const st b)
	{
		return a.id < b.id;
	}
};
st num[200];
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
	int n, l, t;
	cin >> n >> l >> t;
	int i;
	wfor(i, 0, n)
	{
		cin >> num[i].pos;
		num[i].id = i + 1;
		num[i].add = 1;
	}
	while (t--)
	{
		sort(num, num + n, rule());
		st last = num[0];
		if (num[0].pos == l && num[0].add == 1)
			num[0].add *= -1;
		else if (num[0].pos == 0 && num[0].add == -1)
			num[0].add *= -1;
		wfor(i, 1, n)
		{
			if (num[i].pos == last.pos)
			{
				num[i].add *= -1;
				num[i - 1].add *= -1;
			}
			last = num[i];
			if (num[i].pos == l && num[i].add == 1)
				num[i].add *= -1;
			else if (num[i].pos == 0 && num[i].add == -1)
				num[i].add *= -1;
		}
		wfor(i, 0, n)
		{
			num[i].pos += num[i].add;
		}
	}
	sort(num, num + n, rule22());
	wfor(i, 0, n - 1)
	{
		cout << num[i].pos << " ";
	}
	cout << num[i].pos << endl;
	return 0;
}
