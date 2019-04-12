#include<iostream>
#include<set>
using namespace std;
int main ()
{
	int n;
	while(cin>>n)
	{
		set<int> st;
		int i;
		for(i=0;i<n;i++)
		{
			int temp=0;
			cin>>temp;
			st.insert(temp);
		}
		set<int>::iterator it;
		for(it=st.begin();it!=st.end();it++)
		{
			cout<<*it<<endl;
		}
	}
	return 0;	
}
