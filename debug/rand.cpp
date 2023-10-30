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
    //int t=random(1,5);
    cout<<1<<endl;
    int l=random(1,10);
    int n=random(1,10);
    int i;
    cout<<l<<" "<<n<<endl;
    wfor(i,0,n)
    {
        int u,v;
        u=random(1,l);
        v=random(u,l);
        cout<<u<<" "<<v<<endl;
    }
}

