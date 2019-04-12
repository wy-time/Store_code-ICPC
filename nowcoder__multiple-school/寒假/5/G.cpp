// #include <iostream>
// #include <cstdio>
// using namespace std;
// typedef long long ll;
// #define wfor(i,j,k) for(i=j;i<k;++i)
// #define mfor(i,j,k) for(i=j;i>=k;--i)
// // void read(int &x) {
// // 	char ch = getchar(); x = 0;
// // 	for (; ch < '0' || ch > '9'; ch = getchar());
// // 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// // }
// const int maxn = 1e7 + 2;
// int ans[maxn];
// int prime[maxn];
// void getprime()
// {
// 	int i;
// 	wfor(i, 2, maxn)
// 	{
// 		if (!prime[i])
// 		{
// 			prime[++prime[0]] = i;
// 		}
// 		int j;
// 		for (j = 1; j <= prime[0] && prime[j]*i < maxn; j++)
// 		{
// 			prime[i * prime[j]] = 1;
// 			if (i % prime[j] == 0)
// 				break;
// 		}
// 	}
// }
// void init()
// {
// 	// getprime();
// 	int i;
// 	int j;
// 	ans[1] = 1;
// 	wfor(i, 2, maxn)
// 	{
// 		int cnt = 0;
// 		int num = 1;
// 		for (j = 1; j <= prime[0] && prime[j] <= i; j++)
// 		{
// 			if (i % prime[j] == 0)
// 			{
// 				while (i % prime[j] == 0)
// 				{
// 					i /= prime[j];
// 					cnt++;
// 				}
// 			}
// 			num *= (cnt + 1);
// 		}
// 		if (num < maxn || ans[num] == 0)
// 			ans[num] = i;
// 		if (ans[23] != 0)
// 			return;
// 	}
// }
// int main()
// {
// 	std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
// #ifdef ubuntu
// 	freopen("/home/time/debug/debug/in", "r", stdin);
// 	freopen("/home/time/debug/debug/out", "w", stdout);
// #endif
// 	int t, n;
// 	cin >> t;
// 	getprime();
// 	init();
// 	while (t--)
// 	{
// 		cin >> n;
// 		cout << ans[n] << endl;
// 	}
// 	return 0;
// }
#include <cstdio>
#include <algorithm>
#include <cmath>

long long tmp[100000], cnt, rec[100000];
long long prime[30] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 39, 41, 43, 47};
double ans, LOG[30];

void DFS(long long pos, long long val, long long MAX, double clog) {
	if (clog > ans) return;
	if (val == 1) {
		cnt = pos;
		ans = clog;
		for (long long i = 1; i < pos; i++)
			rec[i] = tmp[i];
		return;
	}

	for (long long i = 1; i * i <= val && i <= MAX; i++) {
		if (val % i == 0) {
			if (i != 1) {
				tmp[pos] = i;
				DFS(pos + 1, val / i, i, clog + LOG[pos] * (i - 1));
			}
			if (val / i <= MAX && val / i != i) {
				tmp[pos] = val / i;
				DFS(pos + 1, i, val / i, clog + LOG[pos] * (val / i - 1));
			}
		}
	}
}

int main() {
	long long N;
	for (long long i = 0; i < 16; i++)
		LOG[i] = log((double)prime[i]);
	while (scanf("%lld", &N) != EOF) {
		ans = 0x7f7f7f7f;
		DFS(1, N, N, 0);
		long long M = 1;
		for (long long i = 1; i < cnt; i++)
			for (long long j = 1; j < rec[i]; j++)
				M *= prime[i];
		printf("%lld\n", M);
	}
	return 0;
}

