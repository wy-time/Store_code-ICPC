#include <iostream>
#include<cstdlib>
using namespace std;
int gcd (int a,int b);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int op,a,b,c,d;
        int r1,r2;
        int g;
        cin>>op>>a>>b>>c>>d;
        if(op==1)
        {
            r1=a*d+c*b;
            r2=b*d;
            g=gcd(abs(r1),abs(r2));
            if(r1==0)
            {
                cout<<r1<<"/"<<1<<endl;
            }else if((r1<0&&r2>0)||(r1>0&&r2<0))
            {
                r1/=g;
                r2/=g;
                cout<<"-"<<abs(r1)<<"/"<<abs(r2)<<endl;
            }else
            {
                r1/=g;
                r2/=g;
                cout<<abs(r1)<<"/"<<abs(r2)<<endl;
            }
        }else
        {
            r1=a*d-c*b;
            r2=b*d;
            g=gcd(abs(r1),abs(r2));
            if(r1==0)
            {
                cout<<r1<<"/"<<1<<endl;
            }else if((r1<0&&r2>0)||(r1>0&&r2<0))
            {
                r1/=g;
                r2/=g;
                cout<<"-"<<abs(r1)<<"/"<<abs(r2)<<endl;
            }else
            {
                r1/=g;
                r2/=g;
                cout<<abs(r1)<<"/"<<abs(r2)<<endl;
            }
        }
    }
    return 0;
}
int gcd (int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
