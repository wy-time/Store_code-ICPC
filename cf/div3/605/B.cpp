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
	int q;
	cin >> q;
	while (q--)
	{
		char ans[100005] = {0};
		string s;
		cin >> s;
		int len = s.size();
		int i;
		int cnt[4] = {0};
		wfor(i, 0, len)
		{
			if (s[i] == 'L')
				cnt[0]++;
			else if (s[i] == 'R')
				cnt[1]++;
			else if (s[i] == 'U')
				cnt[2]++;
			else
				cnt[3]++;
		}
		int UD = min(cnt[2], cnt[3]);
		int LR = min(cnt[0], cnt[1]);
		int cntt = 0;
		if (LR == 0 || UD == 0)
		{
			if (LR == 0 && UD == 0)
				LR = UD = 0;
			else if (LR == 0)
				UD = 1;
			else if (UD == 0)
				LR = 1;
		}
		int rest = LR * 2 + UD * 2;
		wfor(i, 0, LR)
		{
			ans[cntt++] = 'R';
		}
		wfor(i, 0, UD)
		{
			ans[cntt++] = 'D';
		}
		wfor(i, 0, LR)
		{
			ans[cntt++] = 'L';
		}
		wfor(i, 0, UD)
		{
			ans[cntt++] = 'U';
		}
		cout << rest << endl;
		cout << ans << endl;
	}
	return 0;
}
