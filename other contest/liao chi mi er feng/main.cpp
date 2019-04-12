#include <iostream>
using namespace std;
int main()
{
    long long t;
    long long n,m;
    int safe =1;
    cin>>n>>m;
    long long up,down;
    if(n<=m)
    {
        cout<<n;
    }

    else
    {
        up=n-m;
        down=0;
        while(up!=down&&up-down!=1)
        {
            t=(up+down)/2;
            if((t/2*t+t/2)>n-m)
            {
                up=t;
            }
            else if((t/2*t+t/2)<n-m)
            {
                down=t;
            }
            else
            {
                cout<<t+m;
                safe =0;
                break;
            }
        }
        if(safe)
        {
            if((down/2*down+down/2)>=n-m)
                cout<<down+m;
            else
                cout<<up+m;
        }
    }
    return 0;
}
