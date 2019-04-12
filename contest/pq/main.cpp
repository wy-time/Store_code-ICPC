#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        double a,b;
        cin>>a>>b;
        double r=a/b;
        int temp=(int)r;
        if(temp==r||r<=0)
            r-=1.0;
        int c=(int)r;
        cout<<c<<endl;
    }
    return 0;
}
