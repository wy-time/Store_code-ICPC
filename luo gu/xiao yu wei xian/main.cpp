#include <iostream>
using namespace std;
int main()
{
    int s,x;
    cin>>s>>x;
    double sum=0;
    double t=7;
    while(sum<s-x)
    {
        sum+=t;
        t*=0.98;
    }
    sum+=t;
    if(sum>s+x)
    {
        cout<<"n"<<endl;
    }else
    {
        cout<<"y"<<endl;
    }
    return 0;
}
