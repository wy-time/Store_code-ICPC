#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    long long n;
    while(cin>>n)
    {
        if (n>2)
        {
            cout<<"XiaoKe"<<endl;
        }else
        {
            cout<<"XiaoNiu"<<endl;
        }
    }
    return 0;
}
