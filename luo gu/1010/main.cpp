#include <iostream>
using namespace std;
void slove(int n);
char ans [2][5]={"2(0)","2"};
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    slove(n);
    return 0;
}
void slove(int n)
{
    bool fflag=true;
    int a[16]={0};
    int cnt=0;
    while(n)
    {
        if(n&1)
        {
            a[cnt]++;
        }
        cnt++;
        n>>=1;
    }
    int i;
    for(i=15;i>=0;i--)
    {
        if(a[i]!=0)
        {
            if(i==0||i==1)
            {
                if(!fflag)
                {
                    cout<<"+";
                }
                cout<<ans[i];
                fflag=false;
            }else
            {
                if(!fflag)
                    cout<<"+";
                cout<<"2(";
                slove(i);
                cout<<")";
                fflag=false;
            }
        }
    }
}
