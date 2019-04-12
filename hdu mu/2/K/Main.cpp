#include <iostream>
#include<algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
#define for(i,j,k) for(i=j;i<k;++i)
#define ffor(i,j,k) for(i=j;i>=k;--i)
ll ans[100005];
ll cnt;
void merge_sort(ll* A, int x, int y, ll* T) {
	if ( y - x > 1 ) {
		ll m = x + (y - x) / 2;
		ll p = x , q = m, i = x ;
		merge_sort(A, x, m, T);
		merge_sort(A, m, y, T);
		while (p < m || q < y ) {
			if (q >= y || (p < m && A[p] <= A[q]))
				T[i++] = A[p++];
			else
			{
				T[i++] = A[q++];
				cnt += m - p;
			}
		}
		for (i , x , y)
			A[i] = T[i];
	}
}
ll t[100005];
int main()
{
	std::ios::sync_with_stdio(false);
	ll n, x, y;
	while (cin >> n >> x >> y)
	{
		memset(t, 0, sizeof(t));
		int i;
		cnt = 0;
		ll res = 0;
		for (i, 0, n)
		{
			cin >> ans[i];
		}
		merge_sort(ans, 0, n, t);
		//cout << cnt << endl;
		res = min(x * cnt, y * cnt);
		cout << res << endl;
	}
	return 0;
}
