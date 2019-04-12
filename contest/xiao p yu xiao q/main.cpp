#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b;
        cin>>a>>b;
        long long l=0,r=1000000;
        long long mid=0;
        while(l<r-1)
        {
            mid=(r+l)/2;
            if(a*b<mid*mid*mid)
            {
                r=mid;
            }else if(a*b>mid*mid*mid)
            {
                l=mid;
            }else
            {
                break;
            }
        }
        if(a*b==mid*mid*mid)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
