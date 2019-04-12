#include<cstring>
#include <iostream>
using namespace std;
bool p[20000];
void prime();
int main()
{
    memset(p,true,sizeof(p));
    int a,b;
    prime();
    cin>>a>>b;
    int i;
    for(i=a;i<=b;i++)
    {
        int t=i;
        cout<<t<<"=";
        if(t<=3)
        {
            cout<<t<<endl;
        }else
        {
            int cnt=0;
            for(int j=2;j*j<=t;j++)
            {
                if(t%j==0)
                {
                    if(cnt!=0)
                    {
                        cout<<"*";
                    }
                    cout<<j;
                    t/=j;
                    j=1;
                    cnt++;
                }
                if(p[t])
                {
                    if(cnt!=0)
                    {
                        cout<<"*";
                    }
                    cout<<t<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
void prime()
{
    int i;
    for(i=2;i<20000;i++)
    {
        if(p[i])
        {
            for(int j=i*2;j<20000;j+=i)
            {
                p[j]=false;
            }
        }
    }

}
