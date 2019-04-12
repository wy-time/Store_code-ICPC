#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
int num[3000];
int odd[3000];
int even[3000];
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
	int cnt1 = 0;
	int cnt2 = 0;
	ll sum = 0;
	wfor(i, 0, n)
	{
		cin >> num[i];
		if (num[i] % 2 == 0)
			even[cnt1++] = num[i];
		else
			odd[cnt2++] = num[i];
		sum += num[i];
	}
	sort(even, even + cnt1, greater<int>());
	sort(odd, odd + cnt2, greater<int>());
	i = 0;
	int j = 0;
	if (cnt1 > cnt2)
	{
		sum -= even[i];
		i++;
	} else if (cnt1 < cnt2)
	{
		sum -= odd[j];
		j++;
	}
	while (j < cnt2 && i < cnt1)
	{
		sum -= even[i];
		sum -= odd[j];
		i++;
		j++;
	}
	cout << sum << endl;
	return 0;
}
