#include <iostream>
#include<algorithm>
#include<cstring>
#include<math.h>
using namespace std;
//#define N 50000001
int a[1000000];
//bool b[N];
void prime();
int main()
{
    int n;
    //memset(b,true,sizeof(b));
//    prime();
    while(cin>>n)
    {
        int i=0;
        int j=0;
        for(j=2;j<=sqrt(n)&&n!=1;j++)
        {
            if(n%j==0)
            {
                a[i]=j;
                n/=j;
                j=1;
                i++;
                /*if(b[n])
                {
                    a[i]=n;
                    i++;
                    break;
                }*/
            }
        }
        if(n!=1)
        {
            a[i]=n;
            i++;
        }
        sort(a,a+i);
        for(j=0;j<i;j++)
        {
            if(j!=0)
                cout<<" ";
            cout<<a[j];
        }
        cout<<endl;
    }
    return 0;
}
/*void prime()
{
    int i,j;
    for(i=2;i*i<=N;i++)
    {
        if(b[i])
        {
            for(j=i*i;j<N;j+=i)
            {
                b[j]=false;
            }
        }
    }
}*/
