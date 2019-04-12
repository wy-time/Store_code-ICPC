#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        bool flag=true;
        double a,b;
        cin>>a>>b;
        if(a>=0&&b>=0)
        {
            if(a<b)
                flag=false;
        }else if(a<0&&b<0)
        {
            if(a<b)
                flag=false;
        }else
        {
            if(a<0&&b>=0)
            {
                if((a+3.1415*2)-b>3.1415)
                    flag=false;
            }else if(a>=0&&b<0)
            {
                if((b+2*3.1415)-a<3.1415)
                    flag=false;
            }
        }
        if(flag)
            cout<<"clockwise"<<endl;
        else
            cout<<"counterclockwise"<<endl;
    }
    return 0;
}
