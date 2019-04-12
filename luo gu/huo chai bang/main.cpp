#include <iostream>
using namespace std;
int slove(int n);
int a[2000000]={6,2,5,5,4,5,6,3,7,6};
int main()
{

    int n;
    cin>>n;
    n-=4;
    int maxs=1;
    int cnt1=0;
    int cnt=0;
    if(n<9)
        cout<<0<<endl;
    else
    {
        cnt1=n/3-2;
        while(cnt1--)
        {
            maxs=maxs*10+7;
        }
        int i,j;
        for(i=0;i<maxs;i++)
        {
            for(j=0;j+i<maxs;j++)
            {
                if(a[i]==0)
                    slove(i);
                if(a[j]==0)
                    slove(j);
                if(a[i+j]==0)
                    slove(i+j);
                if(a[i]+a[j]+a[i+j]==n)
                {
                    cnt++;
                }

            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
int slove(int n)
{
    int t;
    if(a[n]==0)
    {
        t=a[n%10]+slove(n/10);
        a[n]=t;
    }else
    {
        t=a[n];
    }
    return t;
}
