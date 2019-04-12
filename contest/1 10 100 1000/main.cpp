#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a;
        cin>>a;
        double i;
        int sum=0;
        for(i=0;sum<a;i++)
        {
            sum=1+(i/2*i+i/2);
        }
        if(sum==a)
        {
            cout<<1<<endl;
        }else
            cout<<0<<endl;
    }
    return 0;
}
