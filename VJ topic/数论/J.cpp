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
const int maxn = 1e4 + 5;
int prime[maxn + 1];
void getprime()
{
	int i;
	wfor(i, 2, maxn + 1)
	{
		if (!prime[i])
			prime[++prime[0]] = i;
		int j;
		for (j = 1; j <= prime[0] && prime[j]*i <= maxn; j++)
		{
			prime[i * prime[j]] = 1;
			if (prime[j] % i == 0)
				break;
		}
	}
}
struct st
{
	int num;
	int factor;
};
struct rule1
{
	bool operator()(const st &a, const st &b)
	{
		if (a.factor != b.factor)
			return a.factor < b.factor;
		else
			return a.num > b.num;
	}
};
// struct rule2
// {
// 	bool operator()(const st &a, const st &b)
// 	{
// 		return a.num < b.num;
// 	}
// };
st num[1005];
void init()
{
	getprime();
	int i;
	num[1].num = 1;
	num[1].factor = 1;
	wfor(i, 2, 1001)
	{
		int t = i;
		int j;
		int fact = 1;
		for (j = 1; j <= prime[0] && prime[j] <= i; j++)
		{
			int ans = 0;
			while (t % prime[j] == 0)
			{
				ans++;
				t /= prime[j];
			}
			fact *= ans + 1;
		}
		num[i].num = i;
		num[i].factor = fact;
	}
	sort(num + 1, num + 1001, rule1());
	// wfor(i, 1, 1001)
	// {
	// 	num[i].id = i;
	// }
	// sort(num + 1, num + 1001, rule2());
}
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	init();
	int casecnt = 0;
	while (t--)
	{
		casecnt++;
		int n;
		cin >> n;
		cout << "Case " << casecnt << ": " << num[n].num << endl;
	}
	return 0;
}
