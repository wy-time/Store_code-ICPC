#include <iostream>
#include <algorithm>
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
const int maxn = 1e5 + 5;
struct st
{
	int a;
	int b;
};
st num[maxn];
struct rule
{
	bool operator()(const st &q, const st &p)
	{
		return q.b < p.b;
	}
};
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
		cin >> num[i].a;
	}
	wfor(i, 0, n)
	{
		cin >> num[i].b;;
	}
	int now = 0;
	int rest = 0;
	int flag = 1;
	sort(num, num + n, rule());
	wfor(i, 0, n)
	{
		if (num[i].a + now - rest > num[i].b)
		{
			flag = 0;
			break;
		} else
		{
			rest = num[i].b + rest - num[i].a - now;
			now = num[i].b + 2;
		}
	}
	if (flag)
	{
		cout << "YES" << endl;
	} else
		cout << "NO" << endl;
	return 0;
}
