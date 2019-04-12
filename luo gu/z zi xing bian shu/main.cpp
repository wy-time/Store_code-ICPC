#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int safe =2;
    int i=0,j=1;
    int cnt=0;
    if(n==1)
    {
        cout<<"1/1"<<endl;
    }else if(n==2)
    {
        cout<<"1/2"<<endl;
    }else if(n==3)
    {
        cout<<"2/1"<<endl;
    }else
    {
        i=1;j=0;
        for(cnt=4;cnt<=n;cnt++)
        {
            if(i==0&&safe==3)
            {
                j+=1;
                safe=2;
                continue;
            }else if(j==0&&safe==2)
            {
                i+=1;
                safe=3;
                continue;
            }
            if(safe==3)
            {
                i-=1;
                j+=1;
            }else if(safe==2)
            {
                j-=1;
                i+=1;
            }
        }
        cout<<i+1<<"/"<<j+1<<endl;
    }
    return 0;
}
