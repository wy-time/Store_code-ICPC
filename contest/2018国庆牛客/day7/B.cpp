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
int ma[6][4];
bool check();
bool solve();
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int i, j;
		wfor(i, 0, 6)
		{
			wfor(j, 0, 4)
			{
				cin >> ma[i][j];
			}
		}
	}
	return 0;
}
bool check()
{
	int flag = 1;
	wfor(i, 0, 6)
	{
		wfor(j, 0, 3)
		{
			if (ma[i][j] != ma[i][j + 1])
				flag = 0;
		}
	}
	if (flag)
		return true;
	else
		return false;
}
bool solve()
{
	int temp[6][4] = memmove(temp, ma, sizeof(ma));
	if (check(ma))
	{
		return true;
	}

	int t1, t2;
	t1 = ma[0][0]; , t2 = ma[0][2];
	wfor(i, 1, 4)
	{
		ma[i - 1][0] = ma[i][0];
		ma[i - 1][2] = ma[i][2];
	}
	ma[3][0] = t1;
	ma[3][2] = t2;
	if (check(ma))
	{
		return true;
	}

	t1 = ma[3][0]; , t2 = ma[3][2];
	mfor(i, 3, 1)
	{
		ma[i][0] = ma[i - 1][0];
		ma[i][2] = ma[i - 1][2];
	}
	ma[0][0] = t1;
	ma[0][2] = t2;
	if (check(ma))
	{
		return true;
	}

	t1 = ma[5][0], t2 = ma[5][2];
	ma[5][0] = ma[3][2], ma[5][2] = ma[3][3];
	ma[3][2] = ma[4][3], ma[3][3] = ma[4][1];
	ma[4][3] = ma[1][1], ma[4][1] = ma[1][0];
	ma[1][0] = t2, ma[1][1] = t1;
	if (check(ma))
	{
		return true;
	}
}