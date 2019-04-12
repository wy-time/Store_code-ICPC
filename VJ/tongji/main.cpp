#include <iostream>
using namespace std;
int main()
{
    int n;
    double a;
    cin>>n;
    int cnt1,cnt2,cnt3;
    while(n!=0)
    {
        int t=n;
        cnt1=cnt2=cnt3=0;
        while(t--)
        {
            cin>>a;
            if(a>0)
                cnt1++;
            else if(a==0)
                cnt2++;
            else
                cnt3++;
        }
        cout<<cnt3<<" "<<cnt2<<" "<<cnt1<<endl;
        cin>>n;
    }
    return 0;
}
