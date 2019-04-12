// #include <iostream>
// #include <algorithm>
// #include <set>
// using namespace std;
// typedef long long ll;
// #define wfor(i,j,k) for(i=j;i<k;++i)
// #define mfor(i,j,k) for(i=j;i>=k;--i)
// typedef struct
// {
// 	ll a;
// 	ll lb;
// } st;
// st ans[100005];
// ll ttt[100005];
// ll res[100005];
// struct rule
// {
// 	bool operator () (const st &a, const st &b)
// 	{
// 		return a.lb < b.lb;
// 	}
// };
// int main()
// {
// 	std::ios::sync_with_stdio(false);
// 	ll n;
// 	cin >> n;
// 	ll i;
// 	wfor(i, 0, n)
// 	{
// 		cin >> ans[i].a;
// 		ans[i].lb = ans[i].a & -ans[i].a;
// 		res[i] = ans[i].a;
// 		ttt[i] = ans[i].a;
// 	}
// 	sort(ans, ans + n, rule());
// 	sort(ttt, ttt + n );
// 	ll t = -1;
// 	ll flag = 0;
// 	ll j;
// 	mfor(i, n - 1, 0)
// 	{
// 		if (flag)
// 			break;
// 		ll temp = ans[i].lb;
// 		mfor(j, n - 1, 0)
// 		{
// 			if (ttt[j] < temp || flag)
// 				break;
// 			else
// 			{
// 				if ((ttt[j]& temp) /*&& ttt[j] != ans[i].a*/)
// 				{
// 					flag = 1;
// 					t = ans[i].a;
// 				}
// 			}
// 		}
// 	}
// 	ll cnt = 0;
// 	if (flag)
// 	{
// 		set <ll> set1;
// 		wfor(i, 0, n)
// 		{

// 			if ((res[i] & (t & -t)) || res[i] == t)
// 			{
// 				cnt++;
// 				set1.insert(res[i]);
// 			}
// 		}
// 		if (set1.size() != 1)
// 		{
// 			ll first = 1;
// 			cout << cnt << endl;
// 			wfor(i, 0, n)
// 			{
// 				if ((res[i] & (t & -t)) || res[i] == t)
// 				{
// 					if (!first)
// 						cout << " ";
// 					else
// 						first = 0;
// 					cout << res[i];
// 				}
// 			}
// 		} else
// 		{
// 			ll q = *set1.begin();
// 			if ((q & -q) == q)
// 			{
// 				cout << cnt << endl;
// 				int p;
// 				wfor(p, 0, cnt - 1)
// 				cout << q << " ";
// 				cout << q;
// 			} else
// 			{
// 				//cout << -1 << endl;
// 				cout << n << endl;
// 				wfor(i, 0, n - 1)
// 				{
// 					cout << res[i] << " ";
// 				}
// 				if (n != 0)
// 					cout << res[i];
// 			}
// 		}
// 	} else
// 	{
// 		//cout << -1 << endl;
// 		cout << n << endl;
// 		wfor(i, 0, n - 1)
// 		{
// 			cout << res[i] << " ";
// 		}
// 		if (n != 0)
// 			cout << res[i];
// 	}
// 	return 0;
// }
#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define lson rt<<1,l,m
#define rson rt<<1|1,m+1,r
int n;
int s[100100];
int num[100100];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	LL base = 0;
	for (LL i = 0; i < 31; i++)
		base |= (1LL << i);
	int cmp = 0;
	for (int i = 30; i >= 0; i--)
	{
		LL res = base; cmp = 0;
		for (int j = 0; j < n; j++)
			if (num[j] & (1LL << i))
				res = res & num[j], s[cmp++] = num[j];
		int flag = (res & (-res)) < (1LL << i);
		if (!flag) break;
	}
	printf("%d\n", cmp);
	for (int i = 0; i < cmp; i++)
	{
		if (i) printf(" ");
		printf("%d", s[i]);
	}
	printf("\n");
	return 0;
}