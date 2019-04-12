#include <iostream>
#include <set>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
void read(int &x) {
	char ch = getchar(); x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
const int maxn = 150000;
int ans[maxn];
int slove(int n)
{
	// set<int> st;
	int i;
	wfor(i, 0, 10)
	{
		if (n == 1)
			break;
		int tmp = 0;
		while (n)
		{
			tmp += (n % 10) * (n % 10);
			n /= 10;
		}
		n = tmp;
		// if (st.find(tmp) != st.end())
		// 	return 0;
		// else
		// {
		// 	st.insert(tmp);
		// 	n = tmp;
		// }
	}
	if (n == 1)
		return 1;
	else
		return 0;
}
int main()
{
	// std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
// #ifdef ubuntu
// 	freopen("/home/time/debug/debug/in", "r", stdin);
// 	freopen("/home/time/debug/debug/out", "w", stdout);
// #endif
	int n;
	int i = 1;
	int cnt = 0;
	while (cnt < maxn)
	{
		if (slove(i))
			ans[cnt++] = i;
		i++;
	}
	int  t;
	// cin >> t;
	read(t);
	while (t--)
	{
		read(n);
		// cout << ans[n] << endl;
		printf("%d\n", ans[n - 1]);
	}
	return 0;
}