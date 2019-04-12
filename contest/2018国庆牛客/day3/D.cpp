#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int d[10010], l, l1, n, m;
int cmp(int a, int b) {
	return a > b;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		l = l1 = 0;
		scanf("%d%d", &n, &m);
		int a, b;
		double ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &a, &b);
			if (b == 1)
				l1++;
			d[l++] = a;
			ans += 1.0 * a;
		}
		sort(d, d + l, cmp);
		m = min(l1, m);
		for (int i = 0; i < m; i++)
		{
			ans -= 1.0 * d[i] / 2.0;
		}
		printf("%.1f\n", ans);
	}
	return 0;
}