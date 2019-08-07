#include <iostream>
#include <cstdio>
#include <ctime>
#include <random>
#include <set>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
#define random(a,b) (1ll*(a)+rnd()%((b)-(a)+1))
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
int main (int argc, char *argv[])
{
	#ifdef test
	freopen("F:\\Desktop\\question\\in.txt","r",stdin);
	#endif
	#ifdef ubuntu
	freopen("/home/time/debug/debug/in","w",stdout);
	//freopen("/home/time/debug/debug/out","w",stdout);
	#endif
	int seed = time(NULL);
	if (argc > 1)
	{
		seed = atoi(argv[1]);
	}
	std::mt19937 rnd(seed);
	int i=0;
	int j;
	wfor(j,0,1000)
	{
		cout<<i<<" "<<j<<" "<<1<<endl;
	}
	wfor(i,1,1001)
	{
		cout<<i<<" "<<i<<" "<<1<<endl;
	}
	return 0;
}
