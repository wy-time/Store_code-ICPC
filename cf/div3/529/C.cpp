#include <iostream>
#include <queue>
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
	int n, k;
	cin >> n >> k;
	queue <int>qu;
	int flag = 1;
	int s = n;
	while (n)
	{
		qu.push(n & -n);
		n -= n & -n;
	}
	if (qu.size() > k || k > s)
		flag = 0;
	int cnt = 0;
	if (flag)
	{
		while (cnt + qu.size() < k)
		{
			int t = qu.front();
			if (t > 1)
			{
				qu.pop();
				qu.push(t >> 1);
				qu.push(t >> 1);
			} else
			{
				qu.pop();
				cnt++;
			}
		}
		cout << "YES" << endl;
		while (cnt--)
		{
			cout << 1 << " ";
		}
		while (!qu.empty())
		{
			cout << qu.front() << " ";
			qu.pop();
		}
	} else
		cout << "NO" << endl;
	return 0;
}