// #include <iostream>
// #include <algorithm>
// #include <set>
// using namespace std;
// typedef long long ll;
// #define wfor(i,j,k) for(i=j;i<k;++i)
// #define mfor(i,j,k) for(i=j;i>=k;--i)
// bool cmp (int a, int b)
// {
// 	return a > b;
// }
// int main()
// {
// 	std::ios::sync_with_stdio(false);
// 	int n, m;
// 	cin >> n >> m;
// 	int i;
// 	multiset <int> set1;
// 	int ans[200] = {0};
// 	wfor(i, 0, m)
// 	{
// 		int t;
// 		cin >> t;
// 		ans[t]++;
// 	}
// 	sort(ans, ans + 200, cmp);
// 	int cnt = 0;
// 	wfor(i, 0, m)
// 	{
// 		if (cnt == n)
// 			break;
// 		if (ans[i] != 0)
// 		{
// 			set1.insert(ans[i]);
// 			cnt++;
// 		}
// 	}
// 	if (n < m)
// 	{
// 		if (set1.size() != 1 && set1.size() >= n)
// 		{
// 			while (*set1.begin() <= * (set1.rbegin()) / 2)
// 			{
// 				int t = *set1.rbegin();
// 				set1.erase(set1.begin());
// 				auto it = set1.end();
// 				it--;
// 				set1.erase(it);
// 				set1.insert(t / 2);
// 				set1.insert(t - t / 2);
// 			}
// 			cout << *set1.begin() << endl;
// 		} else if (set1.size() == 1)
// 		{
// 			cout << *(set1.begin()) / n << endl;
// 		} else
// 		{
// 			while (set1.size() < n)
// 			{
// 				int t = *set1.rbegin();
// 				auto it = set1.end();
// 				it--;
// 				set1.erase(it);
// 				set1.insert(t / 2);
// 				set1.insert(t - t / 2);
// 			}
// 			while (*set1.begin() <= * (set1.rbegin()) / 2)
// 			{
// 				int t = *set1.rbegin();
// 				set1.erase(set1.begin());
// 				auto it = set1.end();
// 				it--;
// 				set1.erase(it);
// 				set1.insert(t / 2);
// 				set1.insert(t - t / 2);
// 			}
// 			cout << *set1.begin() << endl;
// 		}
// 	} else if (n > m)
// 		cout << 0 << endl;
// 	else if (n == m)
// 		cout << 1 << endl;
// 	return 0;
// }
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(int i=j;i<k;++i)
#define mfor(i,j,k) for(int i=j;i>=k;--i)
int main()
{
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int res = 0;
	int temp = 1000000;
	int ans[200] = {0};
	wfor(i, 0, m)
	{
		int t;
		cin >> t;
		ans[t]++;
	}
	sort(ans, ans + 200, greater<int>());
	while (temp >= n)
	{
		res++;
		temp = 0;
		wfor(i, 0, m)
		{
			if (ans[i] == 0)
				break;
			else
			{
				temp += ans[i] / res;
			}
		}
	}
	cout << res - 1 << endl;
	return 0;
}








