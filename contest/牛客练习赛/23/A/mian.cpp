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
	int i;
	int yuan[7] = {100, 50, 20, 10, 5, 2, 1};
	int fen[6] = {50, 20, 10, 5, 2, 1};
	wfor(i, 0, t)
	{
		int ans1[7] = {0};
		int ans[6] = {0};
		int a, b;
		cin >> a >> b;
		int j;
		wfor(j, 0, 7)
		{
			ans1[j] = a / yuan[j];
			a %= yuan[j];
		}
		wfor(j, 0, 6)
		{
			ans[j] = b / fen[j];
			b %= fen[j];
		}
		wfor(j, 0, 7)
		{
			cout << ans1[j] << " ";
		}
		wfor(j, 0, 5)
		{
			cout << ans[j] << " ";
		}
		cout << ans[j] << endl;
	}
	return 0;
}
