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
const int maxn = 200005;
char ss[maxn];
char s[2 * maxn];
int plen[2 * maxn];
void cal_plen();
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	char op;
	while (cin >> op >> ss)
	{
		int change = 'a' - op;
		int len = strlen(ss);
		int i;
		s[0] = '@';
		wfor(i, 1, len + 1)
		{
			s[(i << 1) - 1] = '#';
			s[i << 1] = (ss[i - 1] + change - 'a' + 26) % 26 + 'a';
			ss[i - 1] = (ss[i - 1] + change - 'a' + 26) % 26 + 'a';
		}
		s[(i << 1) - 1] = '#';
		s[i << 1] = '$';
		s[i << 1 | 1] = '\0';
		cal_plen();
		int pos = -1;
		int mx = 0;
		wfor(i, 1, 2 * len + 1)
		{
			if (mx < plen[i])
			{
				pos = i;
				mx = plen[i];
			}
		}
		if (mx - 1 >= 2)
		{
			cout << ((pos - mx) / 2) << " " << ((pos - mx) / 2) + mx - 2 << endl;
			wfor(i, ((pos - mx) / 2), ((pos - mx) / 2) + mx - 1)
			{
				cout << ss[i];
			}
			cout << endl;
		} else
			cout << "No solution!" << endl;
	}
	return 0;
}
void cal_plen()
{
	int len = strlen(s);
	int i;
	int mx = 0; int pos = 0;
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
	}
}
