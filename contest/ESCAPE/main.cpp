#include <iostream>
#include<math.h>
using namespace std;
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long safe =0;
        long long n;
        cin>>n;
        long long i;
        int cnt=0;
        for(i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                cnt++;
                if(i*i==n&&cnt==1)
                {
                    safe=0;
                    break;
                }
                else
                {
                    safe =1;
                    break;
                }
            }
        }
        if(safe)
        {
            cout<<"escape"<<endl;
        }else
            cout<<"trapped"<<endl;
    }
    return 0;
}
