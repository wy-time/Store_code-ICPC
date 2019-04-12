#include <iostream>
using namespace std;
int slove (int a);
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        int t1=slove(a);
        int t2=slove(b);
        if(t1==b&&t2==a)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
int slove (int a)
{
    int i;
    int sum=0;
    for(i=1; i<a; i++)
    {
        if(a%i==0)
        {
            sum+=i;
        }
    }
    return sum;
}
