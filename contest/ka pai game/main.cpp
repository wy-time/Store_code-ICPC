#include <iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s[5]={"Jin","Mu","Tu","Shui","Huo"};
    int a=0,b=0;
    while(n--)
    {
        string c,d;
        cin>>c>>d;
        int i;
        int t1,t2;
        for(i=0;i<5;i++)
        {
            if(c==s[i])
            {
                t1=i;
            }
            if(d==s[i])
            {
                t2=i;
            }
        }
        if(t1-t2==-1)
        {
            a+=3;
        }else if(t1==t2)
        {
            a++;
            b++;
        }else if(t1-t2==4)
        {
            a+=3;
        }else if(t2-t1==-1)
        {
            b+=3;
        }else if(t2-t1==4)
        {
            b+=3;
        }
    }
    if(a>b)
        cout<<"Alice"<<endl;
    else if(a<b)
    {
        cout<<"Bob"<<endl;
    }else
        cout<<"Draw"<<endl;
    return 0;
}
