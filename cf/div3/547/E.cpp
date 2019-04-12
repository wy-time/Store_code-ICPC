#include <iostream>
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
const int maxn = 2e5 + 5;
int num[maxn];
ll slove(ll h, int n)
{
	int i;
	ll cnt = 0;
	wfor(i, 0, n)
	{
		h += num[i];
		cnt++;
		if (h <= 0)
			break;
	}
	return cnt;
}
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
	ll h, n;
	cin >> h >> n;
	int i;
	ll maxdamage = 0;
	ll alldamage = 0;
	unsigned long long ans = 0;
	wfor(i, 0, n)
	{
		cin >> num[i];
		alldamage += -num[i];
		maxdamage = max(alldamage, maxdamage);
	}
	if (alldamage <= 0 && h > maxdamage)
	{
		cout << -1 << endl;
	} else
	{
		if (maxdamage >= h)
		{
			ans = slove(h, n);
		} else
		{
			h -= maxdamage;
			ans += h / alldamage * n;
			h -= alldamage * (ans / n);
			if (h > 0)
			{
				h -= alldamage;
				ans += n;
			}
			h += maxdamage;
			ans += slove(h, n);
		}
		cout << ans << endl;
	}
	return 0;
}
