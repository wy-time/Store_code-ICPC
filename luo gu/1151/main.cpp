#include <iostream>
using namespace std;
bool slove(int i,int k);
int main()
{
    std::ios::sync_with_stdio(false);
    int k;
    cin>>k;
    int i;
    int cnt=0;
    for(i=10000;i<=30000;i++)
    {
        if(slove(i,k))
        {
            cout<<i<<endl;
            cnt++;
        }
    }
    if(cnt==0)
        cout<<"No"<<endl;
    return 0;
}
bool slove(int i,int k)
{
    int cnt=0;
    int j;
    int s[5]={0};
    for(j=10000;j>=10;j/=10)
    {
        s[cnt]=i/j;
        i%=j;
        cnt++;
    }
    s[cnt]=i;
    int a=s[0]*100+s[1]*10+s[2];
    int b=s[1]*100+s[2]*10+s[3];
    int c=s[2]*100+s[3]*10+s[4];
    if(a%k==0&&b%k==0&&c%k==0)
        return true;
    return false;
}
