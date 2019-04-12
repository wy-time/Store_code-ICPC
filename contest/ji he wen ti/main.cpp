#include <iostream>
using namespace std;
bool is[1000000005];
int a[100005];
int main()
{
    std::ios::sync_with_stdio(false);
    int n,a,b;
    cin>>n>>a>>b;
    int i;
    if(n%2!=0)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        for(i=0; i<n; i++)
        {
            int t;
            cin>>a[i];
            is[a[i]]=true;
        }
        for(i=0; i<n; i++)
        {
            if(is[b-a[i]])
            {
                is[a[i]]=false;
                is[b-a[i]]=false;

            }
            if()
        }
    }
    return 0;
}
