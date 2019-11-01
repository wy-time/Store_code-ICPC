#include <ctime>
#include <string> 
#include <iostream> 
#include <cstdio>
#include <cstdlib>
#include <random> 
#include<map>
#include <set> 
using namespace std;
typedef long long ll;
#define random(a,b) ((ll)a+mt()%(1ll+(b)-(a)))
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
const int up = 10;
int main ()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    int n=random(1,10);
    int m=random(1,10);
    cout<<n<<" "<<m<<endl;
    int i;
    wfor(i,0,m)
    {
        int op=random(0,1);
        int l,r;
        l=random(1,n);
        r=random(1,n);
        if(l>r)
            swap(l,r);
        cout<<op<<" "<<l<<" "<<r<<endl;
    }
	return 0;
}

