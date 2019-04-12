#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    long long n,a,b,q,d;
    cin>>n>>a>>b>>q;
    d=(b-a)/n;
    int l,r;
    while(q--)
    {
        cin>>l>>r;
        long long temp1=l*a+l*(l-1)*d/2;
        long long temp2=(r+1)*a+(r+1)*r*d/2;
        cout<<temp2-temp1<<endl;
    }
    return 0;
}
