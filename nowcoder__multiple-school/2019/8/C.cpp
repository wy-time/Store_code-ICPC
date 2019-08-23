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
int ma[1024][1024];
void slove(int n, int aim)
{
	if (n / 2 == aim)
		return;
	int i, j;
	wfor(i, 0, n / 2)
	{
		wfor(j, 0, n)
		{
			ma[i][j] = ma[i][j % (n / 2)];
		}
	}
	wfor(i, n / 2, n)
	{
		wfor(j, 0, n / 2)
		{
			ma[i][j] = ma[i % (n / 2)][j];
		}
		wfor(j, n / 2, n)
		{
			ma[i][j] = -ma[i % (n / 2)][j];
		}
	}
	slove(n * 2, aim);
}
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
	ma[0][0] = 1;
	ma[0][1] = 1;
	ma[1][0] = 1;
	ma[1][1] = -1;
	int n;
	cin >> n;
	if (n != 2)
	{
		slove(4, n);
	}
	int i, j;
	wfor(i, 0, n)
	{
		wfor(j, 0, n)
		{
			cout << ma[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
