#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int a[50]={1,1};
    int i;
    for (i=2;i<50;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }
    int n;
    cin>>n;
    bool flag=false;
    for(i=0;i<50;i++)
    {
        if(n==a[i])
        {
            flag=true;
            break;
        }
    }
    if(flag)
    {
        cout<<"Sha";
    }else
        cout<<"Xian";
    return 0;
}
