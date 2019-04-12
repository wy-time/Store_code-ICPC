#include <iostream>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		int k;
		cin >> k;
		if (k == 1)
			cout << 5 << endl;
		else if (k == 2)
			cout << 7 << endl;
		else
			cout << k + 5 << endl;
	}
	return 0;
}
