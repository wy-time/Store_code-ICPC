#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int sum=0;
    while(n)
    {
        sum+=n%10;
        n/=10;
        if(n==0)
        {
            if(sum<10)
            {
                cout<<sum<<endl;
                break;
            }else
            {
                n=sum;
                sum=0;
            }
        }
    }
    return 0;
}
