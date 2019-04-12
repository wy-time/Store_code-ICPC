#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
typedef struct
{
	ll a;
	ll b;
} st;
st song[100005];
bool cmp(st q, st w)
{
	return q.a - q.b > w.a - w.b;
}
int main()
{
	std::ios::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	ll i;
	ll minx = 0;
	ll maxn = 0;
	wfor(i, 0, n)
	{
		cin >> song[i].a >> song[i].b;
		minx += song[i].b;
		maxn += song[i].a;
	}
	if (minx > m)
	{
		cout << -1 << endl;
		return 0;
	}
	if (maxn <= m)
	{
		cout << 0 << endl;
		return 0;
	}
	sort(song, song + n, cmp);
	ll cnt = 0;
	wfor(i, 0, n)
	{
		maxn -= (song[i].a - song[i].b);
		cnt++;
		if (maxn <= m)
			break;
	}
	cout << cnt << endl;
	return 0;
}
