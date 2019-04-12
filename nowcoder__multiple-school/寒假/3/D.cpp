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
struct st
{
	int time;
	int b;
};
struct rule
{
	bool operator()(const st &a, const st &c)
	{
		return a.time * c.b < a.b * c.time;
	}
};
st info[100005];
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
		cin >> info[i].time >> info[i].b;
	}
	sort(info, info + n, rule());
	ll ans = 0;
	ll time = info[0].time;
	wfor(i, 1, n)
	{
		ans += time * info[i].b;
		time += info[i].time;
	}
	cout << ans << endl;
	return 0;
}
