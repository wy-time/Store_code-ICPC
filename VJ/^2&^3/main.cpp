#include <iostream>
using namespace std;
int main()
{
    int m,n;
    int result1,result2;
    while(cin>>n>>m)
    {
        result1=0;
        result2=0;
        int i=0;
        if(n>m)
        {
            i=n;
            n=m;
            m=i;
        }
        for(i=n;i<=m;i++)
        {
            if(i%2==0)
            {
                result1+=i*i;
            }else
                result2+=i*i*i;
        }
        cout<<result1<<" "<<result2<<endl;
    }
    return 0;
}
