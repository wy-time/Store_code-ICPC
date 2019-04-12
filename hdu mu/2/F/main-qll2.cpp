#include<iostream>
#include<cstring>
#include<cstdio>
#define lowbit(x) (x&(-(x)))
using namespace std;
const int max_n = 1e5 + 20;
int a_arr[max_n];
int b_arr[max_n];
int c_arr[max_n];
int n, q;
inline void add(int i , int v) {
	while (i <= n ) {
		c_arr[i] += v;
		i += lowbit(i);
	}
}

inline long long tsum(int i) {
	long long ans  = 0;
	while (i > 0 ) {
		ans += c_arr[i];
		i -= lowbit(i);
	}
	return ans;
}

int main() {
	while (scanf("%d%d", &n, &q) == 2) {
		memset(a_arr, 0, sizeof(a_arr));
		memset(c_arr, 0, sizeof(c_arr));
		for (register int i = 1 ; i <= n ; ++i) {
			scanf("%d", b_arr + i);
		}

		char order[10];
		register int x, y;
		for (register int i = 0 ; i < q ; ++i) {
			scanf("%s %d%d", order, &x, &y);
			if (order[0] == 'a') {
				register int last, now;
				for (; x <= y; ++x) {
					last = a_arr[x] / b_arr[x];
					a_arr[x]++;
					now = a_arr[x] / b_arr[x];
					if (last != now) {
						add(x, 1);
					}
				}
			} else {
				long long ans = tsum(y) - tsum(x - 1);
				printf("%lld\n", ans);
			}
		}
	}
	return 0;
}