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
	ll mod = 998244353;
	ll fib[200];
	fib[1] = 0;
	fib[2] = 1;
	int i;
	wfor(i, 3, 200)
	{
		fib[i] = fib[i - 1] * 3 + fib[i - 2] * 2;
		fib[i] %= mod;
	}
	wfor(i, 1, 200)
	{
		cout << fib[i] << " " << i - 1 << " " << ((fib[i]*fib[i] % mod) ^ (i - 1)) << endl;
	}
	return 0;
}