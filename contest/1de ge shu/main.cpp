#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int sum=0;
        int temp=10;
        sum+=n/10;
        int t=n;
        n/=10;
        while(n>0)
        {
            if(n%10>1)
            {
                n/=10;
                sum+=(n+1)*temp;
                temp*=10;
            }
            else if(n%10==1)
            {
                sum+=n/10*temp;
                sum+=(t%temp)+1;
                temp*=10;
                n/=10;
            }else
            {
                sum+=n/10*temp;
                temp*=10;
                n/=10;
            }
        }
        if(t%10>=1)
            sum++;
        cout<<sum<<endl;
    }
    return 0;
}
