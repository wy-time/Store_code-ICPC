// #include <iostream>
// #include <cstdio>
// #include <cstring>
// using namespace std;
// typedef long long ll;
// #define wfor(i,j,k) for(i=j;i<k;++i)
// #define mfor(i,j,k) for(i=j;i>=k;--i)
// // void read(int &x) {
// // 	char ch = getchar(); x = 0;
// // 	for (; ch < '0' || ch > '9'; ch = getchar());
// // 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// // }
// bool dfs(int now, int ned, int n, int step, int &cnt);
// struct st
// {
// 	int cnt;
// 	int way[10];
// };
// st ans [10][10];
// int res[105];
// int ult[105];
// int main()
// {
// 	// std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
// 	int i, j;
// 	wfor(i, 1, 10)
// 	{
// 		wfor(j, 0, 10)
// 		{
// 			int cnt = 0;
// 			int k;
// 			wfor(k, 1, 10)
// 			{
// 				if (((i * k) % 10 + j) % 10 == 0 || ((i * k) % 10 + j) % 10 == 1)
// 					ans[i][j].way[cnt++] = k;
// 			}
// 			ans[i][j].cnt = cnt;
// 		}
// 	}
// 	int n = 0;
// 	while (n <= 200)
// 	{
// 		n++;
// 		int cnt = 0;
// 		if (n == 0)
// 			break;
// 		int ned = 0;
// 		int t = n;
// 		while (ned == 0)
// 		{
// 			ned = t % 10;
// 			t /= 10;
// 		}
// 		if (dfs(0, ned, n, 0, cnt))
// 		{
// 			cout << n << "        ";
// 			mfor(i, cnt - 1, 0)
// 			{
// 				printf("%d", ult[i]);
// 			}
// 			printf("\n");
// 		}
// 	}
// 	return 0;
// }
// bool dfs(int now, int ned, int n, int step, int &cnt)
// {
// 	int i;
// 	if (step >= 19)
// 		return false;
// 	if (now == 1)
// 	{
// 		return true;
// 	}
// 	wfor(i, 0, ans[ned][now].cnt)
// 	{
// 		int temp = now;
// 		bool enter = true;
// 		res[step] = ans[ned][now].way[i];
// 		int j;
// 		memset(ult, 0, sizeof(ult));
// 		wfor(j, 0, step + 1)
// 		{
// 			ult[j] = res[j] * n;
// 		}
// 		int add = 0;
// 		for (j = 0; j <= step || add != 0; j++)
// 		{
// 			ult[j] += add;
// 			add = ult[j] / 10;
// 			if (ult[j] >= 10)
// 			{
// 				ult[j] %= 10;
// 			}
// 			if (ult[j] != 0 && ult[j] != 1)
// 			{
// 				temp = ult[j];
// 				enter = false;
// 				break;
// 			}
// 		}
// 		cnt = j;
// 		if (enter)
// 			temp = 1;
// 		if (dfs(temp, ned, n, step + 1, cnt))
// 			return true;
// 	}
// 	return false;
// }
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
int mod[600005];
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n;
	while (cin >> n)
	{
		if (n == 0)
			break;
		mod[1] = 1 % n;
		int i;
		for (i = 2; mod[i - 1] != 0; i++)
		{
			mod[i] = (mod[i / 2] * 10 + i % 2) % n;
		}
		i--;
		int cnt = 0;
		while (i)
		{
			mod[cnt++] = i % 2;
			i /= 2;
		}
		mfor(i, cnt - 1, 0)
		cout << mod[i];
		cout << endl;
	}
	return 0;
}
