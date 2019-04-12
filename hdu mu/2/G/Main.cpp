#include<iostream>
#include<cstdio>
#include<cstring>
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int max_n = 1e5 + 1;
int b_arr[max_n];
int a_arr[max_n];
int c_arr[max_n];
int n, q;
void add(int i, int v) {
	while (i <= n) {
		a_arr[i] += v;
		i += lowbit(i);
	}
}

int tsum(int i) {
	int ans = 0;
	while (i >= 1) {
		ans += a_arr[i];
		i -= lowbit(i);
	}
	return ans;
}

void addc(int i , int v) {
	while (i <= n) {
		c_arr[i] += v;
		i += lowbit(i);
	}
}

int ctsum(int i) {
	int ans = 0;
	while (i >= 1) {
		ans += c_arr[i];
		i -= lowbit(i);
	}
	return ans;
}

int main() {
	while (scanf("%d%d", &n, &q) == 2) {
		memset(a_arr, 0, sizeof(a_arr));
		memset(c_arr, 0, sizeof(c_arr));
		//memset(b_arr, 0, sizeof(b_arr));
		for (int i = 1 ; i <= n; ++i) {
			scanf("%d", b_arr + i);
		}
		char order[10];
		int l, r;
		for (int ind = 0 ; ind < q ; ++ind) {
			scanf("%s", order);
			if (order[0] == 'a')
			{
				scanf("%d%d", &l, &r);
				add(l, 1);
				add(r + 1, -1);

				int last, now;
				for (; l <= r; ++l) {
					last = ctsum(l);
					now = tsum(l) - last;


				}
			} else {
				long long ans = 0;
				scanf("%d%d", &l, &r);
				for (; l <= r; ++l) {
					ans += tsum(l) / b_arr[l];
				}
				printf("%lld\n", ans);
			}
		}
	}
	return 0;
}