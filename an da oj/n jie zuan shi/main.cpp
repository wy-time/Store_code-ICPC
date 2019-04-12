#include <iostream>
using namespace std;
void space (int n);
int main()
{
    int n;
    cin>>n;
    int t=n;
    n=n*2-1;
    int i;
    for(i=0;i<n;i++)
    {
        if(i<=t-1)
        {
            space(t-1-i);
            int x=i+1;
            while(x--)
            {
                cout<<"*";
                if(x!=0)
                    space(1);
                else
                    cout<<endl;
            }
        }else
        {
            space(i%t+1);
            int x=t-i%t-1;
            while(x--)
            {
                cout<<"*";
                if(x!=0)
                    space(1);
                else
                    cout<<endl;
            }
        }
    }
    return 0;
}
void space (int n)
{
    int i;
    for(i=0;i<n;i++)
        cout<<" ";
}
