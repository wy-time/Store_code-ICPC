#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
void read(int &x) {
	char ch = getchar(); x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
map<int, int>ma;
void add(int number)
{
	ma.insert(make_pair(number, number + 1));
	int temp = number;
	while (ma.count(temp) != 0)
	{
		temp = ma[temp];
	}
	while (ma[number] != temp)
	{
		int j = ma[number];
		ma[number] = temp;
		number = j;
	}
}
int find(int number)
{
	int ans = number;
	while (ma.count(ans) != 0)
		ans = ma[ans];
	return ans;
}
int main()
{
	// std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
#ifdef ubuntu
	freopen("/home/time/debug/debug/in", "r", stdin);
	freopen("/home/time/debug/debug/out", "w", stdout);
#endif
	int n, q;
	read(n), read(q);
	while (q--)
	{
		int op, pos;
		read(op);
		read(pos);
		if (op == 1)
		{
			add(pos);
		} else
		{
			int ans = find(pos);
			// cout << ans << endl;
			printf("%d\n", ans);
		}
	}
	return 0;
}
