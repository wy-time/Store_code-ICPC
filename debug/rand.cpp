#include <ctime>
#include <string> 
#include <iostream> 
#include <cstdio>
#include <cstdlib>
#include <random> 
#include<map>
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
    int len1=random(1,20);
    int len2=random(1,len1);
    int i;
    string s="",t="";
    wfor(i,0,len1)
    {
        s+='0'+random(0,1);
    }
    wfor(i,0,len2)
    {
        t+='0'+random(0,1);
    }
    cout<<s<<endl<<t<<endl;
	return 0;
}

