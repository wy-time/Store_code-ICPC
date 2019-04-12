#include <iostream>
using namespace std;
int main()
{
    int n;
    int i,j;
    int sum,cnt=0;;
    int num1,num2;
    cin>>n;
    while(n--)
    {
        cnt=0;
        cin>>num1>>num2;
        if(num1>num2)
        {
            i=num1;
            num1=num2;
            num2=i;
        }
        for(i=num1;i<=num2;i++)
        {
            sum=0;
            for(j=1;j<i;j++)
            {
                if(i%j==0)
                {
                    sum+=j;
                }
            }
            if(sum==i)
            {
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}
