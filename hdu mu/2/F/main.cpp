#include <iostream>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int ans[2005][2005];
int main()
{
	std::ios::sync_with_stdio(false);
	int n = 2000;
	int i, j;
	wfor(i, 3, n)
	{
		cout << i << endl;
		if (i % 2 != 0)
		{
			ans[0][i / 2] = 1;

		}
	}
	return 0;
}
