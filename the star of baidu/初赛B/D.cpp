#include <iostream>
#ifdef test
#include <cstdio>
#endif
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int i;
		multiset <int> set1;
		multiset <int> ::iterator it;
		multiset <int> ::reverse_iterator itr;
		wfor(i, 0, n)
		{
			int temp;
			cin >> temp;
			set1.insert(temp);
		}
		if (n == 1)
			cout << *set1.begin() << endl;
		else if (n > 2)
		{
			while (*set1.rbegin() - *set1.begin() > 1 || *set1.begin() < 0)
			{
				// it = set1.begin();
				// it++;
				// itr = set1.rbegin();
				// itr++;
				// int temp1 = *it;
				// int temp2 = *itr;
				// int op_cnt = min(temp1 - *set1.begin(), (*set1.rbegin() - temp2) % 2 == 0 ? (*set1.rbegin() - temp2) / 2 : (*set1.rbegin() - temp2) / 2 + 1);
				// if (temp1 == *set1.begin() || temp2 == *set1.rbegin())
				// 	op_cnt = 1;
				// int fix1 = *set1.begin() + op_cnt;
				// int fix2 = *set1.rbegin() - 2 * op_cnt;
				// set1.erase(set1.begin());
				// set1.erase(--set1.end());
				// set1.insert(fix1);
				// set1.insert(fix2);
				int fix1 = ceil((*set1.rbegin() - *set1.begin()) / 3.0) + *set1.begin();
				int fix2 = *set1.rbegin() - (ceil((*set1.rbegin() - *set1.begin()) / 3.0)) * 2;
				set1.erase(set1.begin());
				set1.erase(--set1.end());
				set1.insert(fix1);
				set1.insert(fix2);
			}
			cout << *set1.begin() << endl;
		} else
		{
			cout << (*set1.rbegin() - *set1.begin()) / 3 + *set1.begin() << endl;
		}
	}
	return 0;
}
