#include <iostream>
#include <string>
#include <map>
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
struct st
{
	int s[5];
	int up[5];
	int flag;
	int getsc()
	{
		int i;
		int ans = 0;
		wfor(i, 0, 5)
		{
			ans += this->s[i];
		}
		return ans;
	}
};
st score[1005];
int pid[205];
int psc[205];
int minsc[205];
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
	int n, m;
	cin >> n >> m;
	pid['A'] = 0;
	pid['B'] = 1;
	pid['C'] = 2;
	pid['D'] = 3;
	pid['E'] = 4;
	psc['A'] = 500;
	psc['B'] = 1000;
	psc['C'] = 1500;
	psc['D'] = 2000;
	psc['E'] = 2500;
	minsc['A'] = 150;
	minsc['B'] = 300;
	minsc['C'] = 450;
	minsc['D'] = 600;
	minsc['E'] = 750;
	map <string, int> name;
	int i;
	wfor(i, 0, n)
	{
		string s;
		cin >> s;
		name.insert(make_pair(s, i));
	}
	if (name.count("cnz") == 0)
	{
		cout << -1 << endl;
		return 0;
	}
	wfor(i, 0, m)
	{
		int time;
		string sname, status;
		char sid;
		cin >> time >> sname >> sid >> status;
		int id = sid;
		if (status != "CE")
		{
			if (status == "AC")
			{
				score[name[sname]].s[pid[id]] = max(minsc[id], (psc[id] - (time * (psc[id] / 250)) - (score[name[sname]].up[pid[id]] * 50)));
			}
			else
				score[name[sname]].s[pid[id]] = 0;
			score[name[sname]].up[pid[id]]++;
		}
		score[name[sname]].flag = 1;
	}
	if (score[name["cnz"]].flag == 1)
	{
		int cnz = score[name["cnz"]].getsc();
		int cnt = 0;
		int total = 0;
		wfor(i, 0, n)
		{
			if (score[i].flag == 1)
			{
				total++;
				if (score[i].getsc() > cnz)
					cnt++;
			}
		}
		cout << cnz << endl;
		cout << cnt + 1 << "/" << total << endl;
	} else
		cout << -1 << endl;
	return 0;
}
