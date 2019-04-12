#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int a,b,c;
    cin>>a>>b>>c;
    int x=0,y=0,z=0;
    y=4*sqrt(a*b/c);
    x=4*sqrt(a*c/b);
    z=4*sqrt(b*c/a);
    cout<<x+y+z;
    return 0;
}
