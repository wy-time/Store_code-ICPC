#include<algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a[3];
        int i;
        for(i=0;i<3;i++)
        {
            cin>>a[i];
        }
        sort(a,a+i);
        if(a[0]+a[1]>a[2])
        {
            cout<<a[0]+a[1]+a[2]<<endl;;
        }else
        {
            cout<<"Wrong"<<endl;
        }
    }
    return 0;
}
