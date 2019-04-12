#include <iostream>
#include<cmath>
#include<cmath>
using namespace std;
int get_one(long long x);
int main()
{
    std::ios::sync_with_stdio(false);
    long long n,m;
    cin>>n>>m;
    long long res=0;
    int one=get_one(n);
    while(one>m)
    {
        long long temp=(long long)pow(2.0,log10(n&-n)/log10(2.0));
        res+=temp;
        n+=temp;
        one=get_one(n);
    }
    cout<<res<<endl;
    return 0;
}
int get_one(long long x)
{
    int cnt=0;
    while(x&-x)
    {
        double t=(double)(x&-x);
        double w=log10(t)/log10(2.0);
        int temp=w;
        x>>=temp+1;
        cnt++;
    }
    return cnt;
}
