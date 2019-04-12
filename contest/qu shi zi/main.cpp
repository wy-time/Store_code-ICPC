#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    while(cin>>n)
    {
        if(n==0)
            break;
        int a[105]={0};
        int i;
        int flag=0;
        for(i=0;i<n;i++)
        {
            int temp=0;
            cin>>temp;
            a[temp]++;
        }
        for(i=0;i<105;i++)
        {
            if(a[i]%2!=0)
            {
                flag=1;
                break;
            }
        }
        if(flag)
            cout<<"Win"<<endl;
        else
            cout<<"Lose"<<endl;
    }
    return 0;
}
