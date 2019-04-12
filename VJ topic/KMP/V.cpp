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
const int maxn = 1000010;
int s[2 * maxn];
int plen[2 * maxn];
int num[maxn];
int cal_plen(int len);
int main()
{
	std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int i;
		wfor(i, 0, n)
		{
			cin >> num[i];
		}
		s[0] = 300;
		wfor(i, 1, n + 1)
		{
			s[(i << 1) - 1] = 50;
			s[i << 1] = num[i - 1];
		}
		s[(i << 1) - 1] = 50;
		s[i << 1] = 301;
		int res = cal_plen(2 * n + 1);
		cout << res << endl;
	}
	return 0;
}
int cal_plen(int len)
{
	int i;
	int pos = 0;
	int mx = 0;
	int last = 1;
	int ans = 0;
	wfor(i, 1, len)
	{
		if (i < mx)
			plen[i] = min(plen[2 * pos - i], mx - i);
		else
			plen[i] = 1;
		last = i;
		// while (s[i - plen[i]] == s[i + plen[i]] && s[i - plen[i]] <= s[i - plen[i] + 2])
		while (s[i - plen[i]] == s[i + plen[i]] && (s[i - plen[i]] <= s[last % 2 == 0 ? last : last + 1]))
		{
			plen[i]++;
			last --;
		}
		if (plen[i] + i > mx)
		{
			mx = plen[i] + i;
			pos = i;
		}
		ans = max(ans, plen[i]);
	}
	return ans - 1;
}

