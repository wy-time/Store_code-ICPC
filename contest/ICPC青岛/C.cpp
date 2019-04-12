#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
void read(int &x) {
	char ch = getchar(); x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
struct op
{
	char s;
	int a;
	int b;
	set <int> now;
	op() {}
	op(char ss, int aa, int bb, int cc)
	{
		s = ss;
		a = aa;
		b = bb;
		now.clear();
		now.insert(cc);
	}
};
op ma[10005];
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}
int main()
{
	// std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
	int t;
	// cin >> t;
	read(t);
	while (t--)
	{
		int n;
		// cin >> n;
		read(n);
		int i;
		wfor(i, 0, n)
		{
			char s[3];
			int j;
			wfor(j, 0, 3)
			{
				s[j] = getchar();
			}
			int v;
			if (s[1] == 'd')
			{
				// cin >> v;
				read(v);
				ma[i + 1] = op(s[1], v, 0, 257);
			} else
			{
				int k;
				// cin >> v >> k;
				read(v);
				read(k);
				ma[i + 1] = op(s[1], v, k, 257);
			}
		}
		int flag = 1;
		i = 1;
		int r = 0;
		while (flag && i <= n)
		{
			char opp = ma[i].s;
			switch (opp)
			{
			case 'd':
				if (ma[i].now.count((r + ma[i].a) % 256) != 0)
				{
					flag = 0;
					break;
				}
				ma[i].now.insert((r + ma[i].a) % 256);
				r = (r + ma[i].a) % 256;
				i++;
				break;
			case 'e':
				if (ma[i].now.count(r) != 0)
				{
					flag = 0;
					break;
				}
				if (r == ma[i].a)
					i = ma[i].b;
				else
					i++;
				ma[i].now.insert(r);
				break;
			case 'n':
				if (ma[i].now.count(r) != 0)
				{
					flag = 0;
					break;
				}
				if (r != ma[i].a)
					i = ma[i].b;
				else
					i++;
				ma[i].now.insert(r);
				break;
			case 'l':
				if (ma[i].now.count(r) != 0)
				{
					flag = 0;
					break;
				}
				if (r < ma[i].a)
					i = ma[i].b;
				else
					i++;
				ma[i].now.insert(r);
				break;
			case 'g':
				if (ma[i].now.count(r) != 0)
				{
					flag = 0;
					break;
				}
				if (r > ma[i].a)
					i = ma[i].b;
				else
					i++;
				ma[i].now.insert(r);
				break;
			}
		}
		if (flag)
		{
			// cout << "Yes" << endl;
			printf("Yes\n");
		} else
			// cout << "No" << endl;
			printf("No\n");
	}
	return 0;
}
