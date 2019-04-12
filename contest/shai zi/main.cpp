#include <iostream>
using namespace std;
int main()
{
    int p;
    int safe=1;
    cin>>p;
    int t[4]= {0};
    int s[36];
    int a[6],b[6];
    int i,j,k;
    for(i=0; i<6; i++)
    {
        cin>>a[i];
    }
    for(i=0; i<6; i++)
    {
        cin>>b[i];
    }
    k=0;
    for(i=0; i<6; i++)
    {
        for(j=0; j<6; j++)
        {
            s[k]=a[i]+b[j];
            k++;
        }
    }
    for(i=0; i<36; i++)
    {
        t[s[i]%p]++;
    }
    for(i=0; i<p-1; i++)
    {
        if(t[i]!=t[i+1])
        {
            safe=0;
            break;
        }
    }
    if(safe)
    {
        cout<<"YES"<<endl;
    }else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
