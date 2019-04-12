#include <iostream>
#include <cmath>
#include <string>
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
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
#ifdef ubuntu
	freopen("/home/time/debug/debug/in", "r", stdin);
	freopen("/home/time/debug/debug/out", "w", stdout);
#endif
	string s;
	string p;
	cin >> s >> p;
	int len1 = s.size();
	int len2 = p.size();
	int flag = 1;
	int i;
	if (abs(len1 - len2) > 2)
		flag = 0;
	else if (len1 + 2 == len2)
	{
		int j = 0;
		int cnt = 0;
		wfor(i, 0, len1)
		{
			if (s[i] != p[j])
			{
				i--;
				cnt++;
				if (cnt >= 3)
				{
					flag = 0;
					break;
				}
			}
			j++;
		}
	} else if (len1 - 2 == len2)
	{
		int j = 0;
		int cnt = 0;
		wfor(i, 0, len1)
		{
			if (s[i] != p[j])
			{
				cnt++;
				if (cnt >= 3)
				{
					flag = 0;
					break;
				}
				continue;
			}
			j++;
		}
	} else if (len1 == len2)
	{
		int tflag = 1;
		int j = 0;
		int cnt = 0;
		wfor(i, 0, len1)
		{
			if (s[i] != p[j])
			{
				if (cnt == 0)
				{
					cnt++;
					continue;
				} else
				{
					i--;
					cnt++;
					if (cnt >= 3)
					{
						tflag = 0;
						break;
					}
				}
			}
			j++;
		}
		if (tflag == 0)
		{
			tflag = 1;
			cnt = 0;
			j = 0;
			wfor(i, 0, len1)
			{
				if (s[i] != p[j])
				{
					if (cnt == 0)
					{
						i--;
						cnt++;
					} else
					{
						cnt++;
						if (cnt >= 3)
						{
							tflag = 0;
							break;
						}
						continue;
					}
				}
				j++;
			}
		}
		if (tflag == 0)
		{
			tflag = 1;
			cnt = 0;
			j = 0;
			wfor(i, 0, len1)
			{
				if (s[i] != p[j])
				{
					cnt++;
					if (cnt >= 3)
					{
						tflag = 0;
						break;
					}
				}
				j++;
			}
		}
		if (tflag == 0)
			flag = 0;
	} else if (len1 - 1 == len2)
	{
		int tflag = 1;
		int j = 0;
		int cnt = 0;
		wfor(i, 0, len1)
		{
			if (s[i] != p[j])
			{
				if (cnt == 0)
				{
					cnt++;
					continue;
				} else
				{
					cnt++;
					if (cnt >= 3)
					{
						tflag = 0;
						break;
					}
				}
			}
			j++;
		}
		if (tflag == 0)
		{
			j = 0;
			cnt = 0;
			tflag = 1;
			wfor(i, 0, len1)
			{
				if (s[i] != p[j])
				{
					if (cnt == 0)
					{
						cnt++;
					} else
					{
						cnt++;
						if (cnt >= 3)
						{
							tflag = 0;
							break;
						}
						continue;
					}
				}
				j++;
			}
		}
		if (tflag == 0)
			flag = 0;
	} else if (len1 + 1 == len2)
	{
		int tflag = 1;
		int j = 0;
		int cnt = 0;
		wfor(i, 0, len1)
		{
			if (s[i] != p[j])
			{
				if (cnt == 0)
				{
					cnt++;
					i--;
				} else
				{
					cnt++;
					if (cnt >= 3)
					{
						tflag = 0;
						break;
					}
				}
			}
			j++;
		}
		if (tflag == 0)
		{
			j = 0;
			cnt = 0;
			tflag = 1;
			wfor(i, 0, len1)
			{
				if (s[i] != p[j])
				{
					if (cnt == 0)
					{
						cnt++;
					} else
					{
						cnt++;
						i--;
						if (cnt >= 3)
						{
							tflag = 0;
							break;
						}
					}
				}
				j++;
			}
		}
		if (tflag == 0)
			flag = 0;
	}
	if (flag == 0)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}
