#include <iostream>
#include<string>
using namespace std;
typedef struct
{
    int a;
    string s;
}t;
int main()
{
    int n,m;
    cin>>n>>m;
    int i;
    t man[100000];
    //int b[100000];
    for(i=0;i<n;i++)
    {
        cin>>man[i].a>>man[i].s;
    }
    int temp=0;
    t mannow;
    mannow.a=man[temp].a;
    mannow.s=man[temp].s;
    while(m--)
    {
        int f,t1;
        cin>>f>>t1;
        if(f==1)
        {
            if(mannow.a==0)
            {
                temp+=t1;
                temp%=n;
            }else
            {
                if(temp-t1<0)
                {
                    t1-=temp;
                    while(t1>n)
                        t1-=n;
                    temp=n-t1;
                }else
                {
                    temp-=t1;
                }
            }
        }else
        {
            if(mannow.a==0)
            {
                if(temp-t1<0)
                {
                    t1-=temp;
                    while(t1>n)
                        t1-=n;
                    temp=n-t1;
                }else
                {
                    temp-=t1;
                }
            }else
            {
                temp+=t1;
                temp%=n;
            }
        }
        mannow.a=man[temp].a;
        mannow.s=man[temp].s;
    }
    cout<<mannow.s<<endl;
    return 0;
}
