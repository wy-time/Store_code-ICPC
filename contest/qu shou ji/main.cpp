#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,k;
        double r;
        cin>>a>>b>>k;
        if(a==0&&b!=0)
            r=1.000;
        else if(b==0)
            r=0.000;
        else
        {
            r=1.0*b/(a+b);
        }
        cout<<fixed<<setprecision(3)<<r<<endl;
    }
    return 0;
}
