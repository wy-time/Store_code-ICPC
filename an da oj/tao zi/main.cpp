#include <iostream>
using namespace std;
int main()
{
    int n=1;
    int sum;
    while(cin>>n&&n)
    {
        sum=1;
        n-=1;
        while(n--)
        {
            sum=(sum+1)*2;
        }
        cout<<sum<<endl;
    }
    return 0;
}
