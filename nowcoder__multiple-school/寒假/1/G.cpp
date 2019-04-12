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
const int maxn = 1e5 + 5;
int num[maxn];
int pos[maxn];
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
	int n, x, y;
	cin >> n >> x >> y;
	int i;
	wfor(i, 0, n)
	{
		cin >> num[i];
		pos[num[i]] = i;
	}
	int L, R;
	L = pos[x];
	R = pos[y];
	if (L > R)swap(L, R);
	int minx = 0x7f7f7f7f;
	int maxx = -1;
	wfor(i, L, R + 1)
	{
		minx = min(minx, num[i]);
		maxx = max(maxx, num[i]);
	}
	int r = -1, l = 0x7f7f7f7f;
	wfor(i, minx, maxx + 1)
	{
		l = min(l, pos[i]);
		r = max(r, pos[i]);
	}
	while (l < L || r > R)
	{
		int tmaxx = maxx;
		int tminx = minx;
		wfor(i, l, L + 1)
		{
			tmaxx = max(tmaxx, num[i]);
			tminx = min(tminx, num[i]);
		}
		L = l;
		wfor(i, R, r + 1)
		{
			tmaxx = max(tmaxx, num[i]);
			tminx = min(tminx, num[i]);
		}
		R = r;
		wfor(i, tminx, minx + 1)
		{
			l = min(l, pos[i]);
			r = max(r, pos[i]);
		}
		wfor(i, maxx, tmaxx + 1)
		{
			l = min(l, pos[i]);
			r = max(r, pos[i]);
		}
		maxx = tmaxx;
		minx = tminx;
	}
	cout << l + 1 << " " << r + 1 << endl;
	return 0;
}
