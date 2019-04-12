#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int main()
{
	std::ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	char ans[100];
	int i;
	wfor(i, 0, n)
	{
		cin >> ans[i];
	}
	sort(ans, ans + n);
	int sum = 0;
	int cnt = 0;
	char last = '0';
	wfor(i, 0, n)
	{
		if (cnt == k)
		{
			break;
		}
		if (ans[i] == last || ans[i] == last + 1 || ans[i] == last - 1)
			continue;
		sum += ans[i] - 'a' + 1;
		last = ans[i];
		cnt++;
	}
	if (cnt == k)
		cout << sum << endl;
	else
		cout << -1 << endl;
	return 0;
}
