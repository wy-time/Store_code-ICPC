#include <iostream>
using namespace std;
int main()
{
    int n ,na,nb;
    cin>>n>>na>>nb;
    int a[205];
    int b[205];
    int i;
    int ra=0,rb=0;
    for(i=0;i<na;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<nb;i++)
    {
        cin>>b[i];
    }
    for(i=0;i<n;i++)
    {
        if(a[i%na]==0)
        {
            if(b[i%nb]==1||b[i%nb]==4)
            {
                rb++;
            }
            else if(b[i%nb]==2||b[i%nb]==3)
            {
                ra++;
            }

        }else if(a[i%na]==1)
        {
            if(b[i%nb]==2||b[i%nb]==4)
            {
                rb++;
            }
            else if(b[i%nb]==0||b[i%nb]==3)
            {
                ra++;
            }

        }else if(a[i%na]==2)
        {
            if(b[i%nb]==0||b[i%nb]==3)
            {
                rb++;
            }
            else if(b[i%nb]==1||b[i%nb]==4)
            {
                ra++;
            }
        }
        else if(a[i%na]==3)
        {
            if(b[i%nb]==0||b[i%nb]==1)
            {
                rb++;
            }
            else if(b[i%nb]!=3)
            {
                ra++;
            }
        }else
        {
            if(b[i%nb]==2||b[i%nb]==3)
            {
                rb++;
            }
            else if (b[i%nb]!=4)
            {
                ra++;
            }
        }
    }
    cout<<ra<<" "<<rb;
    return 0;
}

