#include <iostream>
#ifdef test
#include <cstdio>
#endif
#include <algorithm>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int len[50005];
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	int i;
	wfor(i, 0, n - 1)
	{
		int a, b, c;
		cin >> a >> b >> c;
		len[a] = len[b] + c;
	}
	cout << *max_element(len + 1, len + n + 1) << endl;
	return 0;
}
