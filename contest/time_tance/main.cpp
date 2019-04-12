#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    //std::ios::sync_with_stdio(false);
    int n;
    scanf("%d",&n);
    long long d1,h1,m1,s1,d2,h2,m2,s2;
    while(n--)
    {
        scanf("%lldday%lld:%lld:%lld",&d1,&h1,&m1,&s1);
        scanf("%lldday%lld:%lld:%lld",&d2,&h2,&m2,&s2);
        long long temp1=d1*86400+h1*3600+m1*60+s1;
        long long temp2=d2*86400+h2*3600+m2*60+s2;
        cout<<temp2-temp1<<endl;;
    }
    return 0;
}
