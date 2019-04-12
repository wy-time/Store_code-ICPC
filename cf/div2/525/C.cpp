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
	// std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
#ifdef ubuntu
	freopen("/home/time/debug/debug/in", "r", stdin);
	freopen("/home/time/debug/debug/out", "w", stdout);
#endif
	int n;
	int num[2005];
	int i;
	// cin>>n;
	scanf("%d", &n);
	wfor(i, 0, n)
	{
		// cin>>num[]
		scanf("%d", &num[i]);
	}
	printf("%d\n", n + 1);
	int j;
	mfor(i, n - 1, 0)
	{
		int t = num[i] % (n + 1);
		int add = ((i + 1) - t + (n + 1)) % (n + 1);
		printf("1 %d %d\n", i + 1, add);
		mfor(j, i, 0)
		{
			num[j] += add;
		}
	}
	printf("2 %d %d\n", n, n + 1);
	// wfor(i, 0, n)
	// {
	// 	num[i] %= n + 1;
	// 	printf("%d ", num[i]);
	// }
	return 0;
}
