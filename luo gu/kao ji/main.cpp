#include <iostream>
#include<cstring>
#include<cstring>
using namespace std;
int x[100000][10];
int main()
{
    int n;
    int t=0;
    cin>>n;
    if(n<10||n>=30)
    {
        cout<<"0"<<endl;
        return 0;
    }
    int a,b,c,d,e,f,g,h,i,j;
    for(a=1;a<=3;a++)
    {
        for(b=1;b<=3;b++)
        {
            for(c=1;c<=3;c++)
            {
                for(d=1;d<=3;d++)
                {
                    for(e=1;e<=3;e++)
                    {
                        for(f=1;f<=3;f++)
                        {
                            for(g=1;g<=3;g++)
                            {
                                for(h=1;h<=3;h++)
                                {
                                    for(i=1;i<=3;i++)
                                    {
                                        for(j=1;j<=3;j++)
                                        {
                                            if((a+b+c+d+e+f+g+h+i+j)==n)
                                            {
                                                x[t][0]=a;
                                                x[t][1]=b;
                                                x[t][2]=c;
                                                x[t][3]=d;
                                                x[t][4]=e;
                                                x[t][5]=f;
                                                x[t][6]=g;
                                                x[t][7]=h;
                                                x[t][8]=i;
                                                x[t][9]=j;
                                                t++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<t<<endl;
    for(i=0;i<t;i++)
    {
        for(j=0;j<9;j++)
        {
            cout<<x[i][j]<<" ";
        }
        cout<<x[i][j]<<endl;
    }
    return 0;
}
