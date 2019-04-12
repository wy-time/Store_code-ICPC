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
int ans[10005];
int res[10005];
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	int i;
	wfor(i, 0, n)
	{
		cin >> ans[i];
	}
	wfor(i, 0, n)
	{
		int t1, t2;
		t1 = i + 1;
		t2 = i - 1;
		int temp = ans[i];
		int cnt = 1;
		if (t1 < n)
		{
			cnt++;
			temp += ans[t1];
		}
		if (t2 >= 0)
		{
			cnt++;
			temp += ans[t2];
		}
		res[i] = temp / cnt;
	}
	wfor(i, 0, n - 1)
	{
		cout << res[i] << " ";
	}
	cout << res[i] << endl;
	return 0;
}
