#include <iostream>
using namespace std;
void space(int k);
void shuxianleft(int k);
void shuxianright(int k);
int main()
{
    int k;
    cin>>k;

}
void space(int k)
{
    while(k--)
    {
        cout<<" ";
    }
}
void shuxianleft(int k)
{
    while(k--)
    {
        cout<<"|"<<endl;
    }
}
void shuxianright(int k)
{
    while(k--)
    {
        cout<<"|"<<endl;
    }
}
