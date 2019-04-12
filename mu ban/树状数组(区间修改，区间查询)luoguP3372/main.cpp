#include <iostream>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int n, m;
/**
	sum[i]=(i+1)*siagam[di[i]]-sigma(di[i]*i)
*/
int lowbit(int x)
{
	return x & -x;
}
void updata(ll *a, int x, int y)
{
	int i;
	for (i = x; i <= n; i += lowbit(i))
		a[i] += y;
}
ll get_sum(ll *a  , int x)
{
	int i;
	ll sum = 0;
	for (i = x; i > 0; i -= lowbit(i))
		sum += a[i];
	return sum;
}
ll di[100005];//差分数组
ll dix[100005];//di*i数组
//ll a_sum[100005];//前缀和
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	int i;
	int temp = 0;
	wfor(i, 1, n + 1)
	{
		ll t;
		cin >> t;
		updata(di, i, t - temp);
		updata(dix, i, (t - temp)*i);
		//a_sum[i] = a_sum[i - 1] + t;
		temp = t;
	}
	wfor(i, 0, m)
	{
		ll op, x, y, k;
		cin >> op;
		if (op == 1)
		{
			cin >> x >> y >> k;
			updata(di, x, k);
			updata(di, y + 1, -k);
			updata(dix, x, k * x);
			updata(dix, y + 1, -k * (y + 1));
		} else
		{
			cin >> x >> y;
			ll sumx, sumy;
			sumx = /*a_sum[x - 1]+*/ x * get_sum(di, x - 1) - get_sum(dix, x - 1);
			sumy = /*a_sum[y] +*/ (y + 1) * get_sum(di, y) - get_sum(dix, y);
			cout << sumy - sumx << endl;
		}
	}
	return 0;
}

