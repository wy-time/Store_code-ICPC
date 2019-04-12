#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int cnt=0;
    int a[105];
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int flag=1;
    if(n<30)
    {
        cnt=0;
    }else
    {
        for(i=0;n-i>=30;i++)
        {
            flag=1;
            int j=0;
            for(j=i;j<29+i;j++)
            {
                if(a[j]>a[j+1])
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                cnt++;
                break;
            }
        }
    }
    if(cnt!=0)
    {
        cout<<"yes"<<endl;
    }else
    {
        cout<<"no"<<endl;
    }
    return 0;
}
