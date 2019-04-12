#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int cnt=1;
    const double EPS = 1e-8;
    while(t--)
    {
        int n,a,k;
        cin>>n>>a>>k;
        double t=log10(n)/log10(k)*a;
        int x=int(t+EPS);
        cout<<"Case"<<" "<<cnt<<":"<<" "<<x+1<<endl;
        cnt++;
    }
    return 0;
}
