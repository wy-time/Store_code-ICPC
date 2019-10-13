#include <bits/stdc++.h> 
using namespace std;
typedef __int128 ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
ll exgcd(ll a, ll b, ll &x, ll &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll g = exgcd(b, a % b, x, y);
	ll t = x;
	x = y;
	y = t - a / b * y;
	return g;
}
inline __int128 read(){
    __int128 x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
inline void print(__int128 x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}
int main()
{
	//std::ios::sync_with_stdio(false);
#ifdef test
	freopen("F:\\Desktop\\question\\in.txt", "r", stdin);
#endif
#ifdef ubuntu
	freopen("/home/time/debug/debug/in", "r", stdin);
	freopen("/home/time/debug/debug/out", "w", stdout);
#endif
	ll n, p, w, d;
    n=read(),p=read(),w=read(),d=read();
	ll x, y;
	ll g = exgcd(w, d, x, y);
	if (p % g != 0)
        print(-1);
		//cout << -1 << endl;
	else
	{
		x = x * p / g;
		y = y * p / g;
		ll kx = d / g;
		ll ky = w / g;
		int flag = 1;
		if (x < 0)
		{
			ll temp = -x;
			temp = temp / kx + (temp % kx != 0);
			x += temp * kx;
			y -= temp * ky;
			if (y < 0)
				flag = 0;
		}
		if (flag && y < 0)
		{
			ll temp = -y;
			temp = temp / ky + (temp % ky != 0);
			y += temp * ky;
			x -= temp * kx;
			if (x < 0)
				flag = 0;
		}
		if (flag)
		{
			if (x + y <= n)
                print(x),printf(" "),print(y),printf(" "),print(n-x-y),printf("\n");
			else
			{
				if (kx > ky)
				{
					ll cnt = x / kx;
					x -= cnt * kx;
					y += cnt * ky;
				} else
				{
					ll cnt = y / ky;
					y -= cnt * ky;
					x += cnt * kx;
				}
				if (x < 0)
				{
					ll temp = -x;
					temp = temp / kx + (temp % kx != 0);
					x += temp * kx;
					y -= temp * ky;
					if (y < 0)
						flag = 0;
				}
				if (flag && y < 0)
				{
					ll temp = -y;
					temp = temp / ky + (temp % ky != 0);
					y += temp * ky;
					x -= temp * kx;
					if (x < 0)
						flag = 0;
				}
				if (flag)
				{
					if (x + y <= n)
                        print(x),printf(" "),print(y),printf(" "),print(n-x-y),printf("\n");
					else
                        print(-1);
						//cout << -1 << endl;
				} else
                    print(-1);
					//cout << -1 << endl;
			}
		} else
            print(-1);
			//cout << -1 << endl;
	}
	return 0;
}

