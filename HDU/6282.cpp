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
string slove(string s)
{
	int len = s.size();
	int i;
	stack<char>st;
	int flag = 0;
	for (i = 0; i < len; i++)
	{
		if (flag == 3)
		{
			st.pop();
			st.pop();
			char temp = st.top();
			st.pop();
			if (temp == 'a')
				st.push('b');
			else
				st.push('a');
			if (s[i] == 'c')
				flag = 0;
			else
				flag = 1;
		}
		if (st.empty())
		{
			st.push(s[i]);
			if (s[i] != 'c')
				flag = 1;
			else
				flag = 0;
		}
		else
		{
			if (st.top() == 'a' && s[i] == 'a')
			{
				st.pop();
				flag--;
			} else if (st.top() == 'b' && s[i] == 'b')
			{
				st.pop();
				flag--;
			} else
			{
				if (s[i] == 'c')
				{
					flag = 0;
				} else
					flag++;
				st.push(s[i]);
			}
		}
	}
	if (flag == 3)
	{
		st.pop();
		st.pop();
		char temp = st.top();
		st.pop();
		if (temp == 'a')
			st.push('b');
		else
			st.push('a');
		flag = 0;
	}
	s = "";
	while (!st.empty())
	{
		s += st.top();
		st.pop();
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
				if (s[i] == t[i] || ((i + 1 < len1) && s[i] == t[i + 1] && s[i + 1] == t[i] && s[i] != 'c' && s[i + 1] != 'c'))
				{
					if (s[i] != t[i])
						i++;
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
