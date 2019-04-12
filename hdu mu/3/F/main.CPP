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
		int n;
		cin >> n;
		int sum;
		cin >> sum;
		int i;
		wfor(i, 1, n)
		{
			int temp;
			cin >> temp;
			sum ^= temp;
		}
		wfor(i, 0, n - 1)
		{
			int a, b;
			cin >> a >> b;
		}
		if (sum == 0)
			cout << "D" << endl;
		else
			cout << "Q" << endl;
	}
	return 0;
}
