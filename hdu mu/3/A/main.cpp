#include <iostream>
#include <deque>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
const int maxn = 1e7 + 5;
struct st
{
	ll v;
	ll pos;
	// ll cnt;
};
st num[maxn];
int resmax[maxn];
int rescnt[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	ll t;
	cin >> t;
	while (t--)
	{
		deque<st> dq;
		ll n, m, k, p, q, r, mod;
		cin >> n >> m >> k >> p >> q >> r >> mod;
		ll i;
		wfor(i, 1, k + 1)
		{
			cin >> num[i].v;
			num[i].pos = i;
		}
		if (k < n)
		{
			wfor(i, k + 1, n + 1)
			{
				num[i].v = (p * num[i - 1].v + q * i + r) % mod;
				num[i].pos = i;
				// num[i].cnt = 0;
			}
		}
		dq.push_back(num[n]);
		// int cnt = 0;
		mfor(i, n - 1, n - m + 1)
		{
			// num[i].cnt = dq.size();
			if (num[i].v < dq.back().v)
				dq.push_back(num[i]);
			else
			{
				while (!dq.empty() && num[i].v >= dq.back().v)
				{
					// if (num[i].v > dq.back().v)
					// cnt++;
					dq.pop_back();
				}
				// num[i].cnt = cnt;
				dq.push_back(num[i]);
			}
		}
		rescnt[n - m + 1] = dq.size();
		resmax[n - m + 1] = dq.front().v;
		mfor(i, n - m, 1)
		{
			// num[i + m - 1].cnt = dq.size();
			if (num[i].v < dq.back().v)
				dq.push_back(num[i]);
			else
			{
				while (!dq.empty() && num[i].v >= dq.back().v)
				{
					// if (num[i + m - 1].v > dq.back().v)
					// cnt++;
					dq.pop_back();
				}
				// num[i + m - 1].cnt = cnt;
				dq.push_back(num[i]);
			}
			if (dq.front().pos <= i + m - 1 )
			{
				rescnt[i] = dq.size();
				resmax[i] = dq.front().v;
			}
			else
			{
				dq.pop_front();
				resmax[i] = dq.front().v;
				rescnt[i] = dq.size();
			}
		}
		ll outa = 0;
		ll outb = 0;
		wfor(i, 1, n - m + 2)
		{
			outa += resmax[i] ^ i;
			outb += rescnt[i] ^ i;
			// cout << rescnt[i] << " ";
		}
		cout << outa << " " << outb << endl;
	}
	return 0;
}
