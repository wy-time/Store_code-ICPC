#include <iostream>
using namespace std;
int slove(int x,int y);
int main()
{
    int a,b;
    cin>>a>>b;
    int max1;
    long long result;
    if(a<3||b<3)
    {
        max1=max(a,b);
        if(max1<5)
        {
            if(a-2<0||b-2<0||(a==2&&b==2))
            {
                cout<<0<<endl;
                return 0;
            }
            else
            {
                result=(max(a,b)-2)*2;
                cout<<result<<endl;
            }
        }
        else
        {
            max1-=4;
            result=4;
            int temp=2;
            while(max1>0)
            {
                if(max1<=2)
                {
                    result+=max1*temp*2;
                    max1-=2;
                    temp++;
                }
                else
                {
                    result+=2*temp*2;
                    temp++;
                    max1-=2;
                }
            }
        }
        cout<<result<<endl;
    }
    else if(a==3&&b==3)
    {
        cout<<28<<endl;
    }
    else
    {
        result=((a*b)*(a*b-1))/2;
        cout<<result<<endl;
    }
    return 0;
}
