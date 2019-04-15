#include<bits/stdc++.h>

#define LL long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

LL gcd(LL a, LL b) {return b ? gcd(b, a % b) : a;}
LL lcm(LL a, LL b) {return a / gcd(a, b) * b;}
LL powmod(LL a, LL b, LL MOD) {LL ans = 1; while (b) {if (b % 2)ans = ans * a % MOD; a = a * a % MOD; b /= 2;} return ans;}
const int N = 2e5 + 11;
string slove(string s)
{
	int len = s.size();
	int i;
	stack<char>st;
	for (i = 0; i < len; i++)
	{
		if (st.empty())
			st.push(s[i]);
		else
		{
			if (st.top() == 'a' && s[i] == 'a')
			{
				st.pop();
			} else if (st.top() == 'b' && s[i] == 'b')
			{
				st.pop();
			} else
				st.push(s[i]);
		}
	}
	stack<char>st2;
	int flag = 0;
	while (!st.empty())
	{
		char te = st.top();
		st.pop();
		if (flag == 4)
		{
			st2.pop();
			st2.pop();
			st2.pop();
			st2.pop();
		}
		if (te == 'c')
		{
			flag = 0;
			st2.push(te);
		} else
		{
			if (flag == 4)
			{
				st2.push(te);
				flag = 1;
			} else
			{
				if (!st2.empty())
				{
					if (st2.top() != te)
					{
						flag++;
						st2.push(te);
					}
				} else
				{
					flag++;
					st2.push(te);
				}
			}
		}
	}
	s = "";
	while (!st2.empty())
	{
		s += st2.top();
		st2.pop();
	}
	return s;
}
int main() {
	ios::sync_with_stdio(false);
	string s;
	while (cin >> s)
	{
		string t;
		cin >> t;
		s = slove(s);
		t = slove(t);
		int len1 = s.size();
		int len2 = t.size();
		if (len1 != len2)
			cout << "No" << endl;
		else
		{
			int flag = 1;
			for (int i = 0; i < len1; i++)
			{
				if (s[i] == t[i] || ((i + 1 < len1) && s[i] == t[i + 1] && s[i + 1] == t[i] && s[i] != 'c' && t[i + 1] != 'c'))
				{
				} else
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
	return 0;
}