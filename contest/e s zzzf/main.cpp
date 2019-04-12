#include <iostream>
using namespace std;
int main()
{
    int n;
    int i=0;
    cin>>n;
    int a=1,b=2;
    for(i=1;i<n;i++)
    {
        b=a+b;
        a=b-a;
    }
    cout<<b;
}
