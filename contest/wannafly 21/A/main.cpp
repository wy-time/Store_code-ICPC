#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
struct st
{
	int x;
	int y;
};
const int maxn = 1000005;
st point[maxn];
// struct rule1
// {
// 	bool operator()(st a,st b)
// 	{
// 		return a.x<b.x;
// 	}
// };
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		int flag = 0;
		int n;
		cin >> n;
		int i;
		ll maxx1 = 0,  maxx2 = 0,  maxy1 = 0,  maxy2 = 0,  minx1 = 0,  minx2 = 0,  miny1 = 0, miny2 = 0;
		wfor(i, 0, n)
		{
			cin >> point[i].x >> point[i].y;
			if (point[maxx1].x <= point[i].x)
			{
				if (point[maxx1].x < point[i].x)
				{
					maxx1 = i;
					maxx2 = i;
				} else
				{
					maxx1 = point[maxx1].y > point[i].y ? maxx1 : i;
					maxx2 = point[maxx2].y < point[i].y ? maxx2 : i;
				}
			}
			if (point[maxy1].y <= point[i].y)
			{
				if (point[maxy1].y < point[i].y)
				{
					maxy1 = i;
					maxy2 = i;
				} else
				{
					maxy1 = point[maxy1].x > point[i].x ? maxy1 : i;
					maxy2 = point[maxy2].x < point[i].x ? maxy2 : i;
				}
			}
			if (point[minx1].x >= point[i].x)
			{
				if (point[minx1].x > point[i].x)
				{
					minx1 = i;
					minx2 = i;
				} else
				{
					minx1 = point[minx1].y > point[i].y ? minx1 : i;
					minx2 = point[minx2].y < point[i].y ? minx2 : i;
				}
			}
			if (point[miny1].y >= point[i].y)
			{
				if (point[miny1].y > point[i].y)
				{
					miny1 = i;
					miny2 = i;
				} else
				{
					miny1 = point[miny1].x > point[i].x ? miny1 : i;
					miny2 = point[miny2].x < point[i].x ? miny2 : i;
				}
			}
		}
		if (maxx1 == maxy1 || maxx2 == miny1 || minx1 == maxy2 || minx2 == miny2)
		{
			// cout << "Yes" << endl;
			flag = 1;
		}
		maxx1 = 0, maxx2 = 0, maxy1 = 0, maxy2 = 0, minx1 = 0, minx2 = 0, miny1 = 0, miny2 = 0;
		wfor(i, 0, n)
		{
			ll tempx = point[i].x;
			point[i].x = point[i].x + point[i].y;
			point[i].y = point[i].y - tempx;
			if (point[maxx1].x <= point[i].x)
			{
				if (point[maxx1].x < point[i].x)
				{
					maxx1 = i;
					maxx2 = i;
				} else
				{
					maxx1 = point[maxx1].y > point[i].y ? maxx1 : i;
					maxx2 = point[maxx2].y < point[i].y ? maxx2 : i;
				}
			}
			if (point[maxy1].y <= point[i].y)
			{
				if (point[maxy1].y < point[i].y)
				{
					maxy1 = i;
					maxy2 = i;
				} else
				{
					maxy1 = point[maxy1].x > point[i].x ? maxy1 : i;
					maxy2 = point[maxy2].x < point[i].x ? maxy2 : i;
				}
			}
			if (point[minx1].x >= point[i].x)
			{
				if (point[minx1].x > point[i].x)
				{
					minx1 = i;
					minx2 = i;
				} else
				{
					minx1 = point[minx1].y > point[i].y ? minx1 : i;
					minx2 = point[minx2].y < point[i].y ? minx2 : i;
				}
			}
			if (point[miny1].y >= point[i].y)
			{
				if (point[miny1].y > point[i].y)
				{
					miny1 = i;
					miny2 = i;
				} else
				{
					miny1 = point[miny1].x > point[i].x ? miny1 : i;
					miny2 = point[miny2].x < point[i].x ? miny2 : i;
				}
			}
		}
		if (maxx1 == maxy1 || maxx2 == miny1 || minx1 == maxy2 || minx2 == miny2)
		{
			// cout << "Yes" << endl;
			flag = 1;
		}
		if (!flag)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
		// sort(point,point+n,rule1());
	}
	return 0;
}
