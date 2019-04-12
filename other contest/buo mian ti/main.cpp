#include <iostream>
#include<string.h>
#include<cstdio>
using namespace std;
int main()
{
    int n;
    char s[20];
    int t=-1;
    char c[5][20]= {"Tetrahedron","Cube","Octahedron","Dodecahedron","Icosahedron"};
    long long sum=0;
    cin>>n;
    getchar();
    while(n--)
    {
        cin>>s;
        for(int i=0; i<5; i++)
        {
            if(strcmp(s,c[i])==0)
            {
                t=i;
                break;
            }
        }
        switch (t)
        {
            case 0:
                sum+=4;
                break;
            case 1:
                sum+=6;
                break;
            case 2:
                sum+=8;
                break;
            case 3:
                sum+=12;
                break;
            case 4:
                sum+=20;
                break;
        }
        t=-1;
    }
    cout<<sum<<endl;
    return 0;
}
