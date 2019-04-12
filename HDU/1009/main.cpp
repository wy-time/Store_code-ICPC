#include <iostream>
#include <algorithm>
#include<iomanip>
using namespace std;
typedef struct
{
    int j;
    int f;
    double avg;
}st;
st room[10005];
bool cmp(st a,st b)
{
    return a.avg>b.avg;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int n=0,m=0;
    while(cin>>m>>n)
    {
        if(n==-1&&m==-1)
            break;
        int i;
        for(i=0;i<n;i++)
        {
            cin>>room[i].j>>room[i].f;
            room[i].avg=(double)room[i].j/room[i].f;
        }
        sort(room,room+n,cmp);
        double res=0;
        for(i=0;i<n;i++)
        {
            if(room[i].f<m)
            {
                res+=room[i].j;
                m-=room[i].f;
            }else
            {
                res+=(double)m/room[i].f*room[i].j;
                break;
            }
        }
        cout<<fixed<<setprecision(3)<<res<<endl;;
    }
    return 0;
}
/*#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
struct z
{
	double j;
	int f;
	double t ;
};
bool cmp(z a, z b)
{
	return a.t > b.t;
}
int main()
{
	int m, n;
	double s;
	while (cin >> m >> n)
	{
		s = 0;
		if (m == -1 && n == -1)
		{
			break;
		}
		z *a = new z[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].j >> a[i].f;
			a[i].t = a[i].j / a[i].f;
		}
		sort(a, a + n, cmp);
		for (int i = 0; i < n; i++)
		{
			if (m>a[i].f)
			{
				m -= a[i].f;
				s += a[i].j;
			}
			else{
				s += (double)m / a[i].f*a[i].j;
				break;
			}
		}
		cout.setf(ios::fixed);
		cout << setprecision(3) << s << endl;
	}
	return 0;
}*/
