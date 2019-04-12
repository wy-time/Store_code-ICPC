#include <iostream>
#ifdef test
#include <cstdio>
#endif
#include <string>
#include <stack>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
char res[200005];
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	int i;
	stack <char> st;
	int cnt = 0;
	wfor(i, 0, n)
	{
		if (cnt == m)
			break;
		if (s[i] == '(')
			st.push(s[i]);
		else
		{
			if (!st.empty())
			{
				st.push(')');
				cnt += 2;
			}
		}
	}
	// int flag = 1;
	i = 0;
	int cntr = 0;
	while (!st.empty())
	{
		if (st.top() == ')')
		{
			res[i] = st.top();
			// flag *= -1;
			cntr++;
			i++;
		} else if (st.top() == '(' && cntr > 0)
		{
			res[i] = st.top();
			// flag *= -1;
			i++;
			cntr--;
		}
		st.pop();
	}
	mfor(i, cnt - 1, 0)
	{
		cout << res[i];
	}
	return 0;
}
