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
const int maxn = 1e7 + 5; // 表长
ll prime[maxn / 10];
int pNum = 0;    // prime记录素数，pNum记录素数个数
bool p[maxn] = {false};        // p记录当前数是否被筛去
void eulerSieve(int n)    // 查找记录2-n的素数
{
	for (int i = 2; i <= n; i++)
	{
		if (p[i] == false)  // 如果未被筛过，则为素数
			prime[pNum++] = i;
		for (int j = 0; j < pNum; j++)
		{
			if (i * prime[j] > n)      // 当要标记的合数超出范围时跳出
				break;
			p[i * prime[j]] = true;     // 将已经记录的素数的倍数进行标记
			if (i % prime[j] == 0)      //关键步骤
				break;
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
	eulerSieve(maxn);
	ll t;
	cin >> t;
	// read(t);
	ll casecnt = 0;
	while (t--)
	{
		casecnt++;
		ll n;
		cin >> n;
		ll t = n;
		ll ans = 1;
		for (int i = 0; i < pNum && prime[i]*prime[i] <= n; i++)
		{
			ll cnt = 0;
			while (t % prime[i] == 0) cnt++, t /= prime[i];
			ans *= (2 * cnt + 1);
		}
		if (t > 1) ans *= 3;
		ans = ans / 2 + 1;
		cout << "Case " << casecnt << ": " << ans << endl;
	}
	return 0;
}

// #include<cstdio>
// #include<iostream>
// #include<cstring>
// #include<algorithm>
// #include<cmath>
// using namespace std;

// typedef long long ll;
// const int N = 1e7 + 100;
// ll prime[N / 10];
// bool vis[N];
// int tot;
// void ini()
// {
// 	for (ll i = 2; i < N; i++)
// 		if (!vis[i])
// 		{
// 			prime[tot++] = i;
// 			for (ll j = i * i; j < N; j += i) vis[j] = 1;
// 		}
// }
// int main()
// {
// 	ini();
// 	int T;
// 	scanf("%d", &T);
// 	for (int cas = 1; cas <= T; cas++)
// 	{
// 		ll n;
// 		cin >> n;
// 		ll t = n;
// 		ll ans = 1;
// 		for (int i = 0; i < tot && prime[i]*prime[i] <= n; i++)
// 		{
// 			ll cnt = 0;
// 			while (t % prime[i] == 0) cnt++, t /= prime[i];
// 			ans *= (2 * cnt + 1);
// 		}
// 		if (t > 1) ans *= 3;
// 		ans = ans / 2 + 1;
// 		cout << "Case " << cas << ": " << ans << endl;
// 	}
// 	return 0;
// }
