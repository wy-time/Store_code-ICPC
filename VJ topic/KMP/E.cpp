#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
void read(int &x) {
	char ch = getchar(); x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
inline void out(int x) {
	if (x > 9) out(x / 10);
	putchar(x % 10 + '0');
}
int _next[1000005];
char s[1000005];
void cal_next(int n);
int main()
{
	// std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
	int n;
	int cnt = 0;
	while (scanf("%d", &n) != EOF)
	{
		getchar();
		if (n == 0)
			break;
		cnt++;
		gets(s);
		int len = n;
		int i = 2;
		// int step = 1;
		cal_next(n);
		printf("Test case #%d\n", cnt );
		if (_next[len - 1] == len - 1)
		{
			wfor(i, 2, len + 1)
			{
				out(i); putchar(' '); out(i);
				putchar('\n');
			}
			putchar('\n');
			continue;
		}
		while (i < len + 1)
		{
			if (_next[i - 1] == i - 1)
			{
				out(i); putchar(' '); out(i);
				putchar('\n');
			}
			else if (_next[i - 1] * 2 == i)
			{
				// step = _next[i - 1];
				out(i); putchar(' '); out(2);
				putchar('\n');
			}
			else if (_next[i - 1] * 2 < i)
			{
				// i += step;
				i++;
				continue;
			}
			else
			{
				int tlen = i;
				while (_next[tlen - 1] * 2 > tlen)
				{
					tlen = _next[tlen - 1];
				}
				if (_next[tlen - 1] * 2 == tlen)
				{
					// cout << i << " " << i / (tlen / 2) << endl;
					out(i); putchar(' '); out(i / _next[tlen - 1]);
					putchar('\n');
				}
			}
			i ++;
		}
		putchar('\n');
	}
	return 0;
}

void cal_next(int n)
{
	int len = n;
	int i;
	int k = -1;
	_next[0] = -1;
	wfor(i, 1, len)
	{
		while (k > -1 && s[i] != s[k + 1])
			k = _next[k];
		if (s[i] == s[k + 1])
			++k;
		_next[i] = k;
	}
	wfor(i, 0, len)
	_next[i]++;
}
// #include<stdio.h>
// #include<string.h>
// #include<math.h>
// #include<stdlib.h>

// int main(void)
// {
// 	int T;
// 	int temp;
// 	static char word[1000010];
// 	static int next[1000010];
// 	static int num[1000010];
// 	int count = 0;
// 	while (scanf("%d", &T) != EOF && T)
// 	{
// 		count++;
// 		memset(word, 0, sizeof(word));
// 		memset(next, 0, sizeof(next));
// 		for (int i = 1; i < 1000009; i++)
// 			num[i] = 1;
// 		word[0] = '0';
// 		scanf("%s", word + 1);
// 		printf("Test case #%d\n", count);
// 		temp = 1;
// 		num[1] = 1;
// 		for (int i = 2; i <= T; i++)
// 		{
// 			while (word[i] != word[temp] && temp != 0)
// 				temp = next[temp];
// 			next[i] = temp;
// 			if (temp == 0 && word[i] == word[1])
// 			{

// 				next[i] = 1;
// 				temp++;
// 			}
// 			temp++;
// 			if (next[i] != 0)
// 			{
// 				if (next[i] % (i - next[i]) == 0)
// 					num[i] = num[next[i]] + 1;
// 				if (num[i] != 1)
// 					printf("%d %d\n", i, num[i]);
// 			}
// 		}
// 		printf("\n");
// 	}
// 	return 0;
// }