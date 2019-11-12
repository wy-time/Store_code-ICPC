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
    int n=random(10,100);
    int i;
    wfor(i,0,n)
    {
        int t=random(1,2);
        if(t==1)
            cout<<'v';
        else
            cout<<'o';
    }
	return 0;
}

