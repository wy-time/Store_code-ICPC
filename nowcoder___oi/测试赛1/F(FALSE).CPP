// #include <iostream>
// #include <cstdio>
// #include <deque>
// using namespace std;
// typedef long long ll;
// #define wfor(i,j,k) for(i=j;i<k;++i)
// #define mfor(i,j,k) for(i=j;i>=k;--i)
// // void read(int &x) {
// // 	char ch = getchar(); x = 0;
// // 	for (; ch < '0' || ch > '9'; ch = getchar());
// // 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// // }
// struct st
// {
// 	int n;
// 	int id;
// };
// st num[1005];
// const ll mod = 1e9 + 7;
// ll ksm(ll a, ll b);
// int main()
// {
// 	std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
// 	int t;
// 	cin >> t;
// 	while (t--)
// 	{
// 		int n, k;
// 		cin >> n >> k;
// 		int i;
// 		ll res = 0;
// 		wfor(i, 0, n)
// 		{
// 			cin >> num[i].n;
// 			num[i].id = i;
// 		}
// 		res = num[0].n;
// 		wfor(i, 1, n)
// 		{
// 			res = res % mod * ksm(num[i].n, k) % mod;
// 		}
// 		deque<st> deq;
// 		deq.push_back(num[0]);
// 		wfor(i, 1, k)
// 		{
// 			if (num[i].n < deq.back().n)
// 				deq.push_back(num[i]);
// 			else
// 			{
// 				while (!deq.empty()&&num[i].n > deq.back().n)
// 					deq.pop_back();
// 				deq.push_back(num[i]);
// 			}
// 		}
// 		ll max_t = 1;
// 		wfor(i, k, n)
// 		{
// 			if (deq.front().id < i - k)
// 				deq.pop_front();
// 			if (num[i].n < deq.back().n)
// 				deq.push_back(num[i]);
// 			else
// 			{
// 				while (!deq.empty()&&num[i].n > deq.back().n)
// 					deq.pop_back();
// 				deq.push_back(num[i]);
// 			}
// 			max_t = max_t * ksm(deq.front().n, mod - 2) % mod;
// 		}
// 		deque<st> deq_min;
// 		deq_min.push_back(num[0]);
// 		wfor(i, 1, k)
// 		{
// 			if (num[i].n > deq_min.back().n)
// 				deq_min.push_back(num[i]);
// 			else
// 			{
// 				while (!deq_min.empty()&&num[i].n < deq_min.back().n)
// 					deq_min.pop_back();
// 				deq_min.push_back(num[i]);
// 			}
// 		}
// 		ll min_t = 1;
// 		wfor(i, k, n)
// 		{
// 			if (deq_min.front().id < i - k)
// 				deq_min.pop_front();
// 			if (num[i].n > deq_min.back().n)
// 				deq_min.push_back(num[i]);
// 			else
// 			{
// 				while (!deq_min.empty()&&num[i].n < deq_min.back().n)
// 					deq_min.pop_back();
// 				deq_min.push_back(num[i]);
// 			}
// 			min_t = min_t * ksm(deq_min.front().n, mod - 2) % mod;
// 		}
// 	}
// 	return 0;
// }
// ll ksm(ll a, ll b)
// {
// 	ll ans = 1;
// 	while (b)
// 	{
// 		if (b & 1)
// 			ans = ans * a % mod;
// 		b >>= 1;
// 		a = a * a % mod;
// 	}
// 	return ans;
// }
