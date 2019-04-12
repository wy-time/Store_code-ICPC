#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int dp[10005];
struct st
{
	int begx;
	int time;
};
st work[10005];
struct rule
{
	bool operator()(st a, st b)
	{
		return a.begx > b.begx;
	}
};
int main()
{
	std::ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int i;
	wfor(i, 0, k)
	{
		cin >> work[i].begx >> work[i].time;
	}
	sort(work, work + k, rule());
	int cnt = 0;
	mfor(i, n, 1)
	{
		if (work[cnt].begx != i)
			dp[i] = dp[i + 1] + 1;
		while (work[cnt].begx == i)
		{
			dp[i] = max(dp[i], dp[i + work[cnt].time]);
			cnt++;
		}
	}
	cout << dp[1] << endl;
	return 0;
}
