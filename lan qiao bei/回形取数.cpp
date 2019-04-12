#include<iostream>
using namespace std;
int main ()
{
	int n,m;
	int a[205][205];
	bool b[205][205];
	cin>>n>>m;
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>a[i][j];
			b[i][j]=true;
		}
	}
	int dx[4]={1,0,-1,0};
	int dy[4]={0,1,0,-1};
	int x=0,y=0;
	cout<<a[x][y];
	b[x][y]=false;
	i=0;
	int cnt=1;
	while(cnt<n*m)
	{
		int x1=x+dx[i];
		int y1=y+dy[i];
		if(x1>=0&&x1<n&&y1>=0&&y1<m&&b[x1][y1])
		{
			cout<<" "<<a[x1][y1];
			x+=dx[i];
			y+=dy[i];
			b[x1][y1]=false;
			cnt++;
		}else
		{
			i++;
			i%=4;
		}
	}
	return 0;
}
