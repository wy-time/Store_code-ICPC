#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
const int maxn = 1e5 + 5;
char s[maxn];
struct st
{
	int a[26];
};
st ans[maxn];
st sum[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	int cnt = 1;
	while (t--)
	{
		memset(ans, 0, sizeof(ans));
		memset(sum, 0, sizeof(sum));
		int n, q;
		cin >> n >> q;
		cin >> s;
		int i;
		wfor(i, 1, n + 1)
		{
			ans[i].a[s[i - 1] - 'A'] = 1;
		}
		sum[1] = ans[1];
		int j;
		wfor(i, 2, n + 1)
		{
			wfor(j, 0, 26)
			sum[i].a[j] = sum[i - 1].a[j] + ans[i].a[j];
		}
		cout << "Case #" << cnt++ << ":" << endl;
		while (q--)
		{
			int l, r;
			cin >> l >> r;
			int res = -1e5;
			wfor(i, 0, 26)
			{
				res = max(res , sum[r].a[i] - sum[l - 1].a[i]);
				if (res > 0)
					break;
			}
			if (res < 0)
				res = 0;
			cout << res << endl;
		}
	}
	return 0;
}
