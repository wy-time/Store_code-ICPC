#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
char s[15];
int res[5];
int vis[30];
void dfs(int aim, int step, int *ans);
int flag;
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int aim;
	while (cin >> aim >> s)
	{
		if (aim == 0 && strcmp(s, "END") == 0)
			break;
		memset(vis, 0, sizeof(vis));
		memset(res, 0, sizeof(res));
		flag = 0;
		int ans[5] = {0};
		sort(s, s + strlen(s));
		dfs(aim, 0, ans);
		if (flag)
		{
			int i;
			wfor(i, 0, 5)
			{
				cout << (char)(res[i] + 'A' - 1);
			}
			cout << endl;
		} else
			cout << "no solution" << endl;
	}
	return 0;
}
void dfs(int aim, int step, int *ans)
{
	if (step == 5)
	{
		int t = ans[0] - ans[1] * ans[1] + ans[2] * ans[2] * ans[2] - ans[3] * ans[3] * ans[3] * ans[3] + ans[4] * ans[4] * ans[4] * ans[4] * ans[4];
		if (t == aim)
		{
			flag = 1;
			int i;
			wfor(i, 0, 5)
			{
				res[i] = ans[i];
			}
		}
		return;
	}
	int i;
	int len = strlen(s);
	wfor(i, 0, len)
	{
		if (!vis[s[i] - 'A'] /*&& s[i] - 'A' + 1 >= res[step]*/)
		{
			ans[step] = s[i] - 'A' + 1;
			vis[s[i] - 'A'] = 1;
			dfs(aim, step + 1, ans);
			vis[s[i] - 'A'] = 0;
		}
	}
}
