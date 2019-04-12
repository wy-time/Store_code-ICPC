#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
const double E=exp(1.0);
int main()
{
    //std::ios::sync_with_stdio(false);
    int t;
    int a,b,r;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>r;
        double result=pow(E,a*1.0)*b;
        cout << fixed << setprecision(r) << result<<endl;
    }
    return 0;
}
