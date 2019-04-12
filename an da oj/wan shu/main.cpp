#include <iostream>
using namespace std;
int main()
{
    int a[5]= {6, 28, 496, 8128, 33550336};
    int m=1,n=1;
    int down =-1,up=-1;
    while(cin>>m>>n&&m&&n)
    {
        down =-1,up=-1;
        int safe =0,safe2=1 ;
        int i;
        for(i=0; i<5; i++)
        {
            if(safe2)
            {
                if(m<=a[i])
                {
                    down =i;
                    safe2 =0;
                }
            }
            if(n>=a[i])
            {
                up=i;
            }
        }
        if(up==-1||down==-1)
        {
            cout<<"No"<<endl;
        }
        else
        {
            if(up==down)
                safe =1;
            for(i=down; i<up&&i>=0; i++)
            {
                cout<<a[i]<<" ";
                safe =1;
            }
            if(safe)
                cout<<a[i]<<endl;
            else
                cout<<"No"<<endl;
        }
    }
    return 0;
}
