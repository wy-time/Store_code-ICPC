#include <iostream>
#include<string.h>
#include<math.h>
char s[100001];
char a[200000];
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        cin>>s;
        int r=0;
        int i=0,j=0,t,cnt;
        int c[12]={0};
        int len=strlen(s);
        for(i=len-1; i>=0; i--)
        {
            if(s[i]>='A')
            {
                t=(s[i]-'A'+10);
                while(t!=0)
                {
                    c[j]=t%2;
                    t/=2;
                    j++;
                }
                while (j%4!=0)
                    j++;
            }
            else
            {
                t=s[i]-'0';
                if(t==0)
                {
                    j+=4;
                }
                while(t!=0)
                {
                    c[j]=t%2;
                    t/=2;
                    j++;
                }
                while (j%4!=0)
                    j++;
            }
            if(j!=12)
            {
                continue;
            }
            else
            {
                int sum=0;
                int q=0;
                cnt=0;
                for(j=0;j<12;j++)
                {
                    sum+=c[j]*pow(2.0,q);
                    q++;
                    cnt++;
                    if(cnt==3)
                    {
                        a[r]=sum+'0';
                        r++;
                        q=0;
                        sum=0;
                        cnt=0;
                    }
                }
                j=0;
                memset(c,0,sizeof(c));
            }

        }
        cnt =0;
        if(j!=0)
        {
            while((j+1)%3!=0)
                j++;
            int sum=0;
            int q=0;
            for(i=0;i<=j;i++)
            {
                sum+=c[i]*pow(2.0,q);
                q++;
                cnt++;
                if(cnt==3)
                {
                    a[r]=sum+'0';
                    r++;
                    q=0;
                    sum=0;
                    cnt=0;
                }
            }
        }
        r--;
        while(a[r]=='0')
        {
            r--;
        }
        for(;r>=0;r--)
        {
            cout<<a[r];
        }
        cout<<endl;
    }
    return 0;
}
