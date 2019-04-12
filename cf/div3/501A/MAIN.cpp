#include <iostream>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int main()
{
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int i;
	int ans[105] = {0};
	wfor(i, 0, n)
	{
		int a, b;
		cin >> a >> b;
		int j;
		wfor(j, a, b + 1)
		{
			ans[j] = 1;
		}
	}
	int cnt = 0;
	int out[105] = {0};
	wfor(i, 1, m + 1)
	{
		if (ans[i] != 1)
		{
			out[cnt] = i;
			cnt++;
		}
	}
	cout << cnt << endl;
	if (cnt != 0)
	{
		wfor(i, 0, cnt - 1)
		{
			cout << out[i] << " ";
		}
		cout << out[i] << endl;
	}
	return 0;
}
