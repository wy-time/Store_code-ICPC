#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[1005]={0};
        int i;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        int cnt=1;
        for(i=n-1;i>=0;i--)
        {
            if(a[i]>cnt)
            {
                cnt++;
            }else if(a[i]==cnt)
            {
                break;
            }else
            {
                cnt--;
                break;
            }
        }
        if(cnt>=2)
            cout<<cnt<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}
