#include <iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    double cda,bdc,adb;
    while(cin>>cda>>bdc>>adb)
    {
        double r[3];
        r[0]=bdc-60.0;
        r[1]=cda-60.0;
        r[2]=180-r[0]-r[1];
        sort(r,r+3);
        cout<<fixed<<setprecision(4)<<r[0]<<" "<<r[1]<<" "<<r[2]<<endl;
    }
    return 0;
}
