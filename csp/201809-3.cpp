#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
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
struct node
{
	string s;
	int deep;
	string aci;
	string id;
	int line;
};
node s[105];
int findx(string , int);
int n, m;
int main()
{
	std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
	cin >> n >> m;
	int i;
	string getc;
	getline(cin, getc);
	wfor(i, 0, n)
	{
		string temp;
		getline(cin, temp);
		int deep = count(temp.begin(), temp.end(), '.');
		int id = count(temp.begin(), temp.end(), '#');
		s[i].deep = deep;
		s[i].line = i + 1;
		if (id != 0)
		{
			int pos = temp.find(' ');
			s[i].s = temp.substr(deep, pos - deep);
			s[i].id = temp.substr(pos + 2);
		} else
			s[i].s = temp.substr(deep);
		transform(s[i].s.begin(), s[i].s.end(), s[i].s.begin(), ::toupper);
		int j;
		int flag = 0;
		mfor(j, i - 1, 0)
		{
			if (s[j].deep < s[i].deep)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			s[i].aci = s[j].aci + s[j].s + '@' + s[j].id + " ";
		}
	}
	wfor(i, 0, m)
	{
		string tmp;
		getline(cin, tmp);
		int isalone = tmp.find(" ");
		int j;
		int ans[105] = {0};
		int cnt = 0;
		if (isalone == string::npos)
		{
			if (tmp[0] == '#')
			{
				string f = tmp.substr(1);
				wfor(j, 0, n)
				{
					if (f == s[j].id)
					{
						ans[cnt++] = s[j].line;
					}
				}
			} else
			{
				transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);
				wfor(j, 0, n)
				{
					if (tmp == s[j].s)
						ans[cnt++] = s[j].line;
				}
			}
		} else
		{
			string old[100];
			stringstream stin(tmp);
			int ccnt = 0;
			while (!stin.eof())
			{
				stin >> old[ccnt++];
			}
			int pos = -1;
			while (1)
			{
				pos = findx(old[ccnt - 1], pos + 1);
				if (pos != -1)
				{
					stringstream aciin;
					aciin << s[pos].aci;
					wfor(j, 0, ccnt - 1)
					{
						string now;
						now = old[j];
						if (old[j][0] == '#')
							now = now.substr(1);
						else
							transform(now.begin(), now.end(), now.begin(), ::toupper);
						string temp;
						while (!aciin.eof())
						{
							aciin >> temp;
							if (temp.find(now) != string::npos)
								break;
						}
						if (aciin.eof())
							break;
					}
					if (j == ccnt - 1)
						ans[cnt++] = s[pos].line;
				} else
					break;
			}
		}
		cout << cnt;
		wfor(j, 0, cnt)
		{
			cout << " " << ans[j];
		}
		cout << endl;
	}
	return 0;
}
int findx(string tmp, int pos)
{
	int j;
	if (tmp[0] == '#')
	{
		string f = tmp.substr(1);
		wfor(j, pos, n)
		{
			if (f == s[j].id)
			{
				return s[j].line - 1;
			}
		}
	} else
	{
		transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);
		wfor(j, pos, n)
		{
			if (tmp == s[j].s)
				return s[j].line - 1;
		}
	}
	return -1;
}