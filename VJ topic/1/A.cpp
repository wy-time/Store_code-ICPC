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
char ma[10][10];
int lie[10];
// int vis[10][10];
int hang[10];
void dfs(int step, int now);
int n, k;
int cnt;
int comb(int a, int b);
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	while (cin >> n >> k)
	{
		if (n == -1 && k == -1)
		{
			break;
		}
		cnt = 0;
		memset(lie, 0, sizeof(lie));
		memset(hang, 0, sizeof(hang));
		int i, j;
		wfor(i, 0, n)
		{
			wfor(j, 0, n)
			{
				cin >> ma[i][j];
			}
		}
		dfs(0, 0);
		cout << cnt << endl;
	}
	return 0;
}
void dfs(int step, int now)
{
	int i, j;
	if (step == k)
	{
		cnt++;
		return ;
	}
	wfor(i, now, n)
	{
		if (!hang[i])
		{
			wfor(j, 0, n)
			{
				if (!lie[j] && ma[i][j] == '#')
				{
					hang[i] = 1;
					lie[j] = 1;
					dfs(step + 1, i + 1);
					lie[j] = 0;
					hang[i] = 0;
				}
			}
		}
	}
}
// int comb(int a, int b)
// {
// 	int i;
// 	ll temp1 = 1, temp2 = 1;
// 	wfor(i, 0, b)
// 	{
// 		temp1 *= (a - i);
// 	}
// 	wfor(i, 1, b + 1)
// 	{
// 		temp2 *= i;
// 	}
// 	return temp1 / temp2;
// }
