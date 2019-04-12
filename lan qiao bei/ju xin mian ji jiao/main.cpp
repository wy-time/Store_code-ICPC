#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    //std::ios::sync_with_stdio(false);
    double x[4],y[4];
    int i;
    for(i=0;i<4;i++)
    {
       scanf("%lf %lf",&x[i],&y[i]);
    }
    if(max(x[0],x[1])<min(x[2],x[3])||min(x[0],x[1])>max(x[2],x[3])||min(y[0],y[1])>max(y[2],y[3])||max(y[0],y[1])<min(y[2],y[3]))
        printf("0.00");
    else
    {
        sort(x,x+4);
        sort(y,y+4);
        printf("%.2f",(x[2]-x[1])*(y[2]-y[1]));
    }
    return 0;
}
