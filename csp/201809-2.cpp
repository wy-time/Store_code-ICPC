#include <iostream>
#include <algorithm>
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
struct node
{
	int l;
	int r;
	bool operator < (const node t)const
	{
		return this->l < t.l;
	}
};
node p1[2005], p2[2005];
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
		cin >> p1[i].l >> p1[i].r;
	}
	wfor(i, 0, n)
	{
		cin >> p2[i].l >> p2[i].r;
	}
	sort(p1, p1 + n);
	sort(p2, p2 + n);
	int j = 0;
	i = 0;
	int ans = 0;
	while (i < n && j < n)
	{
		int tem = min(p1[i].r, p2[j].r) - max(p1[i].l, p2[j].l);
		if (tem > 0)
		{
			ans += tem;
			if (p1[i].r < p2[j].r)
				i++;
			else if (p1[i].r > p2[j].r)
				j++;
			else
			{
				i++;
				j++;
			}
		} else
		{
			if (p1[i].l < p2[j].l)
				i++;
			else if (p1[i].l > p2[j].l)
				j++;
		}
	}
	cout << ans << endl;
	return 0;
}
