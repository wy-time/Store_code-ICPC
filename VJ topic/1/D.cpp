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
int ma[20][20];
int cnt;
struct st
{
	int x;
	int y;
	st(int a, int b)
	{
		x = a;
		y = b;
	}
};
void dfs(int aim, int step, st now);
int n, m;
int ans[20][20];
bool isgood = false;
int res[20][20];
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	cin >> n >> m;
	int i, j;
	wfor(i, 0, n)
	{
		wfor(j, 0, m)
		{
			cin >> ma[i][j];
			if (ma[i][j] == 1)
				cnt++;
		}
	}
	memset(ans, 0, sizeof(ans));
	wfor(i, 0, n + m)
	{
		if (!isgood)
		{
			dfs(i, 0, st(0, 0));
		} else
			break;
	}
	if (isgood)
	{
		wfor(i, 0, n)
		{
			wfor(j, 0, m - 1)
			{
				cout << res[i][j] << " ";
			}
			cout << res[i][j] << endl;
		}
	} else
		cout << "IMPOSSIBLE" << endl;
	return 0;
}
void dfs(int aim, int step, st now)
{
	int i, j;
	if (step == aim)
	{
		if (cnt != 0)
			return;
		else
		{
			if (isgood == false)
			{
				wfor(i, 0, n)
				wfor(j, 0, m)
				{
					res[i][j] = ans[i][j];
				}
			} else
			{
				bool a = false;
				wfor(i, 0, n)
				wfor(j, 0, m)
				{
					if (res[i][j] > ans[i][j])
					{
						a = true;
					}
				}
				if (a)
				{
					wfor(i, 0, n)
					wfor(j, 0, m)
					{
						res[i][j] = ans[i][j];
					}
				}
			}
			isgood = true;
		}
		return ;
	}
	wfor(i, 0, n)
	{
		wfor(j, 0, m)
		{
			if (i > now.x || (i == now.x && j >= now.y))
			{
				int redu = 0;
				redu += ma[i][j] == 0 ? -1 : 1;
				ma[i][j] += ma[i][j] == 0 ? 1 : -1;
				if (i - 1 >= 0)
				{
					redu += ma[i - 1][j] == 0 ? -1 : 1;
					ma[i - 1][j] += ma[i - 1][j] == 0 ? 1 : -1;
				}
				if (i + 1 < n)
				{
					redu += ma[i + 1][j] == 0 ? -1 : 1;
					ma[i + 1][j] += ma[i + 1][j] == 0 ? 1 : -1;
				}
				if (j - 1 >= 0)
				{
					redu += ma[i][j - 1] == 0 ? -1 : 1;
					ma[i][j - 1] += ma[i][j - 1] == 0 ? 1 : -1;
				}
				if (j + 1 < m)
				{
					redu += ma[i][j + 1] == 0 ? -1 : 1;
					ma[i][j + 1] += ma[i][j + 1] == 0 ? 1 : -1;
				}
				if (redu >= 0)
				{
					cnt -= redu;
					ans[i][j]++;
					dfs(aim, step + 1, st(j == m - 1 ? i + 1 : i, (j + 1) % m));
					cnt += redu;
					ma[i][j] += ma[i][j] == 0 ? 1 : -1;
					if (i - 1 >= 0)
						ma[i - 1][j] += ma[i - 1][j] == 0 ? 1 : -1;
					if (i + 1 < n)
						ma[i + 1][j] += ma[i + 1][j] == 0 ? 1 : -1;
					if (j - 1 >= 0)
						ma[i][j - 1] += ma[i][j - 1] == 0 ? 1 : -1;
					if (j + 1 < m)
						ma[i][j + 1] += ma[i][j + 1] == 0 ? 1 : -1;
					ans[i][j]--;
				} else
				{
					ma[i][j] += ma[i][j] == 0 ? 1 : -1;
					if (i - 1 >= 0)
						ma[i - 1][j] += ma[i - 1][j] == 0 ? 1 : -1;
					if (i + 1 < n)
						ma[i + 1][j] += ma[i + 1][j] == 0 ? 1 : -1;
					if (j - 1 >= 0)
						ma[i][j - 1] += ma[i][j - 1] == 0 ? 1 : -1;
					if (j + 1 < m)
						ma[i][j + 1] += ma[i][j + 1] == 0 ? 1 : -1;
				}
			}
		}
	}
}
// #include <iostream>
// #include <cstdio>
// #include <cstring>
// using namespace std;
// typedef long long ll;
// #define wfor(i,j,k) for(i=j;i<k;++i)
// #define mfor(i,j,k) for(i=j;i>=k;--i)
// // void read(int &x) {
// // 	char ch = getchar(); x = 0;
// // 	for (; ch < '0' || ch > '9'; ch = getchar());
// // 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// // }
// void slove(int i, int j);
// int temp[20][20];
// int ma[20][20] ;
// int ans[20][20] ;
// int res[20][20] ;
// int n, m;
// int main()
// {
// 	std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
// 	cin >> n >> m;
// 	int cntr = 0;
// 	int i, j;
// 	wfor(i, 0, n)
// 	{
// 		wfor(j, 0, m)
// 		{
// 			cin >> ma[i][j];
// 		}
// 	}
// 	int k;
// 	bool is = false;
// 	wfor(k, 0, 1 << m)
// 	{
// 		memmove(temp, ma, sizeof(ma));
// 		memset(ans, 0, sizeof(ans));
// 		int cnt = 0;
// 		wfor(i, 0, m)
// 		{
// 			if ((k >> i) & 1)
// 			{
// 				slove(0, m - i - 1);
// 				ans[0][m - i - 1]++;
// 				cnt++;
// 			}
// 		}
// 		wfor(i, 1, n)
// 		wfor(j, 0, m)
// 		{
// 			if (temp[i - 1][j] == 1)
// 			{
// 				slove(i, j);
// 				ans[i][j]++;
// 				cnt++;
// 			}
// 		}
// 		bool good = true;
// 		wfor(i, 0, m)
// 		{
// 			if (temp[n - 1][i] == 1)
// 			{
// 				good = false;
// 				break;
// 			}
// 		}
// 		if (good)
// 		{
// 			if (!is)
// 			{
// 				cntr = cnt;
// 				memmove(res, ans, sizeof(ans));
// 				is = true;
// 			}
// 			else
// 			{
// 				if (cnt < cntr)
// 				{
// 					cntr = cnt;
// 					memmove(res, ans, sizeof(ans));
// 				}
// 			}
// 		}
// 	}
// 	if (is)
// 	{
// 		wfor(i, 0, n)
// 		{
// 			wfor(j, 0, m - 1)
// 			{
// 				cout << res[i][j] << " ";
// 			}
// 			cout << res[i][j] << endl;
// 		}
// 	} else
// 		cout << "IMPOSSIBLE" << endl;
// 	return 0;
// }
// void slove(int i, int j)
// {
// 	temp[i][j] ^= 1;
// 	if (j - 1 >= 0)
// 		temp[i][j - 1] ^= 1;
// 	if (j + 1 < m)
// 		temp[i][j + 1] ^= 1;
// 	if (i - 1 >= 0)
// 		temp[i - 1][j] ^= 1;
// 	if (i + 1 < n)
// 		temp[i + 1][j] ^= 1;
// }
