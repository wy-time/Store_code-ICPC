#include <iostream>
using namespace std;
int fengjie(int m);
int a[10000000];
int main()
{
    int j=0,k=0;
    long long b[1000]={0};
    int t;
    cin>>t;
    while(t--)
    {
        int c[1000];
        cin>>c[k];
        k++;
        long long i;
        for(i=c[k-1];i<=c[j];i++)
        {
            if(i%7==0)
            {
                a[i]=0;
            }
            else
            {
                a[i]=fengjie(i);
            }
        }
        long long sum=0;
        for(i=c[k-1];i<=c[j];i++)
        {
            if(a[i]==1)
            {
                b[j]+=i*i;
            }
        }
        j++;
        sum=b[j]+b[j-1];
        cout<<sum<<endl;
    }
    return 0;
}
int fengjie(int m)
{
    int t;
    int flag=1;
    while(m!=0)
    {
        t=m%10;
        m/=10;
        if(t==7)
        {
            flag =0;
            break;
        }
    }
    return flag;
}
