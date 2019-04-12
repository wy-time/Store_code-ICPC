#include <iostream>
#include<string>
using namespace std;
typedef struct
{
    int a;
    int b;
    string c;
} z;
int main()
{
    z info;
    string s,s1;
    cin>>s;
    int q;
    cin>>q;
    while(q--)
    {
        int cnt=0;
        cin>>info.a>>info.b>>info.c;
        while(info.a<=info.b)
        {
            s1=s.substr(info.a,info.b-info.a+1);
            if(s1.find(info.c)!=-1)
            {
                int t=info.a;
                cnt++;
                info.a=s1.find(info.c);
                info.a+=1+t;
            }else
            {
                break;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
