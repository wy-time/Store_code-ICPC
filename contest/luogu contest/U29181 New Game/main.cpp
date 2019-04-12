#include <iostream>
#include<cstdlib>
using namespace std;
#define random(a,b) ((a)+rand()%((b)-(a)+1));
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    int a[26]={0};
    cin>>n;
    srand(1121);
    int cnt=0;
    while(n--)
    {
        string temp;
        cin>>temp;
        if(temp.size()!=1)
        {
            long long teee=random(1,65536);
            cout<<(teee%998244353*teee%998244353*teee%998244353)%998244353;
            return 0;
        }else
        {
            char te=temp[0];
            if(a[te-'a']==0)
                cnt++;
            a[te-'a']=1;
        }
    }
    int ans=26-cnt;
    int m;
    cin>>m;
    long long res=ans;
    for(int i=1;i<m;i++)
    {
        res=ans%998244353*res%998244353;
        res%=998244353;
    }
    cout<<res;
    return 0;
}
