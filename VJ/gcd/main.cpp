#include <iostream>
using namespace std;
int main()
{
    long long a,b,c;
    cin>>a>>b;
    if(a<b)
    {
        c=a;
        a=b;
        b=c;
    }
    c=a%b;
    while(c!=0)
    {
        a=b;
        b=c;
        c=a%b;
    }
    cout<<b;
    return 0;
}
