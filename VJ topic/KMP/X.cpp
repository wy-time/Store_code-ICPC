#include <cstring>
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
const int maxn = 110005;
char ss[maxn];
char s[2 * maxn];
int plen[2 * maxn];
int cal_plen();
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	while (cin >> ss)
	{
		int len = strlen(ss);
		int i;
		s[0] = '@';
		wfor(i, 1, len + 1)
		{
			s[(i << 1) - 1] = '#';
			s[i << 1] = ss[i - 1];
		}
		s[(i << 1) - 1] = '#';
		s[i << 1] = '$';
		s[i << 1 | 1] = '\0';
		int res = cal_plen();//最长子串的长度是半径减1，起始位置是中间位置减去半径再除以2。
		cout << res << endl;
	}
	return 0;
}
int cal_plen()
{
	int len = strlen(s);
	int i;
	int pos = 0; int mx = 0;
	int ans = 0;
	wfor(i, 1, len)
	{
		if (mx > i)
			plen[i] = min(plen[2 * pos - i], mx - i);
		else
			plen[i] = 1;
		while (s[i - plen[i]] == s[i + plen[i]])
			plen[i]++;
		if (i + plen[i] > mx)
		{
			mx = i + plen[i];
			pos = i;
		}
		ans = max(ans, plen[i]);
	}
	return ans - 1;
}