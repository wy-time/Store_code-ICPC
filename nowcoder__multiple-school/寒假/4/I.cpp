// #include<cstdio>
// #include<cstring>
// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<string>
// using namespace std;
// typedef long long LL;

// struct node
// {
// 	char c;
// 	int num;
// } u[100005];
// bool cmp(node a, node b)
// {
// 	if (a.c == b.c) return a.num > b.num;
// 	return a.c < b.c;
// }

// vector <int> p;
// char a[100005], c[100005];
// int lena, lenb, dp[100005];

// int main()
// {
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
// 	scanf("%s", a); //读入a串
// 	int i;
// 	lena = strlen(a);
// 	int flag = 1;
// 	for (i = 0; i < lena / 2; i++)
// 	{
// 		if (a[i] != a[lena - 1 - i])
// 		{
// 			flag = 0;
// 			break;
// 		}
// 	}
// 	if (flag == 0)
// 	{
// 		lenb = lena;
// 		for (i = 0; i < lenb; i++)
// 		{
// 			u[i].c = a[lena - i - 1];
// 			u[i].num = i;
// 		}
// 		sort(u, u + lenb, cmp);
// 		for (i = 0; i < lenb; i++)
// 		{
// 			c[i] = u[i].c;
// 		}
// 		c[lenb] = '\0';
// 		for (i = 0; i < lena; i++)
// 		{
// 			int k;
// 			k = lower_bound(c, c + lenb, a[i]) - c;
// 			while (k < lenb && a[i] == c[k])
// 			{
// 				p.push_back(u[k].num);
// 				k++;
// 			}
// 		}
// 		int n;
// 		n = p.size();
// 		memset(dp, 0, sizeof(dp));
// 		int num = 0;
// 		for (i = 0; i < n; i++)
// 		{
// 			if (p[i] > dp[num])
// 			{
// 				dp[++num] = p[i];
// 			} else
// 			{
// 				int k;
// 				k = lower_bound(dp + 1, dp + 1 + num, p[i]) - dp;
// 				dp[k] = p[i];
// 			}
// 		}
// 		if (lena - num <= 1)
// 			printf("Yes\n");
// 		else
// 			// printf("%d\n", lena - num);
// 			printf("No\n");
// 	} else
// 		printf("Yes\n");
// 	return 0;
// }
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
bool IsHuiWen(string str)
{
	int len = str.size();
	for (int i = 0; i < len / 2; i++) {
		if (str[i] != str[len - 1 - i])
			return false;
	}
	return true;
}

int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	string str;
	cin >> str;
	bool flag = false;
	int i;
	int len = str.size();
	for (i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - 1 - i])
			break;;
	}
	if (i == len / 2)
		flag = true;
	else
		flag = (IsHuiWen(str.substr(i + 1, len - 2 * i - 1)) || IsHuiWen(str.substr(i, len - 2 * i - 1)));
	cout << ((flag == true) ? "Yes" : "No") << endl;
	return 0;
}