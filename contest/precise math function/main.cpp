#include <iostream>
#include<iomanip>
#include<cmath>
using namespace std;
const double PI=acos(-1.0);
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        double r=pow(1.0*n,PI);
        cout<<fixed<<setprecision(x)<<r<<endl;
    }
    return 0;
}
