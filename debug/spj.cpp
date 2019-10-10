#include <iostream>
#include <fstream> 
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const int maxn=1e5+5;
int num[maxn];
int num1[maxn];
int num2[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    fstream _out;
    fstream _stdout;
    _out.open("out",ios::in);
    _stdout.open("stdout",ios::in);
    int n;
    cin>>n;
    int i;
    wfor(i,0,n)
    {
        cin>>num[i];
        _out>>num1[i];
        _stdout>>num2[i];
    }
    _out.close();
    _stdout.close();
    int flag=0;
    wfor(i,0,n)
    {
        int temp;
        temp=num1[i];
        if(temp!=num[i]&&temp!=-1*num[i]-1)
        {
            flag=1;
            break;
        }
    }
    _out.open("out",ios::out|ios::trunc);
    _stdout.open("stdout",ios::out|ios::trunc);
    if(flag==1)
        _out<<"operator wrong"<<endl;
    else
    {
        ll sum1=1;
        ll sum2=1;
        wfor(i,0,n)
        {
            ll temp1,temp2;
            temp1=num1[i];
            temp2=num2[i];
            sum1*=temp1;
            sum2*=temp2;
        }
        if(sum1==sum2)
        {
            _out<<"OK"<<endl;
        }else
            _out<<"number is different"<<endl;
    }
    _stdout<<"OK"<<endl;
    _out.close();
    _stdout.close();
    return 0;
}
