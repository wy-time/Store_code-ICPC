#include <iostream>
using namespace std;
int main()
{
    long long a,b,c,t1,t2;;
    cin>>a>>b;
    t1=a;
    t2=b;
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
    cout<<t1*(t2/b);
    return 0;
}
