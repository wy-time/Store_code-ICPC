#include <iostream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    while(cin>>n)
    {
        bool palyer[3]= {true,true,false};
        bool right=true;
        while(n--)
        {
            int t;
            cin>>t;
            if(right)
            {
                if(palyer[t-1])
                {
                    switch (t-1)
                    {
                    case 0:
                        palyer[1]=!palyer[1];
                        palyer[2]=!palyer[2];
                        break;
                    case 1:
                        palyer[2]=!palyer[2];
                        palyer[0]=!palyer[0];
                        break;
                    case 2:
                        palyer[1]=!palyer[1];
                        palyer[0]=!palyer[0];
                        break;
                    }
                }
                else
                {
                    right=false;
                }
            }
        }
        if(right)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
