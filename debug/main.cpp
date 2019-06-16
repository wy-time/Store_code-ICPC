#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(int &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
int ma1[55][55];
int ma2[55][55];
int main()
{
    std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("F:\\Desktop\\question\\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
    freopen("/home/time/debug/debug/in","r",stdin);
    freopen("/home/time/debug/debug/out","w",stdout);
    #endif
    int n,m;
    cin>>n>>m;
    int i,j;
    wfor(i,0,n)
    {
        wfor(j,0,m)
        {
            cin>>ma1[i][j];
        }
    }
    wfor(i,0,n)
    {
        wfor(j,0,m)
        {
            cin>>ma2[i][j];
        }
    }
    int flag=1;
    wfor(i,0,n)
    {
        wfor(j,0,m)
        {
            if(i>0&&j>0)
            {
                if((ma1[i][j]>ma1[i-1][j]&&ma1[i][j]>ma1[i][j-1])||(ma2[i][j]>ma1[i-1][j]&&ma2[i][j]>ma1[i][j-1]))
                {
                    if(ma1[i][j]>ma2[i][j]&&ma2[i][j]>ma1[i-1][j]&&ma2[i][j]>ma1[i][j-1])
                        swap(ma1[i][j],ma2[i][j]);
                }else
                {
                    flag=0;
                    break;
                }
            }else if(i>0)
            {
                if(ma1[i][j]>ma1[i-1][j]||ma2[i][j]>ma1[i-1][j])
                {
                    if(ma1[i][j]>ma2[i][j]&&ma2[i][j]>ma1[i-1][j])
                        swap(ma1[i][j],ma2[i][j]);
                }else
                {
                    flag=0;
                    break;
                }
            }else if(j>0)
            {
                if(ma1[i][j]>ma1[i][j-1]||ma2[i][j]>ma1[i][j-1])
                {
                    if(ma1[i][j]>ma2[i][j]&&ma2[i][j]>ma1[i][j-1])
                        swap(ma1[i][j],ma2[i][j]);
                }else
                {
                    flag=0;
                    break;
                }
            }else
            {
                if(ma1[i][j]>ma2[i][j])
                    swap(ma1[i][j],ma2[i][j]);
            }
        }
        if(flag==0)
            break;
    }
    if(flag==1)
    {
        wfor(i,0,n)
        {
            wfor(j,0,m)
            {
                if(i>0)
                {
                    if(ma2[i][j]<ma2[i-1][j])
                    {
                        if(ma1[i][j]>ma2[i-1][j])
                            swap(ma1[i][j],ma2[i][j]);
                        else
                        {
                            flag=0;
                            break;
                        }
                    }
                }
                if(j>0)
                {
                    if(ma2[i][j]<ma2[i][j-1])
                    {
                        if(ma1[i][j]>ma2[i][j-1])
                            swap(ma1[i][j],ma2[i][j]);
                        else
                        {
                            flag=0;
                            break;
                        }
                    }
                }
            }
            if(flag==0)
                break;
        }
        if(flag==1)
        {
            wfor(i,0,n)
            {
                wfor(j,0,m)
                {
                    if(i>0)
                    {
                        if(ma1[i][j]<ma1[i-1][j])
                        {
                            flag=0;
                            break;
                        }
                    }
                    if(j>0)
                        if(ma1[i][j]<ma1[i][j-1])
                        {
                            flag=0;
                            break;
                        }
                }
                if(flag==0)
                    break;
            }
        }
    }
    if(flag==0)
        cout<<"Impossible"<<endl;
    else
        cout<<"Possible"<<endl;
    return 0;
}
