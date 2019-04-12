#include <iostream>
#include<cstring>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int cnt1,cnt2,cnt3;
    while(t--)
    {
        int n;
        cnt1=cnt2=cnt3=0;
        cin>>n;
        int i;
        int a;
        for(i=0;i<n;i++)
        {
            cin>>a;
            if(a%3==0)
            {
                cnt1++;
            }else if(a%3==1)
                cnt2++;
             else
                cnt3++;
        }
        cout<<cnt1/2+min(cnt2,cnt3)<<endl;
    }
    return 0;
}
