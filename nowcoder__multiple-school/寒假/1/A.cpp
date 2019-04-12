#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
struct st
{
	ll op;
	ll x;
};
st op[500];
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
	ll n, x;
	ll i;
	cin >> n >> x;
	wfor(i, 0, n)
	{
		cin >> op[i].op >> op[i].x;
	}
	mfor(i, n - 1, 0)
	{
		if (op[i].op == 1)
		{
			x -= op[i].x;
		} else if (op[i].op == 2)
		{
			x += op[i].x;
		} else if (op[i].op == 3)
		{
			x /= op[i].x;
		} else
		{
			x *= op[i].x;
		}
	}
	cout << x << endl;
	return 0;
}
