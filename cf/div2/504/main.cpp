// #include <iostream>
// #ifdef test
// #include <cstdio>
// #endif
// #include <string>
// using namespace std;
// typedef long long ll;
// #define wfor(i,j,k) for(i=j;i<k;++i)
// #define mfor(i,j,k) for(i=j;i>=k;--i)
// int main()
// {
// 	std::ios::sync_with_stdio(false);
// #ifdef test
// 	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
// #endif
// 	int n, m;
// 	cin >> n >> m;
// 	string s, t;
// 	cin >> s >> t;
// 	if (s.size() == 1 && s[0] == '*')
// 	{
// 		cout << "YES" << endl;
// 		return 0;
// 	}
// 	if (s.size() > t.size() + 1)
// 		cout << "NO" << endl;
// 	else
// 	{
// 		if (s.find('*') == string::npos)
// 		{
// 			if (s == t)
// 				cout << "YES" << endl;
// 			else
// 				cout << "NO" << endl;
// 		} else
// 		{
// 			int pos = s.find('*');
// 			if (pos == 0)
// 			{
// 				if (s.substr(1) == t || t.find_last_of(s.substr(1)) == (t.size() - s.size() + 1))
// 					cout << "YES" << endl;
// 				else
// 					cout << "NO" << endl;
// 			} else
// 			{
// 				string temp1, temp2;
// 				temp1 = s.substr(0, pos);
// 				temp2 = s.substr(pos + 1);
// 				int tp1, tp2;
// 				tp1 = t.find(temp1);
// 				if (tp1 == 0)
// 				{
// 					if (pos == s.size() - 1)
// 						cout << "YES" << endl;
// 					else
// 					{
// 						tp2 = t.find_last_of(temp2);
// 						if (tp2 >= pos)
// 						{
// 							if (tp2 == pos)
// 							{
// 								if (temp2 == t.substr(pos))
// 									cout << "YES" << endl;
// 								else
// 									cout << "NO" << endl;
// 							} else
// 							{
// 								if (temp2 == t.substr(tp2))
// 									cout << "YES" << endl;
// 								else
// 									cout << "NO" << endl;
// 							}
// 						} else
// 							cout << "NO" << endl;
// 					}
// 				} else
// 					cout << "NO" << endl;
// 			}
// 		}
// 	}
// 	return 0;
// }
#include <iostream>
#ifdef test
#include <cstdio>
#endif
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
char s[200005];
char t[200005];
int main()
{
	std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	cin >> s >> t;
	int i;
	int f1 = -1, f2 = n;
	wfor(i, 0, n)
	{
		if (s[i] == t[i])
			f1++;
		else
			break;
	}
	int j = m - 1;
	mfor(i, n - 1, 0)
	{
		if (s[i] == t[j])
			f2--;
		else
			break;
		j--;
	}
	if ((f1 == n - 1 && m == n) || (s[f1 + 1] == '*' && s[f2 - 1] == '*' && f1 <= j))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
