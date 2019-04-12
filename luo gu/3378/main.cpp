#include <iostream>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
const int maxn = 1000005;
ll num[maxn];
void ins (int x);
void shift_up(int n);
void shift_down(int n);
void swap(int a, int b);
int now = 1;
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	while (n--)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			ll x;
			cin >> x;
			ins(x);
		} else if (op == 2)
		{
			cout << num[1] << endl;
		} else
		{
			num[1] = num[now - 1];
			now--;
			if (now != 1)
				shift_down(1);
			else
				num[1] = 0;
		}
	}
	return 0;
}
void ins (int x)
{
	num[now] = x;
	shift_up(now);
	now++;
}
void shift_up(int n)
{
	while (n / 2 >= 1 && num[n] < num[n / 2])
	{
		ll temp = num [n];
		num[n] = num[n / 2];
		num[n / 2] = temp;
		n = n / 2;
	}
}
void shift_down(int n)
{
	while ((n << 1) < now && num[n] > min(num[n << 1], num[n << 1 | 1]))
	{
		if (num[n] > max(num[n << 1], num[n << 1 | 1]))
		{
			if (num[n << 1] < num[n << 1 | 1])
			{
				swap(n << 1, n);
				n <<= 1;
			} else
			{
				swap(n << 1 | 1, n);
				n = n << 1 | 1;
			}
		} else
		{
			if (num[n] > num[n << 1])
			{
				swap(n << 1, n);
				n <<= 1;
			} else
			{
				swap(n << 1 | 1, n);
				n = n << 1 | 1;
			}
		}
	}
}
void swap(int a, int b)
{
	ll temp = num[a];
	num[a] = num[b];
	num[b] = temp;
}

