#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
void read(int &x) {
	char ch = getchar(); x = 0;
	int flag = 1;
	if (ch == '-')
		flag = -1;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
	x *= flag;
}
const int maxn = 500005;
const int INF = 0x7f7f7f7f;
int plen[2 * maxn];
char s[2 * maxn];
char ss[maxn];
int sum[maxn];
void cal_plen();
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	// read(t);
	while (t--)
	{
		int val[30] = {0};
		int i;
		wfor(i, 0, 26)
		{
			cin >> val[i];
			// read(val[i]);
		}
		cin >> ss;
		// gets(ss);
		int len = strlen(ss);
		if (len == 1)
		{
			cout << 0 << endl;
			continue;
		}
		s[0] = '$';
		wfor(i, 1, len + 1)
		{
			s[(i << 1) - 1] = '#';
			s[i << 1] = ss[i - 1];
		}
		s[(i << 1) - 1] = '#';
		s[i << 1] = '@';
		s[i << 1 | 1] = '\0';
		sum[0] = (val[ss[0] - 'a']);
		wfor(i, 1, len)
		{
			sum[i] = sum[i - 1] + val[ss[i] - 'a'];
		}
		cal_plen();
		int ans = -INF;
		wfor(i, 1, len )
		{
			int temp = 0;
			if (plen[i + 1] - 1 == i)
				temp += sum[i - 1];
			if (plen[i + len + 1] - 1 == len - i)
				temp += sum[len - 1] - sum[i - 1];
			ans = max(ans, temp);
		}
		cout << ans << endl;
		// printf("%d\n", ans);
	}
	return 0;
}
void cal_plen()
{
	int len = strlen(s);
	int i;
	int pos = 0, mx = 0;
	memset(plen, 0, sizeof(plen));
	wfor(i, 1, len)
	{
		if (mx > i)
			plen[i] = min(plen[2 * pos - i], mx - i);
		else
			plen[i] = 1;
		while (s[i + plen[i]] == s[i - plen[i]])
			plen[i]++;
		if (plen[i] + i > mx)
		{
			pos = i;
			mx = plen[i] + i;
		}
	}
}