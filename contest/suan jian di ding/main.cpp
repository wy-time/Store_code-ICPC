#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    //std::ios::sync_with_stdio(false);
    double a,b,c;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        double result=a*c/b;
        char s[55];
        sprintf(s,"%.12f",result);
        bool flag2=false;
        char *p=strchr(s,'.');
        p+=3;
        if(*p>'5')
        {
            (*(p-1))++;
            *p='\0';
        }
        else if(*p<'5')
            *p='\0';
        else if(*p=='5')
        {
            char *tt=p;
            for(tt++;*tt!='\0';tt++)
            {
                if(*tt!='0')
                {
                    flag2=true;
                    break;
                }
            }
            if(flag2)
            {

                (*(p-1))++;
                *p='\0';
            }else
            {
                int t=*(p-1)-'0';
                if(t%2==0)
                    *p='\0';
                else
                {
                    (*(p-1))++;
                    *p='\0';
                }
            }
        }
        int len=strlen(s);
        int temp=0;
        int i;
        bool flag=false;
        for(i=len-1; i>=0; i--)
        {
            if(s[i]=='.')
                continue;
            s[i]+=temp;
            if(temp!=0)
                temp--;
            if(s[i]>'9')
            {
                if(i==0)
                    flag=true;
                temp++;
                s[i]-='0';
                s[i]%=10;
                s[i]+='0';
            }
        }
        if(flag)
            cout<<"1";
        cout<<s<<endl;
    }
    return 0;
}
