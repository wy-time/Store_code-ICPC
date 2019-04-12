#include <iostream>
using namespace std;
typedef long long LL;
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    unsigned long long k,m;
    while(t--)
    {
        cin>>k>>m;
        unsigned long long r;
        LL mm=6*m;
        if(k>=3)
        {
            r=((k+1)%mm*(k+2)%mm*(k+3)%mm)/6;
        }else
        {
            if(k==0)
                r=1;
            else if(k==1)
                r=4;
            else if(k==2)
                r=10;
        }
        cout<<r%m<<endl;
    }
    return 0;
}
