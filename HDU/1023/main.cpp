#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
//ll comb(int a,int b);
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n;
	unsigned long long ans[115] = {0};
	ans[3] = 1;
	ans[2] = 1;
	int i;
	wfor(i, 4, 104)
	{
		int t = i;
		wfor(t, 0, i - 2)
		{
			ans[i] += ans[2 + t] * ans[i - t - 1];
		}
	}
	while (cin >> n)
	{
		cout << ans[n + 2] << endl;
	}
	return 0;
}
// ll comb(int a,int b)
// {
// 	int i;
// 	ll temp1=1,temp2=0;
// 	wfor(i,0,b)
// 	{
// 		temp1*=
// 	}
// }