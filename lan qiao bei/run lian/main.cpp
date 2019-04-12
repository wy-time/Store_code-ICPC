#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int flag =0;
    if(n%4==0&&n%100!=0)
    {
        flag =1;
    }else if(n%400==0)
    {
        flag =1;
    }
    if(flag)
    {
        cout<<"yes"<<endl;
    }else
        cout<<"no"<<endl;
    return 0;
}
