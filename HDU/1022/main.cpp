#include <iostream>
#include <cstdio>
#include <stack>
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
	while (cin >> n)
	{
		stack <char>sta;
		int i;
		string _o1;
		string _o2;
		cin >> _o1 >> _o2;
		int cnt = 0;
		int ans[20] = {0};
		int cnt2 = 0;
		wfor(i, 0, n)
		{
			if (sta.empty())
			{
				sta.push(_o1[cnt++]);
				ans[cnt2++] = 1;
			}
			while (sta.top() != _o2[i] && cnt < n)
			{
				sta.push(_o1[cnt++]);
				ans[cnt2++] = 1;
			}
			if (sta.top() == _o2[i])
			{
				sta.pop();
				ans[cnt2++] = -1;
			}
		}
		if (cnt2 == 2 * n)
		{
			cout << "Yes." << endl;
			wfor(i, 0, cnt2)
			{
				if (ans[i] == 1)
					cout << "in" << endl;
				else
					cout << "out" << endl;
			}
		} else
			cout << "No." << endl;
		cout << "FINISH" << endl;
	}
	return 0;
}
