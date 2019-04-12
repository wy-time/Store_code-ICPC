#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int a;
        int sum=1;
       while(n--)
       {
           cin>>a;
           if(a%2!=0)
           {
               sum*=a;
           }
       }
       cout<<sum<<endl;
    }
    return 0;
}
