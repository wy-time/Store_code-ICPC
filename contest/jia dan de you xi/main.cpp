#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int i;
        int sum=0;
        for(i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            sum+=temp;
        }
        cout<<sum/n<<endl;
    }
    return 0;
}
