#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
ll val[100005];
int pre[100005];
int findx(int x);
void join(int a, int b);
const ll mod = 1e9 + 7;
inline void read(ll &x) {
	char ch = getchar(); x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
int main()
{
	// std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
	int t;
	scanf("%d", &t);
	while (t--)
	{
		register int i;
		int n, m;
		scanf("%d %d", &n, &m);
		wfor(i, 1, n + 1)
		{
			pre[i] = i;
		}
		wfor(i, 1, n + 1)
		{
			read(val[i]);
		}
		wfor(i, 0, m)
		{
			ll a, b;
			read(a); read(b);
			join(a, b);
		}
		register int j;
		ll res = 0;
		wfor(i, 1, n)
		{
			wfor(j, i + 1, n + 1)
			{
				if (findx(i) == findx(j))
					res = (res + (max(val[i], val[j]) % mod * (val[i] & val[j]) % mod)) % mod;
			}
		}
		cout << res << endl;
	}
	return 0;
}
inline int findx(int x)
{
	int t = x;
	while (pre[t] != t)
	{
		t = pre[t];
	}
	int i = x;
	int j;
	while (pre[i] != t)
	{
		j = pre[i];
		pre[i] = t;
		i = j;
	}
	return t;
}
inline void join(int a, int b)
{
	int a1 = findx(a);
	int b1 = findx(b);
	pre[b1] = a1;
}