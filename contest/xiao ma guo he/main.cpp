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
        double px,py,ux,uy,vx,vy,rx,ry;
        cin>>px>>py>>ux>>uy>>vx>>vy;
        double k2=(uy-vy)/(ux-vx);
        double k1=-1.0/k2;
        double b1=py-k1*px;
        double b2=uy-k2*ux;
        rx=(b2-b1)/(k1-k2);
        ry=(k1)*rx+b1;
        cout<<fixed<<setprecision(7)<<rx<<" "<<ry<<endl;
    }
    return 0;
}
