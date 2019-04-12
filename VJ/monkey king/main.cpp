#include <iostream>
using namespace std;
int main()
{
    int n,day1;
    while(cin>>n)
    {
        day1=1;
        n-=1;
        while(n--)
        {
            day1=(day1+1)*2;
        }
        cout<<day1<<endl;
    }
    return 0;
}
