/*#include <stdio.h>
main()
{
    unsigned long s=0,f1=1,f2=1,f3=1,n=0;
    scanf("%d",&n);

    if(n>2)
    for(s=3;s<=n;s++)
    {
        f3=(f2+f1)%10007;
        f1=f2;
        f2=f3;
    }

    printf("%d",f3);
    return 0;
}*/
#include <iostream>
using namespace std;
int fb(int n);
int main()
{
    int n;//i;
    cin>>n;
    //for(i=1;i<=n;i++)
   // {
        int t=fb(n);
        cout<<"   ำเสýฮช"<<t<<endl;
   // }
    return 0;
}
int fb(int n)
{
    if(n==1||n==2)
    {
        return 1%10007;
    }
    else return fb(fb(n-1)%10007+fb(n-2)%10007);
    /*{
        return fb(n-1)+fb(n-2);
    }
    else
    {
        return fb(n-1)+fb(n-2)-10007;
    }*/
}

