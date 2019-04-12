#include <iostream>
using namespace std;
int slove (int n);
int b[7]= {2,5,10,20,50,100,10000};
int main()
{
    int n=1;
    int ccc;
    while(cin>>n&&n)
    {
        ccc=0;
        int cnt=0;
        if(n<=100)
        {
            int i;

            for(i=0; i<6; i++)
            {
                int t=n;
                while(t>0)
                {
                    if(i>0&&t-b[i]>=0)
                    {
                        ccc++;
                    }
                    cnt+=t/b[i];
                    t-=b[i+1];
                }
            }
        }
        if(n>100&&n<=200)
        {
            int f=n-100;
            int i;
            for(i=0;i<6; i++)
            {
                int t=n;

                while(t>0)
                {
                    ccc++;
                    cnt+=t/b[i]-f;
                    t-=b[i+1];
                }
            }
        }
        if(n>200)
        {
            int i;

            for(i=2; i<6; i++)
            {
                int t=n;
                while(t>0)
                {
                    ccc++;
                    cnt+=t/b[i];
                    t-=b[i+1];
                }
            }
        }
        cout<<cnt+ccc<<endl;
    }
    return 0;
}
