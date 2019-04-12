#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn = 1000005;
int plen[2 * maxn];
char s[2 * maxn];
char ss[maxn];
int cal_plen();
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	cin >> ss
	    if (strcmp(ss, "END") == 0)
		    break;
	int len = strlen(ss);
	int i;
	s[0] = '$';
	wfor(i, 1, len + 1)
	{
		s[(i << 1) - 1] = '#';
		s[i << 1] = ss[i - 1];
	}
	s[(i << 1) - 1] = '#';
	s[i << 1] = '@';
	s[i << 1 | 1] = '\0';
	int res = cal_plen();
	cout << res << endl;
	return 0;
}
int cal_plen()
{
	int len = strlen(s);
	int i;
	int mx = 0, pos = 0;
	int ans = 0;
	wfor(i, 1, len)
	{
		if (mx > i)
			plen[i] = min(plen[2 * pos - i], mx - i);
		else
			plen[i] = 1;
		while (s[i - plen[i]] == s[i + plen[i]])
			plen[i]++;
		if (plen[i] + i > mx)
		{
			mx = plen[i] + i;
			pos = i;
		}
		ans = max(ans, plen[i]);
	}
	return ans - 1;
}