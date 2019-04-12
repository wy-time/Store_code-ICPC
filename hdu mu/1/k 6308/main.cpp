#include <iostream>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
string a;
int s,f,cc,m=6,op,sj,fj,ep;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>cc;
    while(cc--)
    {
        cin>>s>>f>>a;
        int u=a.size();
        if(a[u-2]=='.')
        {
            int f1=0;
            if(a[u-4]!='+'&&a[u-4]!='-')
            {
                f1=(a[u-4]-'0')*10+a[u-3]-'0';
                if(a[u-5]=='+')
                {
                    op=1;
                    ep=1;
                }
                else
                {
                    op=-1;
                    ep=-1;
                }
            }
            else
            {

                f1=a[u-3]-'0';
                if(a[u-4]=='+')
                {
                    op=1;
                    ep=1;
                }
                else
                {
                    op=-1;
                    ep=-1;
                }
            }
            sj=op*f1-8;
            fj=ep*(a[u-1]-'0')*m;
            s+=sj+48;
            s%=24;
            f+=fj;
            if(f<0)
            {
                f=60+f;
                s=(s-1+24)%24;

            }
            else if(f>=60)
            {
                f-=60;
                s=(s+1+24)%24;
            }
        }

        else
        {
            int f1=0;
            if(a[u-2]!='+'&&a[u-2]!='-')
            {
                f1=(a[u-2]-'0')*10+a[u-1]-'0';
                if(a[u-3]=='+')
                {
                    op=1;
                }
                else
                {
                    op=-1;
                }
            }
            else
            {

                f1=a[u-1]-'0';
                if(a[u-2]=='+')
                {
                    op=1;
                }
                else
                {
                    op=-1;
                }


            }

            sj=op*f1-8;
            s+=sj+48;
            s%=24;
        }
        if(s<10)
            cout<<"0"<<s<<":";
        else
            cout<<s<<":";

        if(f<10)
            cout<<"0"<<f<<endl;
        else
            cout<<f<<endl;


    }
    return 0;
}
