#include <iostream>
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
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	string a, b, r;
	int case_num = 1;
	map <string, int> ma;
	while (n--)
	{
		int cnt = 0;
		bool flag = false;
		int c;
		cin >> c >> a >> b >> r;
		ma.clear();
		while (1)
		{
			int i;
			string temp = "";
			wfor(i, 0, c)
			{
				temp += b[i];
				temp += a[i];
			}
			cnt++;
			if (temp == r)
			{
				flag = true;
				break;
			}
			if (ma.count(temp) != 0)
				break;
			else
			{
				ma.insert(make_pair(temp, 1));
			}
			a = "";
			b = "";
			a = temp.substr(0, c);
			b = temp.substr(c);
			temp = "";
		}
		if (flag)
			cout << case_num << " " << cnt << endl;
		else
			cout << case_num << " " << -1 << endl;
		case_num++;
	}
	return 0;
}
