#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int max1,min1;
    int i;
    int temp;
    cin>>temp;
    max1=min1=temp;
    int p1,p2;
    p1=p2=0;
    for(i=1;i<n;i++)
    {
        cin>>temp;
        if(temp>max1)
        {
            max1=temp;
            p1=i;
        }
        if(temp<min1)
        {
            min1=temp;
            p2=i;
        }
    }
    int result=max(p1,max(p2,max(n-1-p1,n-1-p2)));
    cout<<result<<endl;
    return 0;
}
