#include<cstdio>
#include <iostream>
int a[131072]= {0}; //储存结果的数组
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int i=0;
    a[0]=1;
    int res=0;
    int t=0;//进位数
    int j=0,cnt=1;//cnt变量来判断那些位该乘
    for(i=2; i<=n; i++)
    {
        t=0;
        for(j=0; j<cnt; j++)
        {
            res=a[j]*i+t;
            t=res/10;
            a[j]=res%10;
        }
        while(t)
        {
            cnt++;
            a[cnt-1]+=t%10;
            t/=10;
        }
    }
    for(i=cnt-1; i>=0; i--)
    {
        printf("%d",a[i]);
    }
    return 0;
}
/*
#include <iostream>
using namespace std;
int str[1000000];        //根据题目要求设置数组的大小
int main()
{
    int n,i,j;
    int flag=1;
    int carry=0;        //设置进位
    int res=0;
    str[0]=1;
    cin>>n;
    for (i=2; i<=n; i++) //从2开始计算阶乘
    {
        for (j=1; j<=flag; j++)   //根据进位flag大小来判断当前阶乘结果的的位数
        {
            res=str[j-1]*i+carry;
            str[j-1]=res%10;
            carry=res/10;
        }
        while (carry)  //当进位大于一时将结果扩展到下一位
        {
            flag++;
            str[flag-1]=carry%10;
            carry/=10;
        }
    }
    for (i=flag-1; i>=0; i--)  //将结果数组倒序输出，注意最后一位是"i=flag-1",因为"flag=1" 对应str[0],以此类推
    {
        cout<<str[i];
    }
    return 0;
}*/

