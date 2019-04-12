#include <iostream>
#include <iomanip>
#include<math.h>
using namespace std;
int main()
{
    double a,b,c,d;
    while(cin>>a>>b>>c>>d)
    {
        cout.setf(ios::fixed);
        cout<<setprecision(2)<<sqrt((a-c)*(a-c)+(b-d)*(b-d))<<endl;
    }
    return 0;
}
