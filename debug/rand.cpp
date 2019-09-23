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
    int n=random(1,20);
    int i;
    cout<<n<<endl;
    char ma[330];
    ma[1]='a';
    ma[2]='e';
    ma[3]='i';
    ma[4]='o';
    ma[5]='u';
    ma[6]='c';
    ma[7]='c';
    ma[8]='c';
    ma[9]='c';
    ma[10]='c';
    for(i=0;i<n;i++)
    {
        int len=random(1,10);
        int j;
        for(j=0;j<len;j++)
        {
            int te=random(1,10);
            cout<<ma[te];
        }
        cout<<endl;
    }
	return 0;
}

