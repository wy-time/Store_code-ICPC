#include <iostream>
#include <cmath>
using namespace std;
bool dfs(int n,int len,int sum,int a,int b,int last,int aim);
const int mod=100000007;
int result;
int main()
{
    std::ios::sync_with_stdio(false);
    long long n,s,a,b;
    cin>>n>>s>>a>>b;
    long long min1=(s*2-a*n*(n-1))/(2*n);
    long long max1=(s*2+b*n*(n-1))/(2*n);
    long long i=0;
    for(i=min1;i<=max1;i++)
    {
        dfs(n,1,i,a,b,i,s);
    }
    cout<<result;
    return 0;
}
bool dfs(int n,int len,int sum,int a,int b,int last,int aim)
{
    len++;
    if(len>=n)
    {
        if(sum+last+a<=aim)
        {
            if(sum+last+a==aim)
            {
                result++;
                result%=mod;
            }
            return false;
        }
        if(sum+last-b==aim)
        {
            result++;
            result%=mod;
            return false;
        }
    }else
    {
        if(dfs(n,len,sum+last+a,a,b,last+a,aim))
            dfs(n,len,sum+last-b,a,b,last-b,aim);
    }
    return true;
}
