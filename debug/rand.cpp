#include <ctime>
#include <iostream> 
#include <cstdio>
#include <cstdlib>
#include <random> 
#include<map>
using namespace std;
#define random(a,b) ((a)+mt()%((b)-(a)+1))
const int up = 10;
int main ()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    int n,m,q;
    n=random(1,100000);
    m=random(1,100000);
    q=random(1,100000);
    cout<<n<<" "<<m<<" "<<q<<endl;
    int i;
    for(i=0;i<n;i++)
    {
        int t=random(1,m);
        cout<<t<<" ";
    }
    cout<<endl;
    for(i=0;i<q;i++)
    {
        long long w=mt()+n;
        cout<<w<<endl;
    }
	return 0;
}

