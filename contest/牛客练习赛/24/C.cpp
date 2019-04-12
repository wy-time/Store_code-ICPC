#include <iostream>
#ifdef test
#include <cstdio>
#endif
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
const int maxn = 1000005;
int r[maxn];
int b[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	int i;
	int cnt1 = 0, cnt2 = 0;
	wfor(i, 1, n + 1)
	{
		char s;
		cin >> s;
		if (s == 'R')
			r[cnt1++] = i;
		else
			b[cnt2++] = i;
	}
	wfor(i, 0, m)
	{
		char s;
		int t;
		cin >> s >> t;
		if (s == 'R')
		{
			if (t - 1 >= cnt1)
				cout << -1 << endl;
			else
				cout << r[t - 1] << endl;
		} else
		{
			if (t - 1 >= cnt2)
				cout << -1 << endl;
			else
				cout << b[t - 1] << endl;
		}
	}
	return 0;
}
