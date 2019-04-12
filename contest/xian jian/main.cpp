#include<iostream>
using namespace std;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int safe=1;
        while(1)
        {
            a-=d;
            if(a<=0)
            {
                safe=1;
                break;
            }
            b-=c;
            if(b<=0)
            {
                safe=0;
                break;
            }
        }
        if(safe)
        {
            cout<<"Yes"<<endl;
        }else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
