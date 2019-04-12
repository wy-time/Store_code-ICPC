#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn = 2e6 + 5;
struct POINT
{
	int x;
	int y;
	bool operator< (const POINT b) const
	{
		if (this->x != b.x)
			return this->x < b.x;
		else
			return this->y < b.y;
	}
};
POINT p[maxn];
POINT info[maxn];
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
	int n;
	cin >> n;
	int i;
	wfor(i, 0, n)
	{
		cin >> p[i].x >> p[i].y;
	}
	map <POINT, int> st;
	wfor(i, 0, n)
	{
		cin >> info[i].x >> info[i].y;
		st.insert(make_pair(info[i], i));
	}
	int j;
	POINT temp;
	int flag = 1;
	wfor(i, 0, n)
	{
		flag = 1;
		temp.x = p[0].x + info[i].x;
		temp.y = p[0].y + info[i].y;
		wfor(j, 1, n)
		{
			POINT tt;
			tt.x = temp.x - p[j].x;
			tt.y = temp.y - p[j].y;
			if (st.count(tt) == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag != 0)
			break;
	}
	cout << temp.x << " " << temp.y << endl;
	return 0;
}
